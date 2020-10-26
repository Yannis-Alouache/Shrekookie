#include <raylib.h>
#include "circle.h"

typedef struct Cookie {
	int x;
	int y;
	Circle hitBox;
	Texture2D texture;
	bool isAlive;
} Cookie;

Cookie cookie;


//ENNEMY
extern void initCookie();
extern void spawnNewCookie();