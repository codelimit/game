#include "eng.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  bool running{true};
  std::string pressedBtn;

  if (!initAll()) {
    running = false;
  }

  uint32_t winId = initWindow(640, 480);
  if (winId == 0) {
    running = false;
  }

  while (running) {
    std::string btn = getEvent();
    if (!btn.empty()) {
      if (btn == "QUIT") {
        running = false;
      }
      std::cout << "Button pressed: " << btn << std::endl;
    }
  }

  shutDown(winId);

  return 0;
}
