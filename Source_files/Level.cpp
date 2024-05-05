#include "../Header_files/Level.h"

Level::Level(int WindowWidth, int WindowHeight ,int n) : WindowWidth(WindowWidth), WindowHeight(WindowHeight) {
    map = new Map();
    readMap(map, n);
    map->ColorMap();
    food = new Food(map);
    pacman = new Pacman(map,food);
    ghost = new Ghost(map);
    source = {0, 0}, dest = {vc - 1, hc - 1};

}

Level::~Level() {
    delete map;
    delete pacman;
    map = nullptr;
    pacman = nullptr;
}

void Level::start() {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        map->Draw();
        food->draw(map);
        pacman->draw();
        ghost->draw();
        DrawText(TextFormat("Score: %d", pacman->score), 10, map->infoBarHeight / 2 - 10, 30, WHITE);
        if (IsWindowResized()) {
            map->Update();
            pacman->setSize();
        }
        if (IsKeyPressed(KEY_C)) {
            mapMaker(map);
            writeMap(map,1);

            food->update(map);

        }
        if (IsKeyPressed(KEY_Q)) {
            EndDrawing();
            break;
        }
        if (IsKeyPressed(KEY_F))
            map->FindPath(source, dest);
        if (IsKeyPressed(KEY_UP) || pacman->direction.y < 0) {
            pacman->goUp();
            pacman->eat();
        }
        if (IsKeyPressed(KEY_DOWN) || pacman->direction.y > 0) {
            pacman->goDown();
            pacman->eat();
        }
        if (IsKeyPressed(KEY_RIGHT) || pacman->direction.x > 0) {
            pacman->goRight();
            pacman->eat();
        }
        if (IsKeyPressed(KEY_LEFT) || pacman->direction.x < 0) {
            pacman->goLeft();
            pacman->eat();
        }
        if (pacman->score==food->count*10)
        {
            EndDrawing();
            cout << "YOU WON!";
            break;
        }
        EndDrawing();
    }
    writeScore(pacman->score);
}
