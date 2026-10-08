#include "box.h"

Box::Box(float startX, float startY, float w, float h, float speed) {
    x = startX;
    y = startY;
    width = w;
    height = h;
    speedY = speed;
}

void Box::Update(float deltaTime) {
    float gravity = 981.81f;
    speedY += gravity * deltaTime;
    y += speedY * deltaTime;

    if (y + height >= 900.0f) {
        y = 900.0f - height;
        speedY = -speedY*gravity; // Visszapattan
    }
}

void Box::Render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 

    SDL_FRect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);
}