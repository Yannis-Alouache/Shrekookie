#include <raylib.h>

typedef struct Player {
	int x;
	int y;
	int speed;
	Rectangle hitBox;
	Texture2D texture;
	int character;
	bool isAlive;
} Player;

Player player;

//PLAYER
extern void initPlayer();
extern void movePlayer();