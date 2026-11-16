#pragma once
#include <SFML/Graphics.hpp>

#include <ez/Game.h>

class ExempleGame :
	public ez::Game
{
public:
	ExempleGame(sf::RenderWindow& window);
	virtual ~ExempleGame() override;

	virtual void Init() override;
};