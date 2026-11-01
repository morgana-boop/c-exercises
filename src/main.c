#include "raylib.h"
#include <stdbool.h>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 600

#define PLAYER_SIZE 32.0f
#define PLAYER_SPEED 260.0f

#define CRYSTAL_COUNT 10

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_VICTORY
} GameState;

typedef struct {
    Vector2 position;
    float radius;
    bool collected;
} Crystal;

static void ResetGame(Rectangle *player, Crystal crystals[])
{
    player->x = SCREEN_WIDTH / 2.0f - PLAYER_SIZE / 2.0f;
    player->y = SCREEN_HEIGHT / 2.0f - PLAYER_SIZE / 2.0f;
    player->width = PLAYER_SIZE;
    player->height = PLAYER_SIZE;

    for (int i = 0; i < CRYSTAL_COUNT; i++) {
        crystals[i].radius = 10.0f;
        crystals[i].collected = false;

        do {
            crystals[i].position = (Vector2) {
                (float)GetRandomValue(40, SCREEN_WIDTH - 40),
                (float)GetRandomValue(70, SCREEN_HEIGHT - 40)
            };
        } while (
            CheckCollisionCircleRec(
                crystals[i].position,
                crystals[i].radius,
                *player
            )
        );
    }
}

int main(void)
{
    InitWindow(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        "Caca aos Cristais"
    );

    SetTargetFPS(60);

    Rectangle player;
    Crystal crystals[CRYSTAL_COUNT];

    ResetGame(&player, crystals);

    GameState state = STATE_MENU;
    int score = 0;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        if (state == STATE_MENU && IsKeyPressed(KEY_ENTER)) {
            ResetGame(&player, crystals);
            score = 0;
            state = STATE_PLAYING;
        }

        if (state == STATE_PLAYING) {
            Vector2 direction = { 0.0f, 0.0f };

            if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
                direction.x -= 9.0f;

            if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
                direction.x += 9.0f;

            if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
                direction.y -= 9.0f;

            if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
                direction.y += 9.0f;

            if (direction.x != 0.0f && direction.y != 0.0f) {
                direction.x *= 0.70710678f;
                direction.y *= 0.70710678f;
            }

            player.x += direction.x * PLAYER_SPEED * deltaTime;
            player.y += direction.y * PLAYER_SPEED * deltaTime;

            if (player.x < 0)
                player.x = 0;

            if (player.y < 0)
                player.y = 0;

            if (player.x + player.width > SCREEN_WIDTH)
                player.x = SCREEN_WIDTH - player.width;

            if (player.y + player.height > SCREEN_HEIGHT)
                player.y = SCREEN_HEIGHT - player.height;

            for (int i = 0; i < CRYSTAL_COUNT; i++) {
                if (!crystals[i].collected &&
                    CheckCollisionCircleRec(
                        crystals[i].position,
                        crystals[i].radius,
                        player
                    )) {

                    crystals[i].collected = true;
                    score++;
                }
            }

            if (score == CRYSTAL_COUNT)
                state = STATE_VICTORY;
        }

        if (state == STATE_VICTORY && IsKeyPressed(KEY_ENTER)) {
            ResetGame(&player, crystals);
            score = 0;
            state = STATE_PLAYING;
        }

        BeginDrawing();

        ClearBackground((Color){ 18, 16, 32, 255 });

        if (state == STATE_MENU) {
            const char *title = "CACA AOS CRISTAIS";
            const char *instruction = "Pressione ENTER para comecar";

            DrawText(
                title,
                SCREEN_WIDTH / 2 - MeasureText(title, 40) / 2,
                200,
                40,
                PURPLE
            );

            DrawText(
                instruction,
                SCREEN_WIDTH / 2 - MeasureText(instruction, 20) / 2,
                280,
                20,
                RAYWHITE
            );

            DrawText(
                "WASD ou setas para movimentar",
                SCREEN_WIDTH / 2 - MeasureText(
                    "WASD ou setas para movimentar", 18
                ) / 2,
                320,
                18,
                LIGHTGRAY
            );
        }

        if (state == STATE_PLAYING) {
            for (int x = 0; x < SCREEN_WIDTH; x += 40)
                DrawLine(x, 0, x, SCREEN_HEIGHT, (Color){ 35, 30, 52, 255 });

            for (int y = 0; y < SCREEN_HEIGHT; y += 40)
                DrawLine(0, y, SCREEN_WIDTH, y, (Color){ 35, 30, 52, 255 });

            for (int i = 0; i < CRYSTAL_COUNT; i++) {
                if (!crystals[i].collected) {
                    DrawCircleV(
                        crystals[i].position,
                        crystals[i].radius,
                        SKYBLUE
                    );

                    DrawCircleV(
                        crystals[i].position,
                        crystals[i].radius / 2.0f,
                        WHITE
                    );
                }
            }

            DrawRectangleRec(player, PURPLE);
            DrawRectangleLinesEx(player, 2.0f, RAYWHITE);

            DrawText(
                TextFormat("Cristais: %02d / %02d", score, CRYSTAL_COUNT),
                20, 20, 24, RAYWHITE
            );

            DrawText(
                "Mover: WASD ou SETAS | ESC: sair",
                20, SCREEN_HEIGHT - 30, 16, LIGHTGRAY
            );
        }

        if (state == STATE_VICTORY) {
            const char *message = "VOCE VENCEU!";
            const char *instruction = "ENTER para jogar novamente";

            DrawText(
                message,
                SCREEN_WIDTH / 2 - MeasureText(message, 40) / 2,
                220,
                40,
                SKYBLUE
            );

            DrawText(
                instruction,
                SCREEN_WIDTH / 2 - MeasureText(instruction, 20) / 2,
                290,
                20,
                RAYWHITE
            );
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}