/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#define MAX_OBJECTS 100
#define MAX_ENEMY 100
#define MAX_LINKS 400
#define MAX_S 235

#include "command.h"
#include "space.h"
#include "types.h"
#include "object.h"
#include "player.h"
#include "set.h"
#include "enemy.h"
#include "link.h"

typedef struct _Game {
  Player *play;                 /*Pointer to Player*/
  Enemy *enemy[MAX_ENEMY];      /*Pointer to Enemys*/ 
  Object *objects[MAX_OBJECTS]; /*Pointer to Objects*/
  Space *spaces[MAX_SPACES];    /*Pointer to spaces*/
  Link *links[MAX_LINKS];       /*Pointer to links*/
  char description[MAX_S];      /*String of the inspect space/object*/
  T_Command last_cmd;           /*Structure commands*/
  STATUS cmd_st;                /*Command Status*/
  int rounds;                   /*Number of rounds*/
  int attack_round;             /*Round to attack*/
  int buff_round;               /*Round to buff*/
  int nerf_round;               /*Round to nerf*/
  BOOL attack_failed;           /*True if player attack failed*/
  BOOL attack_critical;         /*True if player attack critical*/
} Game;


/**
 * @brief Initializes the game
 * @param game pointer to structure Game
 * @return OK if it could initialize the game or ERROR if it couldn't
*/
STATUS game_create(Game *game);

/**
 * @brief Updates the game with the last command given
 * @param game Pointer to structure Game
 * @param cmd Last command given
 * @return Ok if it can update the game, else it returns ERROR
*/
STATUS game_update(Game *game, T_Command cmd);

/**
 * @brief Destroy the game
 * @param game Pointer to structure Game
 * @return Ok if it cans destroy it, else it returns ERROR.
 */
STATUS game_destroy(Game *game);

/**
 * @brief It says wether the game is over or not
 * @param game Pointer to structure Game
 * @return TRUE if it is over, FALSE if it isn't
*/
BOOL game_is_over(Game *game);

/**
 * @brief Prints on screen the Game data
 * @param game Pointer to structure Game
*/
void game_print_data(Game *game);

/**
 * @brief Gets the description of the space or object
 * @param game Pointer to structure Game
 * @return It returns the description of the space or object
*/
char *game_get_description(Game *game);

/**
 * @brief Creates a new space
 * @param game Pointer to structure Game
 * @param space Pointer to structure Space
 * @return OK if it created the new space, else, returns ERROR
*/
STATUS game_add_space(Game *game, Space *space);

/**
 * @brief Creates a new object
 * @param game Pointer to structure Game
 * @param object Pointer to structure Object
 * @return OK if it created the new object, else, returns ERROR
*/
STATUS game_add_object(Game *game, Object *object);

/**
 * @brief Creates a new link
 * @param game Pointer to structure Game
 * @param link Pointer to structure Link
 * @return OK if it created the new link, else, returns ERROR
*/
STATUS game_add_link(Game *game, Link *link);

/**
 * @brief Creates a new player
 * @param game Pointer to structure Game
 * @param player Pointer to structure Player
 * @return OK if it created the new player, else, returns ERROR
 */
STATUS game_add_player(Game *game, Player *player);

/**
 * @brief Creates a new enemy
 * @param game Pointer to structure Game
 * @param enemy Pointer to structure Enemy
 * @return OK if it created the new enemy, else, returns ERROR
 */
STATUS game_add_enemy(Game *game, Enemy *enemy);

/**
 * @brief It gets the position's id
 * @param game Pointer to structure Game
 * @param position position
 * @return Position's id
*/
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief It gets a space from it's id
 * @param game Pointer to structure Game
 * @param id Space's ID
 * @return It returns the space related with the id, else it returns NULL
*/
Space *game_get_space(Game *game, Id id);

/**
 * @brief It gets a link from it's id
 * @param game Pointer to structure Game
 * @param id Link's ID
 * @return It returns the link related with the id, else it returns NULL
*/
Link *game_get_link(Game *game, Id id);

/**
 * @brief It gets an object from it's id
 * @param game Pointer to structure Game
 * @param id Object's ID
 * @return It returns the object related with the id, else it returns NULL
 */
Object *game_get_object(Game *game, Id id);

/**
 * @brief It gets an enemy from it's id
 * @param game Pointer to structure Game
 * @param id Enemy's ID
 * @return It returns the enemy related with the id, else it returns NULL
 */
Enemy *game_get_enemy(Game *game, Id id);

/**
 * @brief It gets the space where the player is
 * @param game Pointer to structure Game
 * @return it returns the ID of the space the player is
*/
Id game_get_player_location(Game *game);

/**
 * @brief It gets the space where the object is
 * @param game Pointer to structure Game
 * @param id Id of the object
 * @return it returns the ID of the space the object is
*/
Id game_get_object_location(Game *game, Id id);

/**
 * @brief It gets the last command from the imput
 * @param game Pointer to structure Game
 * @return it returns the last command given
*/
T_Command game_get_last_command(Game *game);
#endif
