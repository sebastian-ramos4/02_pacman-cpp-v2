#include "Apple.h"

Apple::Apple(int x, int y, int width, int height, ofImage spriteSheet) : Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 535,48,16,16);
}


