#include "ExempleGame.h"

#include <iostream>

#include <IMGUI/imgui.h>
#include <IMGUI/imgui-SFML.h>

#include <ez/components/graphics/renderer.h>
#include <ez/components/graphics/camera.h>

#include <ez/components/physics/boxcollider.h>

#include <components/behaviour/movement.h>

#include <maths/maths.h>

ExempleGame::ExempleGame(sf::RenderWindow& window) : Game(window)
{
}

ExempleGame::~ExempleGame()
{
	Game::~Game();
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
		obj1->SetOrder(10);

		// Creating Components
		// Render
		auto render = obj1->AddComponent<ez::components::graphics::Renderer>();
		render->SetTexture("../Assets/Debug/red_block.png");

		// Movement
		auto movement = obj1->AddComponent<Movement>(300.f);
		movement->SetInput(sf::Keyboard::Key::Z, sf::Keyboard::Key::Q, sf::Keyboard::Key::S, sf::Keyboard::Key::D);

		// BoxCollider
		auto collider = obj1->AddComponent<ez::components::physics::BoxCollider>();
		collider->SetListObject(m_scene->GetListObject());
		collider->SetSize(obj1->GetSize());
		//collider->Debug();
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
		back->SetOrder(0);

		auto winSize = sf::Vector2f(GetWindow().getSize());
		maths::TVecteur2<float >mathsWinSize = { winSize.x,winSize.y };
		back->GetSize() = mathsWinSize;
		auto res = mathsWinSize / 2.f;
		back->GetTransform() = { res[0], res[1] };

		// Creating Components
		// Render
		auto render = back->AddComponent<ez::components::graphics::Renderer>();
		render->SetTexture("../Assets/Debug/map.png");
	}

	// Wall
	{
		auto* wall = m_scene->AddObject("Wall");

		wall->SetOrder(1);

		auto winSize = sf::Vector2f(GetWindow().getSize());
		maths::TVecteur2<float>mathsWinSize = { winSize.x,winSize.y };
		wall->GetSize() = { 100,100 };
		auto res = mathsWinSize / 2.f;
		wall->GetTransform() = { res[0], res[1] };

		// Creating Components
		// Render
		auto render = wall->AddComponent<ez::components::graphics::Renderer>();
		render->SetTexture("../Assets/Debug/red_block.png");

		// BoxCollider
		auto collider = wall->AddComponent<ez::components::physics::BoxCollider>();
		collider->SetListObject(m_scene->GetListObject());
		collider->SetSize(wall->GetSize());
		//collider->Debug();
		collider->isStatic = true;
	}

	//// Test math
	// //Vecteur
	maths::TVecteur<float,2> testvec = { 1,1 };
	maths::TVecteur2<float> test2 = { 4,2 };

	maths::TVecteur3<float> vec1 = { 1,2,23 };

	//maths::TVecteur3<float> test3 = { 3,-3,1 };
	//maths::TVecteur3<float> test4 = { 4,9,2 };

	// Matrix
	maths::TMatrix<float, 2,2> test = {
		{1,2},
		{2,4}
	};

	std::cout << vec1 << std::endl;

	maths::TVecteur3<float> axe = { 1,1,1 };
	auto res = vec1.Rotate(30.f, axe);

	std::cout << res << std::endl;
}

void ExempleGame::Update(float dt, systeme::Systeme& m_systeme)
{
	Game::Update(dt,m_systeme);
}

void ExempleGame::Render(sf::RenderWindow& m_window)
{
	Game::Render(m_window);
	ImGui::Begin("Ma fenetre");
	ImGui::Text("Hello ImGui !");
	ImGui::End();
}
