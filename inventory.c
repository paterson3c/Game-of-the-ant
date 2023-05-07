/**
 * @brief Implements the functions defined in inventory.h
 * @name inventory.c
 * @author Javier Agüero
 * @date 19-03-2023
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include "inventory.h"

#define MAX_OBJS 4

struct _Inventory
{
   Set *objs;
   int max_objs;
};

/*----------------------------------------------------------------------------------------------------*/
Inventory *inventory_create()
{
   Inventory *inv_new;

   inv_new = (Inventory *)malloc(sizeof(Inventory));
   if (!inv_new)
      return NULL;

   inv_new->objs = set_create(inv_new->objs);
   inv_new->max_objs = MAX_OBJS;

   return inv_new;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_destroy(Inventory *inv)
{
   /*Error control*/
   if (!inv)
      return ERROR;

   set_destroy(inv->objs);
   free(inv);

   return OK;
}

/*----------------------------------------------------------------------------------------------------*/
BOOL inventory_isFull(Inventory *inv)
{
   int n_ids;

   /*Error control*/
   if (!inv)
      return FALSE;

   if (set_get_numberofIds(inv->objs) == NO_ID)
      return FALSE;
   else
      n_ids = set_get_numberofIds(inv->objs);

   if (inv->max_objs <= n_ids)
      return TRUE;

   return FALSE;
}

/*----------------------------------------------------------------------------------------------------*/
BOOL inventory_isEmpty(Inventory *inv)
{
   /*Error control*/
   if (!inv)
      return FALSE;

   if (set_get_numberofIds(inv->objs) == 0)
      return TRUE;

   return FALSE;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_add(Inventory *inv, Id id)
{
   /*Error control*/
   if (!inv || id == NO_ID)
      return ERROR;

   if (inventory_isFull(inv) == TRUE)
      return ERROR;

   if (set_add(inv->objs, id) == ERROR)
      return ERROR;

   return OK;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_del(Inventory *inv, Id id)
{
   /*Error control*/
   if (!inv || id == NO_ID)
      return ERROR;

   if (inventory_isEmpty(inv) == TRUE)
      return ERROR;

   if (set_del(inv->objs, id) == ERROR)
      return ERROR;

   return OK;
}

/*----------------------------------------------------------------------------------------------------*/
int inventory_getMaxObjects(Inventory *inv)
{
   /*Error control*/
   if (!inv)
      return NO_ID;

   return inv->max_objs;
}

/*----------------------------------------------------------------------------------------------------*/
Set *inventory_getObjs(Inventory *inv)
{
   /*Error control*/
   if (!inv)
      return NULL;

   return inv->objs;
}

/*----------------------------------------------------------------------------------------------------*/
Id *inventory_getIds(Inventory *inv)
{
   Id *ids;

   /*Error control*/
   if (!inv)
      return NULL;

   ids = set_get_ids(inv->objs);

   return ids;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_setMaxObjs(Inventory *inv, int value)
{
   /*Error control*/
   if (!inv || value == NO_ID)
      return ERROR;

   inv->max_objs = value;

   return OK;
}

/*----------------------------------------------------------------------------------------------------*/
BOOL inventory_contains(Inventory *inv, Id id)
{
   /*Error control*/
   if (!inv || id == NO_ID)
      return FALSE;

   if (set_contains(inv->objs, id) == TRUE)
      return TRUE;

   return FALSE;
}
/*----------------------------------------------------------------------------------------------------*/
STATUS inventory_setCapacity(Inventory *inv, int capacity)
{
   if (!inv || capacity < 0)
      return ERROR;

   inv->max_objs = capacity;

   return OK;
}
/*----------------------------------------------------------------------------------------------------*/
int inventory_print(FILE *pf, Inventory *inv)
{
   int n = 0;

   if (!inv || !pf)
      return n;

   n += fprintf(pf, "Almacenamiento: %d", inv->max_objs);

   if (set_print(pf, inv->objs) == 0)
      return n;

   return n;
}

/*----------------------------------------------------------------------------------------------------*/

Set *inventory_getSet(Inventory *inv)
{
   if (!inv)
      return NULL;
   return inv->objs;
}