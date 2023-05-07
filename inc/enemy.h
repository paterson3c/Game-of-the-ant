/**
 * @brief It defines the enemy's interface
 * @name enemy.h
 * @author Ignacio Serena
 * @date 16-02-2022
 * @copyright GNU Public License
*/

#ifndef ENEMY_H
#define ENEMY_H

#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _Enemy Enemy;

/**
 * @brief It allocates memory for a structure Enemy, it initialize location
 * and name to 0, and object to NULL.
 * @param id Id for the new enemy.
 * @return returns a Pointer to the allocated memory Enemy if it goes without errors,
 * else, it returns NULL.
*/
Enemy *enemy_create();

/**
 * @brief It gives you the Enemy's Id.
 * @param e Pointer to structure Enemy.
 * @return returns the Enemy's id, else, it returns NO_ID.
*/
Id enemy_getId(Enemy *e);

/**
 * @brief It changes the Enemy's Id.
 * @param e Pointer to structure Enemy.
 * @param id new Id for the enemy.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS enemy_setId(Enemy *e, Id id);

/**
 * @brief It gives the Enemy's name.
 * @param e Pointer to structure Enemy.
 * @return returns the Enemy's name, else, it returns NULL.
*/
char *enemy_getName(Enemy *e);

/**
 * @brief It changes the Enemy's name.
 * @param e Pointer to structure Enemy.
 * @param name new name for the enemy.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS enemy_setName(Enemy *e, char *name);

/**
 * @brief It gives the Enemy's Location.
 * @param e Pointer to structure Enemy.
 * @return returns the Enemy's location Id, else, it returns NO_ID.
*/
Id enemy_getLocation(Enemy *e);

/**
 * @brief It changes the Enemy's location.
 * @param e Pointer to structure Enemy.
 * @param id new Location Id.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS enemy_setLocation(Enemy *e, Id id);

/**
 * @brief It gives the Enemy's health.
 * @param e Pointer to structure Enemy.
 * @return returns the Enemy's health, else, it returns -1.
*/
int enemy_getHealth(Enemy *e);

/**
 * @brief It changes the Enemy's health.
 * @param e Pointer to structure Enemy.
 * @param h new health.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS enemy_setHealth(Enemy *e, int h);

/**
 * @brief it frees the memory allocated for the Enemy's Object and the Enemy.
 * @param e Pointer to structure Enemy.
 * @return returns OK if it runned correctly, else, it returns ERROR.
*/
STATUS enemy_destroy(Enemy *e);

/**
 * @brief It sets the enemy's position.
 * @param p Pointer to structure enemy.
 * @param x New x coordinate.
 * @param y New y coordinate.
 * @return returns the status (OK/ERROR) of the action.
*/
STATUS enemy_setPosition(Enemy *p, int x, int y);

/**
 * @brief It says if the enemy is in a given position.
 * @param p Pointer to structure enemy.
 * @param x Coordinate x.
 * @param y Coordinate y.
 * @return returns TRUE if the enemy is in that position, else, it returns FALSE.
 */
BOOL enemy_isHere(Enemy *p, int x, int y);

/**
 * @brief It resets the enemy's position to the initial one.
 * @param p Pointer to structure enemy.
 * @return returns the status (OK/ERROR) of the action.
 */
STATUS enemy_resetPosition(Enemy *p);

/**
 * @brief displays on screen the Enemy's id, name and location.
 * @param pf File where the info is printed.
 * @param e Pointer to structure Enemy.
 * @return returns the number of characters printed.
*/
int enemy_print(Enemy *e);

/**
 * @brief It gives the Enemy's attack.
 * @param e Pointer to structure Enemy.
 * @return returns the Enemy's attack, else, it returns -1.
*/
float enemy_getAttack(Enemy *e);

/**
 * @brief It changes the Enemy's attack.
 * @param e Pointer to structure Enemy.
 * @param a new attack.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS enemy_setAttack(Enemy *e, float a);

/**
 * @brief It gives the Enemy's defense.
 * @param e Pointer to structure Enemy.
 * @return returns the Enemy's defense, else, it returns -1.
*/
float enemy_getDefense(Enemy *e);

/**
 * @brief It changes the Enemy's defense.
 * @param e Pointer to structure Enemy.
 * @param d new defense.
 * @return returns OK if it runned without errors, else, it returns ERROR.
*/
STATUS enemy_setDefense(Enemy *e, float d);

#endif