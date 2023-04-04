#include <raylib.h>

#include <iostream>

Vector2 Vector2Normalize(Vector2 vector)
{
    float length = sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length == 0) return { 0, 0 };
    return { vector.x / length, vector.y / length };
}

const int screenWidth = 800;
const int screenHeight = 450;

const int paddleWidth = 20;
const int paddleHeight = 80;
const int paddleSpeed = 5;

const int ballSize = 20;
const int ballSpeed = 5;

int main()
{
    InitWindow(screenWidth, screenHeight, "Pong");

    // Initialize paddles
    Rectangle player1 = { 30, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight };
    Rectangle player2 = { screenWidth - 30 - paddleWidth, screenHeight / 2 - paddleHeight / 2, paddleWidth, paddleHeight };

    // Initialize ball
    Vector2 ballPosition = { screenWidth / 2 - ballSize / 2, screenHeight / 2 - ballSize / 2 };
    float randX = (float)GetRandomValue(0, 1);
    float randY = (float)GetRandomValue(0, 1);

    Vector2 ballDirection = { randX == 0 ? -1.0f : 1.0f, randY == 0 ? -1.0f : 1.0f };
    ballDirection = Vector2Normalize(ballDirection);
    ballDirection.x *= ballSpeed;
    ballDirection.y *= ballSpeed;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update paddles
        if (IsKeyDown(KEY_W)) player1.y -= paddleSpeed;
        if (IsKeyDown(KEY_S)) player1.y += paddleSpeed;
        if (IsKeyDown(KEY_UP)) player2.y -= paddleSpeed;
        if (IsKeyDown(KEY_DOWN)) player2.y += paddleSpeed;

        // Keep paddles inside screen
        if (player1.y <= 0) player1.y = 0;
        if (player1.y + player1.height >= screenHeight) player1.y = screenHeight - player1.height;
        if (player2.y <= 0) player2.y = 0;
        if (player2.y + player2.height >= screenHeight) player2.y = screenHeight - player2.height;

        // Update ball
        ballPosition.x += ballDirection.x;
        ballPosition.y += ballDirection.y;

        // Check ball collision with walls
        if ((ballPosition.y <= 0) || (ballPosition.y + ballSize >= screenHeight))
            ballDirection.y *= -1;

        // Check ball collision with paddles
        if (CheckCollisionRecs(player1, { ballPosition.x, ballPosition.y, ballSize, ballSize }))
            ballDirection.x *= -1;
        if (CheckCollisionRecs(player2, { ballPosition.x, ballPosition.y, ballSize, ballSize }))
            ballDirection.x *= -1;

        // Check if ball goes out of bounds
        if (ballPosition.x <= 0 || ballPosition.x + ballSize >= screenWidth)
        {
            ballPosition = { screenWidth / 2 - ballSize / 2, screenHeight / 2 - ballSize / 2 };

            float randX = (float)GetRandomValue(0, 1);
            float randY = (float)GetRandomValue(0, 1);

            ballDirection = { randX == 0 ? -1.0f : 1.0f, randY == 0 ? -1.0f : 1.0f };
            ballDirection = Vector2Normalize(ballDirection);
            ballDirection.x *= ballSpeed;
            ballDirection.y *= ballSpeed;
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw paddles
        DrawRectangleRec(player1, RAYWHITE);
        DrawRectangleRec(player2, RAYWHITE);

        // Draw ball
        DrawRectangle(ballPosition.x, ballPosition.y, ballSize, ballSize, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}