#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <iostream>
#include <ctime>

#include "raylib.h"
#include "jewel.h"

using namespace std;

const int FPS = 60;


namespace M3 {
	class Mainframe {
	private:
		int _win_width;
		int _win_height;
		bool _pause;
		bool _mainBool;
	public:
		enum class screen_ID {
			menu,
			game
		};
		screen_ID screenId;

		Mainframe();
		~Mainframe();
		void init();
		void setScene(int scene);
		void mainLoop();
		void menuScreen();
		void gameScreen();
		
		void update();
		void draw();
		void input();
	};
}
#endif