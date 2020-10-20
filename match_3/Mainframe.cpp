#include "Mainframe.h"


namespace M3 
{
	Jewel _jewels[10][10];

	Mainframe::Mainframe()
	{
		_win_width = 800;
		_win_height = 480;
		_pause = false;
		_mainBool = true;
		screen_ID screenId;
	
	}
	Mainframe::~Mainframe() 
	{
		CloseAudioDevice();
		CloseWindow();
	}

	void Mainframe::init() 
	{
		screenId = screen_ID::menu;
		InitWindow(_win_width, _win_height, "Match 3");
		SetTargetFPS(FPS);
		SetExitKey(NULL);
		InitAudioDevice();
		init_jewel(_jewels);
	}
	void Mainframe::setScene(int scene) 
	{
		switch (scene) 
			{
			case 0:
				screenId = screen_ID::menu;
				break;
			case 1:
				screenId = screen_ID::game;
				break;
			}
	}
	void Mainframe::mainLoop() 
	{

		while (!WindowShouldClose() && _mainBool) 
		{
			switch (screenId) 
				{
				case screen_ID::menu:
					menuScreen();
				case screen_ID::game:
					gameScreen();
				}
		}
	}
	void Mainframe::menuScreen() 
	{

		Rectangle playButton;
		playButton.x = 20.0f;
		playButton.y = GetScreenHeight() / 2.0f;
		playButton.height = 30.0f;
		playButton.width = 65.0f;

		Rectangle creditsButton;
		creditsButton.x = 20.0f;
		creditsButton.y = (GetScreenHeight() / 2) + 100.0f;
		creditsButton.height = 30.0f;
		creditsButton.width = 113.0f;
		
		Rectangle closeButton;
		closeButton.x = 20.0f;
		closeButton.y = (GetScreenHeight() / 2) + 150.0f;
		closeButton.height = 30.0f;
		closeButton.width = 81.25f;



		while (!WindowShouldClose() && screenId == screen_ID::menu&&_mainBool)
		{
		
			BeginDrawing();
			ClearBackground(BLACK);
			

			DrawText(FormatText("Match 3"), 20, 10, 120, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), playButton))
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, RED);
			else
				DrawText(FormatText("Play"), 20, GetScreenHeight() / 2, 30, WHITE);


			if (CheckCollisionPointRec(GetMousePosition(), creditsButton))
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, RED);
			else
				DrawText(FormatText("Credits"), 20, (GetScreenHeight() / 2) + 100, 30, WHITE);

			if (CheckCollisionPointRec(GetMousePosition(), closeButton))
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, RED);
			else
				DrawText(FormatText("Close"), 20, (GetScreenHeight() / 2) + 150, 30, WHITE);


			DrawText(FormatText("v 0.1"), GetScreenWidth() - 50, 1, 20, WHITE);
			if (CheckCollisionPointRec(GetMousePosition(), creditsButton)) {
				DrawText(FormatText("Engine: Raylib 3.0"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 20, 30, WHITE);
				DrawText(FormatText("Created by:"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 100, 30, WHITE);
				DrawText(FormatText("Felix Godziela"), (GetScreenWidth() / 2 + 40), (GetScreenHeight() / 3) + 130, 30, WHITE);
			}

			EndDrawing();
			if (CheckCollisionPointRec(GetMousePosition(), closeButton) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
				exit(0);
			}
			if (CheckCollisionPointRec(GetMousePosition(), playButton) && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
				setScene(1);
			}
		}
		
	}
	void Mainframe::gameScreen() 
	{

		while (!WindowShouldClose() && screenId == screen_ID::game&&_mainBool) {
			if (!_pause) {
				input();
				update();
				draw();
			}

		}
	}


	//Match 3

	void Mainframe::input() 
	{

	}
	void Mainframe::update() 
	{
		//find matches
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				if (_jewels[i][j].kind == _jewels[i + 1][j].kind)
					if (_jewels[i][j].kind == _jewels[i - 1][j].kind)
						for (int n = -1; n <= 1; n++) _jewels[i + n][j].match++;

				if (_jewels[i][j].kind == _jewels[i][j + 1].kind)
					if (_jewels[i][j].kind == _jewels[i][j - 1].kind)
						for (int n = -1; n <= 1; n++) _jewels[i][j + n].match++;
			}
	}
	void Mainframe::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				DrawCircle(_jewels[i][j].pos_xy.x, _jewels[i][j].pos_xy.y, 10, _jewels[i][j].color);
			}
		EndDrawing();
	}

}