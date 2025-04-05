#include <raylib.h>
#include <iostream>

int cpu_score = 0; // CPU score
int player_score = 0; // Player score

class Ball {
    public:
        Ball(float startX, float startY, float startSpeedX, float startSpeedY, float startRadius) {
            x = startX;
            y = startY;
            speedX = startSpeedX;
            speedY = startSpeedY;
            radius = startRadius;
        }

        void CheckCollision() {
            if (x - radius <= 0) {
                cpu_score++; // Increment CPU score
                x = GetScreenWidth() / 2; // Reset ball position to center
                y = GetScreenHeight() / 2; // Reset ball position to center
                speedX = -speedX; // Reverse direction on X axis
            }

            if (x + radius >= GetScreenWidth()) {
                player_score++; // Increment player score
                x = GetScreenWidth() / 2; // Reset ball position to center
                y = GetScreenHeight() / 2; // Reset ball position to center
                speedX = -speedX; // Reverse direction on X axis
            }

            if (y - radius <= 0 || y + radius >= GetScreenHeight()) {
                speedY = -speedY; // Reverse direction on Y axis
            }
        }

        void UpdatePosition() {
            x += speedX;
            y += speedY;
        }

        void Draw() {
            CheckCollision();
            UpdatePosition(); // Update the ball position before drawing
            DrawCircle(x, y, radius, WHITE);
        }

        float GetX() {
            return x; // Return the X position of the ball
        }

        float GetY() {
            return y; // Return the Y position of the ball
        }

        void ReverseDirection() {
            speedX = -speedX; // Reverse direction on X axis
        }

    private:
        float x, y; // Ball position
        float speedX, speedY; // Ball speed
        float radius; // Ball radius
};


class Paddle {
    public:
        Paddle(float startX, float startY, float startWidth, float startHeight, float startSpeed) {
            x = startX;
            y = startY;
            width = startWidth;
            height = startHeight;
            paddleSpeed = startSpeed;
        }

        void UpdatePosition() {
            if (IsKeyDown(KEY_W) && y > 0) {
                y -= paddleSpeed; // Move up
            }
            if (IsKeyDown(KEY_S) && y < GetScreenHeight() - height) {
                y += paddleSpeed; // Move down
            }
        }

        void Draw() {
            UpdatePosition(); // Update the paddle position before drawing
            DrawRectangleRounded(Rectangle{ x, y, width, height }, 0.8f, 0, WHITE); // Draw the paddle with rounded corners
        }

        float GetX() {
            return x; // Return the X position of the paddle
        }

        float GetY() {
            return y; // Return the Y position of the paddle
        }

    protected:
        float x, y; // Paddle position
        float width, height; // Paddle dimensions
        float paddleSpeed; // Paddle speed
};


class CPUPaddle : public Paddle {
    public:
        CPUPaddle(float startX, float startY, float startWidth, float startHeight, float startSpeed) : Paddle(startX, startY, startWidth, startHeight, startSpeed) {}

        void UpdatePosition(float ballY) {
            if (y + height / 2 < ballY && y < GetScreenHeight() - height) {
                y += paddleSpeed; // Move down
            }
            if (y + height / 2 > ballY && y > 0) {
                y -= paddleSpeed; // Move up
            }
        }
        void Draw(float ballY) {
            UpdatePosition(ballY); // Update the paddle position based on ball position before drawing
            DrawRectangleRounded(Rectangle{ x, y, width, height }, 0.8f, 0, WHITE); // Draw the paddle with rounded corners
        }
};


int main() {

    const int screenWidth = 1280;
    const int screenHeight = 800;
    const int ballSize = 20;
    const int ballSpeed = 7;
    const int paddleWidth = 20;
    const int paddleHeight = 100;
    const int paddleSpacing = 10;
    const int paddleSpeed = 6;

    Ball ball(screenWidth / 2, screenHeight / 2, ballSpeed, ballSpeed, ballSize); // Create a Ball object
    Paddle leftPaddle(paddleSpacing, (screenHeight / 2) - (paddleHeight / 2), paddleWidth, paddleHeight, paddleSpeed); // Create a Paddle object
    CPUPaddle rightPaddle(screenWidth - paddleSpacing - paddleWidth, (screenHeight / 2) - (paddleHeight / 2), paddleWidth, paddleHeight, paddleSpeed); // Create a CPUPaddle object

    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60); // Set the game to run at 60 frames per second

    while (!WindowShouldClose()) { // Detect window close button or ESC key
        BeginDrawing(); // Start drawing
        ClearBackground(BLUE); // Clear the background with white color

        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE); // Draw the center line
        ball.Draw(); // Draw the ball
        leftPaddle.Draw(); // Draw the left paddle
        rightPaddle.Draw(ball.GetY()); // Draw the right paddle with ball position

        if (CheckCollisionCircleRec(Vector2{ ball.GetX(), ball.GetY() }, ballSize, Rectangle{ leftPaddle.GetX(), leftPaddle.GetY(), paddleWidth, paddleHeight })) {
            ball.ReverseDirection(); // Reverse direction on X axis
        }

        if (CheckCollisionCircleRec(Vector2{ ball.GetX(), ball.GetY() }, ballSize, Rectangle{ rightPaddle.GetX(), rightPaddle.GetY(), paddleWidth, paddleHeight })) {
            ball.ReverseDirection(); // Reverse direction on X axis
        }

        DrawText(TextFormat("Player Score: %i", player_score), 10, 10, 20, WHITE); // Draw player score
        DrawText(TextFormat("CPU Score: %i", cpu_score), screenWidth - 200, 10, 20, WHITE); // Draw CPUs score

        EndDrawing(); // End drawing
    }

    CloseWindow(); // Close the window and OpenGL context

    return 0;
}


