#ifndef MENU_H
#define MENU_H
// #include "Level.h"
#include "raylib.h"
#include <string>

struct Menu {
    Texture2D background;
    Texture2D logo;
    Texture2D arrow;
    Font customFont;
    Sound backgroundSound;
};

void mainMenu();
void toStartMenu(Texture2D background, Texture2D logo, Font customFont, Texture2D arrowTexture, Sound backgroundSound);
void toStartMenu();
void toHowToPlay(Texture2D background, Texture2D logo, Font customFont, Texture2D arrowTexture);
void toCredits(Texture2D background, Texture2D logo, Font customFont, Texture2D arrowTexture);
void createMap(Texture2D background, Texture2D logo, Font customFont, Texture2D arrowTexture, Sound backgroundSound);
int WinScreen(Texture2D background, Font customFont, int score);
bool LoseScreen(Texture2D background, Font customFont, int score);
// Custom drawing function
struct CustomButton {
    Rectangle bounds;
    Color color;
    const char *text;
    int fontSize;
};
void DrawCustomButton(CustomButton button);
#endif
