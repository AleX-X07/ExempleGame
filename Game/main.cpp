#include <SFML/Graphics.hpp>

#include <../../EZ-Engine/mainloop.h>

#include <ExempleGame.h>

int main()
{
	auto& window = MainLoop::Instance("myGame")->m_window;
	MainLoop::Instance("myGame")->SetGame(ExempleGame(window));
	return 0;
}