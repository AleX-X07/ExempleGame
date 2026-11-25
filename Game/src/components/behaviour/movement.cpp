#include "components/behaviour/movement.h"

#include <ez/GameObject.h>

Movement::Movement(ez::GameObject* owner) : Movement(owner, 1.0f) {}

Movement::Movement(ez::GameObject* owner, float speed) : Component(owner), m_speed(speed) {}

void Movement::SetInput(const sf::Keyboard::Key& Up, const sf::Keyboard::Key& Left, const sf::Keyboard::Key& Down, const sf::Keyboard::Key& Right)
{
	m_Up = Up;
	m_Left = Left;
	m_Down = Down;
	m_Right = Right;
}

void Movement::Update(float dt, systeme::Systeme& m_systeme)
{
	sf::Vector2f dir = { 0,0 };
	if (m_systeme.m_input.IsKeyHeld(m_Up))
	{
		dir.y -= 1.f;
	}
	if (m_systeme.m_input.IsKeyHeld(m_Left))
	{
		dir.x -= 1.f;
	}
	if (m_systeme.m_input.IsKeyHeld(m_Down))
	{
		dir.y += 1.f;
	}
	if (m_systeme.m_input.IsKeyHeld(m_Right))
	{
		dir.x += 1.f;
	}

	float m_step = dt * m_speed;

	sf::Vector2f normalized;

	if (dir.x != 0 || dir.y != 0)
	{
		normalized = dir.normalized();
	}

	m_owner->GetTransform() += normalized * m_step;
}
