#include "src_mario/game/GameWindow.h"

int main( )
{
	GameWindow window( 1200, 900, "Super Mario Bros" );
	window.MainLoop( );

	return 0;
}