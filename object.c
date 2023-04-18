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
    Id id;                    /*!< Id number of the object, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the object */
    char description[235]; /*!< Description of the object */
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