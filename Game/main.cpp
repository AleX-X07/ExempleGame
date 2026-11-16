#include <SFML/Graphics.hpp>

#include <mainloop.h>

#include <ExempleGame.h>

int main()
{
	MainLoop::Run<ExempleGame>("MyGame");
	return 0;
}