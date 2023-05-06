/**
 * @brief It defines the xp module
 * 
 * @author Javier Agüero and Paterson
 * @date 20-04-2023
 * @copyright GNU Public License
*/

#ifndef XP_H
#define XP_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

typedef struct _XP XP;

/**
 * @brief It creates a new xp
 * 
 * @param id the id of the xp
 * @return XP* the new xp
 */
XP *xp_create();

/**
 * @brief It destroys an xp
 * 
 * @param xp the xp to destroy
 * @return STATUS the status of the function
 */
STATUS xp_destroy(XP *xp);

/**
 * @brief It sets the xp
 * 
 * @param xp the xp to set
 * @param value the value to set
 * @return STATUS the status of the function
 */
STATUS xp_setXp(XP *xp, int value);

/**
 * @brief It gets the xp
 * 
 * @param xp the xp to get
 * @return int the xp
 */
int xp_getXp(XP *xp);

/**
 * @brief It sets the level
 * 
 * @param xp the xp to set
 * @param value the value to set
 * @return STATUS the status of the function (ERROR, OK)
*/
STATUS xp_setLevel(XP *xp, int value);

/**
 * @brief It gets the level
 * 
 * @param xp the xp to get
 * @return int the level
 */
int xp_getLevel(XP *xp);

/**
 * @brief It gets the xp
 * 
 * @param xp the xp to set
 * @return STATUS the status of the function (ERROR, OK)
*/
int xp_getXp(XP *xp);

/**
 * @brief It levels up 
 * 
 * @param xp Pointer to the structure containing the level of the player
 * @return STATUS the status of the function (ERROR, OK)
*/
STATUS xp_levelUp(XP *xp);

/**
 * @brief It adds xp to the player
 * 
 * @param xp Pointer to the structure containing the level of the player
 * @param value the value to add
 * @return STATUS the status of the function (ERROR, OK)
*/
STATUS xp_addXp(XP *xp, int value);

/**
 * @brief It sets the max xp
 * 
 * @param xp Pointer to the structure containing the level of the player
 * @param value the value to set
 * @return STATUS the status of the function (ERROR, OK)
*/
STATUS xp_setMaxXp(XP *xp, int value);

/**
 * @brief It gets the max xp
 * 
 * @param xp Pointer to the structure containing the level of the player
 * @return STATUS the status of the function (ERROR, OK)
*/
STATUS xp_getMaxXp(XP *xp);

/**
 * @brief It prints the xp
 * 
 * @param xp Pointer to the structure containing the level of the player
 * @return STATUS the status of the function (ERROR, OK)
*/
STATUS xp_print(XP *xp);









#endif