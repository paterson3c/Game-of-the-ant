/**
 * @brief Defines the inventory's interface
 * @name inventory.h
 * @author Javier Agüero
 * @date 19-03-2023
 * @copyright GNU Public License
*/


#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdio.h>
#include "types.h"
#include "set.h"


typedef struct _Inventory Inventory;


Inventory *inventory_create();
/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_destroy(Inventory* inv);
/*----------------------------------------------------------------------------------------------------*/
BOOL inventory_isFull(Inventory* inv);
/*----------------------------------------------------------------------------------------------------*/
BOOL inventory_isEmpty(Inventory* inv);
/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_add(Inventory* inv, Id id);
/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_del(Inventory* inv, Id id);
/*----------------------------------------------------------------------------------------------------*/
int inventory_getMaxObjects(Inventory* inv);
/*----------------------------------------------------------------------------------------------------*/
Set* inventory_getObjs(Inventory *inv);
/*----------------------------------------------------------------------------------------------------*/
Id* inventory_getIds(Inventory *inv);
/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_setMaxObjs(Inventory *inv, int value);
/*----------------------------------------------------------------------------------------------------*/
BOOL inventory_contains(Inventory *inv, Id id);
/*----------------------------------------------------------------------------------------------------*/
int inventory_print(FILE *pf, Inventory *inv);
/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_setCapacity(Inventory *inv, int capacity);
/*----------------------------------------------------------------------------------------------------*/
Set* inventory_getSet(Inventory *inv);

#endif