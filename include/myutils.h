#include <raylib.h>

void MyDrawCenteredText(Font font, int screenWidth, int screenHeight, char *text, int spacing)
{
    Vector2 len = MeasureTextEx(font, text, 40, spacing);
    DrawTextEx(font, text,
               (Vector2){(screenWidth - len.x) / 2.0, (screenHeight - len.y) / 2.0},
               40, spacing, BLACK); // Draw text using font and additional parameters
}