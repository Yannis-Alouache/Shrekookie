#include "defs.h"
#include "player.h"
#include "menu.h"
#include <raylib.h>
#include <stdio.h>

void initPlayer() {
	if (player.character == 1) {
		Image shrekImage = LoadImage("images/shrek.png");
		ImageResize(&shrekImage, 250, 250);

		player.texture = LoadTextureFromImage(shrekImage);
		UnloadImage(shrekImage);
	}
	if (player.character == 2) {
		Image pussImage = LoadImage("images/puss.png");
		ImageResize(&pussImage, 250, 250);

		player.texture = LoadTextureFromImage(pussImage);
		UnloadImage(pussImage);
	}
	if (player.character == 3) {
		Image gingerBreadImage = LoadImage("images/gingerbread.png");
		ImageResize(&gingerBreadImage, 250, 250);

		player.texture = LoadTextureFromImage(gingerBreadImage);
		UnloadImage(gingerBreadImage);
	}

	player.x = SCREEN_WIDTH / 2 - player.texture.width / 2;
	player.y = SCREEN_HEIGHT / 2 - player.texture.height / 2;

	player.hitBox.x = 0;
	player.hitBox.y = 0;
	player.hitBox.width = 0;
	player.hitBox.height = 0;

	player.isAlive == true;
}

void movePlayer() {
	player.speed = 10;

	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
		player.y -= player.speed;
	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
		player.x += player.speed;
	}
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
		player.x -= player.speed;
	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
		player.y += player.speed;
	}
	if (player.x < 0) {
		player.x += player.speed;
	}
	if (player.y < 0) {
		player.y += player.speed;
	}
	if (player.x + player.texture.width > SCREEN_WIDTH) {
		player.x -= player.speed;
	}
	if (player.y + player.texture.height > SCREEN_HEIGHT) {
		player.y -= player.speed;
	}
}