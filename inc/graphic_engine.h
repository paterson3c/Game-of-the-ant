/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

/* It has all the graphics used for the display on screen*/
typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief Initializes the Grapic Engine and the display on screen
 * @return It returns a pointer to the graphic engine, if there's an error it returns NULL
*/
Graphic_engine *graphic_engine_create();

/**
 * @brief It ends the graphic engine and delete it
 * @param pe Pointer to structure graphic engine
*/
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It updates the display of the game on screen
 * @param game Pointer to structure Game
 * @param pe Pointer to structure graphic engine
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
