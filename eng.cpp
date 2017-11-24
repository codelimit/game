#include "SDL2/SDL.h"
#include <iostream>

bool initAll() {
  SDL_version compiled;
  SDL_version linked;

  SDL_VERSION(&compiled);
  SDL_GetVersion(&linked);

  if (SDL_COMPILEDVERSION !=
      SDL_VERSIONNUM(linked.major, linked.minor, linked.patch)) {
    std::cerr << "SDL2 compiled and linked versions mismatch: "
              << SDL_GetError() << std::endl;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
    return false;
  }
  return true;
}

Uint32 drawWindow(int height, int width) {

  SDL_Window *window;
  Uint32 id;
  window = SDL_CreateWindow("An SDL2 window", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, height, width,
                            SDL_WINDOW_OPENGL);
  if (window == nullptr) {
    std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
    return 0;
  }
  id = SDL_GetWindowID(window);
  return id;
}

std::string scanKeyboard() {

  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.key.type == SDL_KEYDOWN) {
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE:
        return "QUIT";
        break;
      case SDLK_RETURN:
        return "START";
        break;
      case SDLK_BACKSPACE:
        return "SELECT";
        break;
      case SDLK_UP:
        return "UP";
        break;
      case SDLK_DOWN:
        return "DOWN";
        break;
      case SDLK_LEFT:
        return "LEFT";
        break;
      case SDLK_RIGHT:
        return "RIGHT";
        break;
      case SDLK_SPACE:
        return "FIRE1";
        break;
      case SDLK_LCTRL:
        return "FIRE2";
        break;
      }
    }
  }
  return "";
}

void shutDown(Uint32 id) {
  std::cout << "System is shutting down" << std::endl;
  SDL_Delay(2000);
  SDL_Window *window = SDL_GetWindowFromID(id);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
