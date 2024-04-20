#ifndef CELL_H
#define CELL_H
#include <raylib.h>

typedef enum { ROAD, WALL } TileType_t;

struct Vector2i {
    int x, y;
};

struct Cell {
    Rectangle rec;
    TileType_t TileType;
    Color BackgroundColor;
    Vector2i arrPos;
    void Draw() {
        DrawRectangleRec(rec, BackgroundColor);
    }
};

#endif // CELL_H