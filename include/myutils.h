#include <raylib.h>

void MyDrawCenteredText(Font font, int screenWidth, int screenHeight, char *text, int spacing)
{
    Vector2 len = MeasureTextEx(font, text, 2*font.baseSize, spacing);
    DrawTextEx(font, text,
               (Vector2){(screenWidth - len.x) / 2.0, (screenHeight - len.y) / 2.0},
               2*font.baseSize, spacing, BLACK); // Draw text using font and additional parameters
}