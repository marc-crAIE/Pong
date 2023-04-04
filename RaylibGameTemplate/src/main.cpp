#include <raylib.h>

#include <iostream>

static const int s_ScreenWidth = 800;
static const int s_ScreenHeight = 450;

int main()
{
	// Initialize the window
	InitWindow(s_ScreenWidth, s_ScreenHeight, "Raylib Game Template");

	// Set the game to run at 60 fps
	SetTargetFPS(60);

	// Keep the game running until the window close button or the escape key is pressed 
	while (!WindowShouldClose())
	{
		// Update any variables here before drawing

		ClearBackground(BLACK);

		// Do all of our drawing in here
		BeginDrawing();

		DrawText("Hello World!", 50, 50, 24, BLUE);

		EndDrawing();
	}

	// Close the window
	CloseWindow();

	return 0;
}