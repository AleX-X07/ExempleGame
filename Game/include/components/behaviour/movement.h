#pragma once

#include <ez/Component.h>

class Movement : public ez::Component
{
private:
	float m_speed;

	sf::Keyboard::Key m_Up = sf::Keyboard::Key::Unknown;
	sf::Keyboard::Key m_Left = sf::Keyboard::Key::Unknown;
	sf::Keyboard::Key m_Down = sf::Keyboard::Key::Unknown;
	sf::Keyboard::Key m_Right = sf::Keyboard::Key::Unknown;

public:
	Movement(ez::GameObject* owner);
	Movement(ez::GameObject* owner, float speed);
	virtual ~Movement() = default;

	void SetInput(const sf::Keyboard::Key& Up, const sf::Keyboard::Key& Left, const sf::Keyboard::Key& Down, const sf::Keyboard::Key& Right);

	virtual void Update(float dt, systeme::Systeme& m_systeme) override;
};