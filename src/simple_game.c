/*******************************************************************************************
*
*   raylib Game Template
*
*   <Game title>
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <raylib.h>
#include "myutils.h"
#include <stdio.h>

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;
Font font = { 0 };
Music music = { 0 };
Sound fxCoin = { 0 };

static void UpdateDrawFrame(void);          // Update and draw one frame

int main(void)
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib game template");
    InitAudioDevice();      // Initialize audio device

    // Load global data (assets that must be available in all screens, i.e. font)
    font = LoadFont("res/mecha.png");
    music = LoadMusicStream("res/ambient.ogg");
    fxCoin = LoadSound("res/coin.wav");

    SetMusicVolume(music, 1.0f);
    SetSoundVolume(fxCoin, 0.2f);
    PlayMusicStream(music);
    //--------------------------------------------------------------------------------------

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif


    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadFont(font);
    UnloadMusicStream(music);
    UnloadSound(fxCoin);
    CloseAudioDevice();     // Close audio context
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void)
{
    UpdateMusicStream(music);       // NOTE: Music keeps playing between screens
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawFPS(10, 10);
    MyDrawCenteredText(font, screenWidth, screenHeight, "Click anywhere to play sound effect", 10);
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        PlaySound(fxCoin);
    }
    EndDrawing();
}
