#include "ExempleGame.h"

#include <ez/components/graphics/renderer.h>
#include <ez/components/graphics/camera.h>

#include <ez/components/physics/boxcollider.h>

ExempleGame::ExempleGame(sf::RenderWindow& window) : Game(window)
{
}

ExempleGame::~ExempleGame()
{
}

void ExempleGame::Init()
{
	// First Scene TestZone
	AddScene("Test");

	// Creating Object
	auto* m_scene = GetScene("Test");

	// Character
	{
		auto* obj1 = m_scene->AddObject("Obj");
		obj1->GetTransform() = { 100,100 };
		obj1->GetSize() = { 100,100 };

		// Creating Components
		// Render
		auto render = obj1->AddComponent<ez::components::graphics::Renderer>();
		render->SetTexture("../EZ-Engine/assets-debug/red_block.png");
		render->SetOrder(10);

		// Movement
		float speed = 200.0f;
		auto movement = obj1->AddComponent<Movement>(speed);

		// BoxCollider
		auto collider = obj1->AddComponent<ez::components::physics::BoxCollider>();
		collider->SetListObject(m_scene->GetListObject());
		collider->SetSize(obj1->GetSize());
		collider->Debug();
		collider->isStatic = false;
	}

	// Camera
	{
		auto* camera = m_scene->AddObject("Camera");
		auto cam = camera->AddComponent<ez::components::graphics::Camera>();

		sf::Vector2f size(GetWindow().getSize());
		auto target = m_scene->GetObject("Obj");

		cam->SetCamera(size);
		cam->SetTarget(target);
	}

	// Background
	{
		auto* back = m_scene->AddObject("Back");

		auto winSize = sf::Vector2f(GetWindow().getSize());
		back->GetSize() = winSize;
		back->GetTransform() = winSize / 2.f;

		// Creating Components
		// Render
		auto render = back->AddComponent<ez::components::graphics::Renderer>();
		render->SetTexture("../EZ-Engine/assets-debug/background.png");
		render->SetOrder(0);
	}

	// Wall
	{
		auto* wall = m_scene->AddObject("Wall");

		auto winSize = sf::Vector2f(GetWindow().getSize());
		wall->GetSize() = { 100,100 };
		wall->GetTransform() = winSize / 2.f;

		// Creating Components
		// Render
		auto render = wall->AddComponent<ez::components::graphics::Renderer>();
		render->SetTexture("../EZ-Engine/assets-debug/red_block.png");
		render->SetOrder(1);

		// BoxCollider
		auto collider = wall->AddComponent<ez::components::physics::BoxCollider>();
		collider->SetListObject(m_scene->GetListObject());
		collider->SetSize(wall->GetSize());
		collider->Debug();
		collider->isStatic = true;
	}
}

