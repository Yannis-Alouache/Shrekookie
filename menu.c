#include <raylib.h>
#include "defs.h"
#include "player.h"

static bool menuExit;

void menu() {
	Rectangle shrekHitBox = { SCREEN_WIDTH / 2 - 600, SCREEN_HEIGHT / 2 - 250 / 2, 250, 250 };
	Image shrekImage = LoadImage("images/shrek.png");
	ImageResize(&shrekImage, 250, 250);
	Texture2D shrekTexture = LoadTextureFromImage(shrekImage);
	UnloadImage(shrekImage);

	Rectangle pussHitBox = { SCREEN_WIDTH / 2 - 250 / 2, SCREEN_HEIGHT / 2 - 250 / 2, 250, 250 };
	Image pussImage = LoadImage("images/puss.png");
	ImageResize(&pussImage, 250, 250);
	Texture2D pussTexture = LoadTextureFromImage(pussImage);
	UnloadImage(pussImage);

	Rectangle gingerBreadHitBox = { SCREEN_WIDTH / 2 + 400, SCREEN_HEIGHT / 2 - 250 / 2, 250, 250 };
	Image gingerBreadImage = LoadImage("images/gingerbread.png");
	ImageResize(&gingerBreadImage, 250, 250);
	Texture2D gingerBreadTexture = LoadTextureFromImage(gingerBreadImage);
	UnloadImage(gingerBreadImage);

	while (1)
	{
		Vector2 mousePosition = GetMousePosition();

		BeginDrawing();

		ClearBackground(MAGENTA);

		DrawText(FormatText("SELECTIONNER VOTRE PERSONNAGE"), SCREEN_WIDTH / 2 - 480, SCREEN_HEIGHT / 10, 50, WHITE);

		DrawTexture(shrekTexture, shrekHitBox.x, shrekHitBox.y, WHITE);
		DrawRectangleLines(shrekHitBox.x, shrekHitBox.y, shrekHitBox.width, shrekHitBox.height, WHITE);

		DrawTexture(pussTexture, pussHitBox.x, pussHitBox.y, WHITE);
		DrawRectangleLines(pussHitBox.x, pussHitBox.y, pussHitBox.width, pussHitBox.height, WHITE);

		DrawTexture(gingerBreadTexture, gingerBreadHitBox.x, gingerBreadHitBox.y, WHITE);
		DrawRectangleLines(gingerBreadHitBox.x, gingerBreadHitBox.y, gingerBreadHitBox.width, gingerBreadHitBox.height, WHITE);

		EndDrawing();
		if (CheckCollisionPointRec(mousePosition, shrekHitBox)) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				player.character = 1;
				menuExit = true;
				break;
			}
		}
		if (CheckCollisionPointRec(mousePosition, pussHitBox)) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				player.character = 2;
				menuExit = true;
				break;
			}
		}
		if (CheckCollisionPointRec(mousePosition, gingerBreadHitBox)) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				player.character = 3;
				menuExit = true;
				break;
			}
		}
	}
}

bool menuDone() {
	return menuExit;
}