#include "fakeCookie.h"
#include "defs.h"
#include "player.h"
#include "cookie.h"

#include <raylib.h>

void initSprout() {
	Image sproutImage = LoadImage("images/choux.png");
	ImageResize(&sproutImage, 100, 100);

	sprout.texture = LoadTextureFromImage(sproutImage);

	sprout.x = SCREEN_WIDTH / 2 - 500;
	sprout.y = SCREEN_HEIGHT / 2 + 400;

	sprout.isAlive = true;

	UnloadImage(sproutImage);
}

void spawnNewSprout() {
	Image sproutImage = LoadImage("images/choux.png");
	ImageResize(&sproutImage, 100, 100);

	sprout.texture = LoadTextureFromImage(sproutImage);

	sprout.x = GetRandomValue(0, SCREEN_WIDTH);
	sprout.y = GetRandomValue(0, SCREEN_HEIGHT);

	while (sprout.x < 0 || sprout.x + sprout.texture.width > SCREEN_WIDTH || CheckCollisionCircleRec(sprout.hitBox.position, sprout.hitBox.radius, player.hitBox) == true) {
		sprout.x = GetRandomValue(0, SCREEN_WIDTH);
	}
	while (sprout.y < 0 || sprout.y + sprout.texture.height > SCREEN_HEIGHT || CheckCollisionCircleRec(sprout.hitBox.position, sprout.hitBox.radius, player.hitBox) == true) {
		sprout.y = GetRandomValue(0, SCREEN_HEIGHT);
	}

	sprout.isAlive = true;

	UnloadImage(sproutImage);
}