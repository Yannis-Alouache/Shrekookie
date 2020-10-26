#include <raylib.h>
#include <stdio.h>
#include "cookie.h"
#include "player.h"
#include "defs.h"
#include "menu.h"
#include <stdlib.h>
#include "fakeCookie.h"

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SHREKOOKIE");

	ToggleFullscreen();

	SetTargetFPS(120);

	Image shrekImage = LoadImage("images/shrek.png");
	SetWindowIcon(shrekImage);

	InitAudioDevice();
	Music music = LoadMusicStream("music/Tobu_Candyland.mp3");
	music.looping = true;
	SetMusicVolume(music, (float)0.1);
	PlayMusicStream(music);

	Sound sound = LoadSound("music/Yeet.mp3");
	SetSoundVolume(sound, (float)0.1);

	initCookie();
	initSprout();

	int score = 0;
	int highestScore = 0;
	char highestScoreArray[10];

	FILE* tempFile = fopen("highestScore.txt", "r");
	fgets(highestScoreArray, 10, tempFile);
	fclose(tempFile);

	highestScore = atoi(highestScoreArray);

	BeginDrawing();
	while (!menuDone())
	{
		menu();
	}
	EndDrawing();

	initPlayer();

	while (1)
	{
		while (!WindowShouldClose()) {
			UpdateMusicStream(music);

			BeginDrawing();

			movePlayer();

			ClearBackground(MAGENTA);

			DrawTexture(player.texture, player.x, player.y, WHITE);
			player.hitBox.x = (float)player.x;
			player.hitBox.y = (float)player.y;
			player.hitBox.width = (float)player.texture.width;
			player.hitBox.height = (float)player.texture.height;
			DrawRectangleLines(player.x, player.y, player.texture.width, player.texture.height, WHITE);

			if (CheckCollisionCircleRec(cookie.hitBox.position, cookie.hitBox.radius, player.hitBox) == true) {
				/*DrawText(FormatText("LES DEUX RECTANGLES SE SONT TOUCHER"), SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 30, 30, WHITE);*/
				PlaySound(sound);
				cookie.isAlive = false;
				cookie.hitBox.position.x = 0;
				cookie.hitBox.position.y = 0;
				cookie.hitBox.radius = 0;
				spawnNewCookie();
				score++;
			}

			if (cookie.isAlive == true)
			{
				DrawTexture(cookie.texture, cookie.x, cookie.y, WHITE);
				cookie.hitBox.position.x = (float)cookie.x + cookie.texture.width / 2;
				cookie.hitBox.position.y = (float)cookie.y + cookie.texture.height / 2;
				cookie.hitBox.radius = 47;
				DrawCircleLines((int)cookie.hitBox.position.x, (int)cookie.hitBox.position.y, cookie.hitBox.radius, WHITE);
				/*DrawRectangleLines(ennemy.collideRectangle.x, ennemy.collideRectangle.y, ennemy.collideRectangle.width, ennemy.collideRectangle.height, WHITE);*/
			}

			if (CheckCollisionCircleRec(sprout.hitBox.position, sprout.hitBox.radius, player.hitBox) == true) {
				sprout.isAlive = false;
				sprout.hitBox.position.x = 0;
				sprout.hitBox.position.y = 0;
				sprout.hitBox.radius = 0;
				spawnNewSprout();
				//player.isAlive = false;
				break;
			}
			if (sprout.isAlive == true)
			{
				DrawTexture(sprout.texture, sprout.x, sprout.y, WHITE);
				sprout.hitBox.position.x = (float)sprout.x + sprout.texture.width / 2;
				sprout.hitBox.position.y = (float)sprout.y + sprout.texture.height / 2;
				sprout.hitBox.radius = 47;
				DrawCircleLines((int)sprout.hitBox.position.x, (int)sprout.hitBox.position.y, sprout.hitBox.radius, WHITE);
			}

			DrawText(FormatText("FPS %d", GetFPS()), SCREEN_WIDTH * 0.9 + 40, SCREEN_HEIGHT / 30, 25, WHITE);
			DrawText(FormatText("SCORE : %d", score), SCREEN_WIDTH / 2.2, SCREEN_HEIGHT / 30, 25, WHITE);
			DrawText(FormatText("HIGHEST SCORE : %s", highestScoreArray), SCREEN_WIDTH / 31, SCREEN_HEIGHT / 30, 25, WHITE);

			EndDrawing();
		}
		if (!player.isAlive)
		{
			BeginDrawing();

			ClearBackground(MAGENTA);
			DrawText(FormatText("VOULEZ VOUS REJOUEZ ?"), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 25, WHITE);
			if ((IsKeyDown(KEY_Y)))
			{
				break;
			}
			EndDrawing();
		}
	}

	CloseWindow();
	CloseAudioDevice();
	UnloadMusicStream(music);
	UnloadSound(sound);
	UnloadImage(shrekImage);

	if (score > highestScore) {
		FILE* file = fopen("highestScore.txt", "w");
		fprintf(file, "%d", score);
		fclose(file);
	}

	return 0;
}