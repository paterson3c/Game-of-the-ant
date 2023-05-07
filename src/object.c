#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/**
 * @brief Space
 *
 * This struct stores all the information of an object.
 */
struct _Object
{
    Id id;                      /*!< Id number of the object, it must be unique */
    char name[WORD_SIZE + 1];   /*!< Name of the object */
    char description[235];      /*!< Description of the object */
    BOOL consumable;            /*!< If the object is consumable or not */
    int type;                   /*!< Type of the object (1 = common, 2 = rare, 3 = epic, 4 = legendary) */
    BD *buff;                   /*!< Buffs of the object */
    BD *debuff;                 /*!< Debuffs of the object */
    int position[3][3];         /*!< Position of the object */
};

/**
  * @brief It creates a new object, allocating memory and initializing its memebers
  * @param id the identification number for the new space
  * @return a new object, initialized
  */
Object *object_create(Id id)
{
    Object *newObject = NULL;

    /* Error control */
    if (id == NO_ID)
        return NULL;

    newObject = (Object *)malloc(sizeof(Object));
    if (newObject == NULL)
    {
        return NULL;
    }

    /* Initialization of an new object*/
    newObject->id = id;
    newObject->name[0] = '\0';
    newObject->consumable = FALSE;
    newObject->type = 0;
    newObject->buff = NULL;
    newObject->debuff = NULL;

    return newObject;
}

/**
  * @brief It destroys an object, freeing the allocated memory
  * @param object a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object *object)
{
    if (!object)
    {
        return ERROR;
    }

    free(object);
    object = NULL;
    return OK;
}

/**
  * @brief It sets the id of an object
  * @param space a pointer to the object
  * @param id New id of the object
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_id(Object *object, Id id)
{
    if (!object)
        return ERROR;

    object->id = id;
    return OK;
}

/**
  * @brief It gets the id of an object
  * @param space a pointer to the object  
  * @return the id of object
  */
Id object_get_id(Object *object)
{
    if (!object)
    {
        return NO_ID;
    }
    return object->id;
}

/**
  * @brief It sets the name of an object
  * @param space a pointer to the object
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_name(Object *object, char *name)
{
    if (!object || !name)
    {
        return ERROR;
    }

    if (!strcpy(object->name, name))
    {
        return ERROR;
    }
    return OK;
}

/**
  * @brief It gets the name of an object
  * @param object a pointer to the object
  * @return  a string with the name of the object
  */
const char *object_get_name(Object *object)
{
    if (!object)
    {
        return NULL;
    }
    return object->name;
}

/**
  * @brief It sets the description of an object
  * @param space a pointer to the object
  * @param name a string with the description to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_desc(Object *object, char *desc)
{
    if (!object || !desc)
    {
        return ERROR;
    }

    if (!strcpy(object->description, desc))
    {
        return ERROR;
    }
    return OK;
}

/**
  * @brief It gets the name of an object
  * @param object a pointer to the object
  * @return  a string with the description of the object
  */
const char *object_get_desc(Object *object)
{
    if (!object)
    {
        return NULL;
    }
    return object->description;
}

/**
  * @brief It prints the object information
  * @param object a pointer to the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(Object *object)
{
    /* Error Control */
    if (!object)
    {
        return ERROR;
    }

    /* Print the id and the name of the object */
    fprintf(stdout, "--> Object (Id: %ld; Name: %s\n", object->id, object->name);

    return OK;
}

/**
 * @brief It gets the consumable attribute of an object
 * @param object a pointer to the object
 * 
 * 
 * @return TRUE if the object is consumable, FALSE if it is not
*/
BOOL object_getIfConsumable(Object *object)
{
    if (!object)
    {
        return FALSE;
    }
    return object->consumable;
}

/**
 * @brief It sets the consumable attribute of an object
 * 
 * @param object a pointer to the object
 * @param consumable a boolean that indicates if the object is consumable or not
 * 
 * @return OK if everything goes well, ERROR if there was some mistake
*/
STATUS object_setIfConsumable(Object *object, BOOL consumable)
{
    if (!object)
    {
        return ERROR;
    }
    object->consumable = consumable;
    return OK;
}

/**
 * @brief It gets the type attribute of an object
 * @param object a pointer to the object
 * 
 * 
 * @return the type of the object (1 = common, 2 = rare, 3 = epic, 4 = legendary)
*/
int object_getType(Object *object)
{
    if (!object)
    {
        return -1;
    }
    return object->type;
}

BDTYPE object_getBuffType(Object *object)
{
    if (!object)
    {
        return Unkown;
    }
    return bd_getType(object->buff);
}

BDTYPE object_getDebuffType(Object *object)
{
    if (!object)
    {
        return Unkown;
    }
    return bd_getType(object->debuff);
}

float object_getBuffValue(Object *object)
{
    if (!object)
    {
        return -1;
    }
    return bd_getValue(object->buff);
}

float object_getDebuffValue(Object *object)
{
    if (!object)
    {
        return -1;
    }
    return bd_getValue(object->debuff);
}

/**
 * @brief It sets the type attribute of an object
 * 
 * @param object a pointer to the object
 * @param type an integer that indicates the type of the object (1 = common, 2 = rare, 3 = epic, 4 = legendary)
 * 
 * @return OK if everything goes well, ERROR if there was some mistake
*/
STATUS object_setType(Object *object, BDTYPE type)
{
    if (!object)
    {
        return ERROR;
    }
    object->type = type;
    return OK;
}

/**
 * @brief It gets the buff/debuff attribute of an object
 * @param object a pointer to the object
 * 
 * 
 * @return a pointer to the buff/debuff attribute of the object
*/
BD *object_getBuff(Object *object)
{
    if (!object)
    {
        return Unkown;
    }
    return object->buff;
}

BD *object_getDebuff(Object *object)
{
    if (!object)
    {
        return Unkown;
    }

    return object->debuff;
}

/**
 * @brief It sets the buff/debuff attribute of an object
 * 
 * @param object a pointer to the object
 * @param bd a pointer to the buff/debuff attribute of the object
 * 
 * @return OK if everything goes well, ERROR if there was some mistake
*/
STATUS object_setBuff(Object *object, BD *buff)
{
    if (!object)
    {
        return ERROR;
    }
    object->buff = buff;
    return OK;
}

STATUS object_setDebuff(Object *object, BD *debuff)
{
    if (!object)
    {
        return ERROR;
    }
    object->debuff = debuff;
    return OK;
}

STATUS object_setBuffValue(Object *object, float value) 
{
    if (!object)
    {
        return ERROR;
    }
    
    if(!bd_setValue(object->buff, value))
    {
        return ERROR;
    }

    return OK;
}

STATUS object_setDebuffValue(Object *object, float value) 
{
    if (!object)
    {
        return ERROR;
    }
    
    if(!bd_setValue(object->debuff, value))
    {
        return ERROR;
    }

    return OK;
}

STATUS object_setBuffType(Object *object, BDTYPE type) 
{
    if (!object)
    {
        return ERROR;
    }
    
    if(!bd_setType(object->buff, type))
    {
        return ERROR;
    }

    return OK;
}

STATUS object_setDebuffType(Object *object, BDTYPE type) 
{
    if (!object)
    {
        return ERROR;
    }
    
    if(!bd_setType(object->debuff, type))
    {
        return ERROR;
    }

    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS object_setPosition(Object *o, int x, int y) {
    if(!o || x<0 || x>2 || y<0 || y>2)
        return ERROR;

    if(object_resetPosition(o) == ERROR) 
        return ERROR;
    
    o->position[x][y] = TRUE;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
BOOL object_isHere(Object *o, int x, int y) {
    if(!o)
        return FALSE;
    
    return o->position[x][y];
}

/*----------------------------------------------------------------------------------------------------*/
STATUS object_resetPosition(Object *o) {
    int i, j;
    if(!o)
        return ERROR;
    
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            o->position[i][j] = FALSE;
        }
    }
    return OK;
}

