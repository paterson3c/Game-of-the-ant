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



STATUS xp_setXp(XP *xp, int value);


int xp_getXp(XP *xp);


STATUS xp_setLevel(XP *xp, int value);


int xp_getLevel(XP *xp);









#endif