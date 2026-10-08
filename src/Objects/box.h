#pragma once
#include <SDL3/SDL.h>

class Box {
public:

    Box(float startX, float startY, float w, float h, float speed);

    void Update(float deltaTime);
    void Render(SDL_Renderer* renderer);

private:
    float x, y;
    float width, height;
    float speedY;
};