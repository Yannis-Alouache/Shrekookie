#include "cookie.h"
#include "player.h"
#include "defs.h"
#include <raylib.h>


void initCookie() {
	Image cookieImage = LoadImage("images/cookie.png");
	ImageResize(&cookieImage, 100, 100);

	cookie.texture = LoadTextureFromImage(cookieImage);

	cookie.x = SCREEN_WIDTH / 2 + 400;
	cookie.y = SCREEN_HEIGHT / 2 + 100;
	cookie.isAlive = true;

	UnloadImage(cookieImage);
}

void spawnNewCookie() {
	Image cookieImage = LoadImage("images/cookie.png");
	ImageResize(&cookieImage, 100, 100);

	cookie.texture = LoadTextureFromImage(cookieImage);

	cookie.x = GetRandomValue(0, SCREEN_WIDTH);
	cookie.y = GetRandomValue(0, SCREEN_HEIGHT);

	while (cookie.x < 0 || cookie.x + cookie.texture.width > SCREEN_WIDTH || CheckCollisionCircleRec(cookie.hitBox.position, cookie.hitBox.radius, player.hitBox) == true) {
		cookie.x = GetRandomValue(0, SCREEN_WIDTH);
	}
	while (cookie.y < 0 || cookie.y + cookie.texture.height > SCREEN_HEIGHT || CheckCollisionCircleRec(cookie.hitBox.position, cookie.hitBox.radius, player.hitBox) == true) {
		cookie.y = GetRandomValue(0, SCREEN_HEIGHT);
	}

	cookie.isAlive = true;

	UnloadImage(cookieImage);
}