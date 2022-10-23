#pragma once

#include "raylib.h"

typedef struct {
  int width;
  int height;
	const char* title;
} Game;

/**
 * Initialize Raylib etc.
 */
void initGame();

extern Game game;


