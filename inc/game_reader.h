#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "inventory.h"

/**
 * @brief Plaze the object and the player at space 1
 * @param game Pointer to structure Game
 * @param filename Name of the file
 * @return Ok if it could create the game, else it returns ERROR.
*/
STATUS game_create_from_file(Game *game, char *filename);

/**
 * @brief Initializes spaces and sets names to the spaces
 * @param game Pointer to structure Game
 * @param filename Name of the file
 * @return OK if it could load space, else it returns ERROR
*/
STATUS game_load_spaces(Game *game, char *filename);

/**
 * @brief Initializes objects and sets names to the objects
 * @param game Pointer to structure Game
 * @param filename Name of the file
 * @return OK if it could load objects, else it returns ERROR
*/
STATUS game_load_objects(Game *game, char *filename);
/**
 * @brief Initializes spaces and sets names to the 
 * @param game Pointer to structure Game
 * @param filename Name of the file
 * @return OK if it could load player, else it returns ERROR
*/
STATUS game_load_player(Game *game, char *filename);

/**
 * @brief Initializes an enemy and sets the name to it
 * @param game Pointer to structure Game
 * @param filename Name of the file
 * @return OK if it could load enemy, else it returns ERROR
*/
STATUS game_load_enemy(Game *game, char *filename);

/**
 * @brief Initializes a link and sets the names to the links
 * @param game Pointer to structure Game
 * @param filename Name of the file
 * @return OK if it could load links, else it returns ERROR
*/
STATUS game_load_links(Game *game, char *filename);
