#include <iostream>

#ifndef ENG_H_
#define ENG_H_

#ifdef _WIN32
#ifdef BUILD_ENG
#define ENG __declspec(dllexport)
#else
#define ENG __declspec(dllimport)
#endif
#else
#define ENG
#endif

bool ENG initAll();

unsigned int ENG drawWindow(int a, int b);

std::string ENG scanKeyboard();

void ENG shutDown(unsigned int);

#endif /* ENG_H_ */
