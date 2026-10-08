#include <SDL3/SDL.h>
#include "Objects/box.h"


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Teszt Ablak", 1024, 900, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    SDL_SetRenderVSync(renderer, 1);

    bool running = true;
    SDL_Event event;

    uint64_t lastTime = SDL_GetTicksNS(); 
    Box box(600, 400, 50, 50, 200.0f); // startX, startY, width, height, speed

    while (running) {
        // 1. Események kezelése (csak ezt csinálja)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // 2. deltaTime másodpercben
        uint64_t currentTime = SDL_GetTicksNS();
        float deltaTime = (currentTime - lastTime) / 1000000000.0f;
        lastTime = currentTime;

        // 3. Frissítés
        box.Update(deltaTime);

        // 4. Rajzolás
        SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
        SDL_RenderClear(renderer);
        box.Render(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}