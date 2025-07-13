#include "Cherry.h"

Cherry::Cherry(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet, 487,48,16,16);
}



// #include "BigDot.h"

// BigDot::BigDot(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
//     sprite.cropFrom(spriteSheet, 643,18,16,16);
// }