#include <raylib.h>
#include "circle.h"

typedef struct FakeCookie {
	int x;
	int y;
	Circle hitBox;
	Texture2D texture;
	bool isAlive;
} FakeCookie;

FakeCookie sprout;

void initSprout();
void spawnNewSprout();