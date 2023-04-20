#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/**
 * @brief Object
 *
 * This struct stores all the information of an object.
 */
typedef struct _Object Object;

/**
  * @brief It creates a new object, allocating memory and initializing its memebers
  * @param id the identification number for the new space
  * @return a new object, initialized
  */
Object* object_create(Id id);

/**
  * @brief It destroys an object, freeing the allocated memory
  * @param object a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object* object);

/**
  * @brief It sets the id of an object
  * @param space a pointer to the object
  * @param id New id of the object
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_id(Object *object, Id id);

/**
  * @brief It gets the id of an object
  * @param space a pointer to the object  
  * @return the id of object
  */
Id object_get_id(Object* object);

/**
  * @brief It sets the name of an object
  * @param space a pointer to the object
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_name(Object* object, char* name);

/**
  * @brief It gets the name of an object
  * @param object a pointer to the object
  * @return  a string with the name of the object
  */
const char* object_get_name(Object* object);

/**
  * @brief It sets the name of an object
  * @param space a pointer to the object
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_desc(Object* object, char* name);

/**
  * @brief It gets the name of an object
  * @param object a pointer to the object
  * @return  a string with the name of the object
  */
const char* object_get_desc(Object* object);

/**
  * @brief It prints the object information
  * @param object a pointer to the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(Object* object);

/**
 * @brief It gets the consumable status of an object
 * 
 * 
 * @param object a pointer to the object
 * @return TRUE if the object is consumable, FALSE if it is not
 */
BOOL object_getIfConsumable(Object* object);

/**
 * @brief It sets the consumable status of an object
 * 
 * 
 * @param object a pointer to the object
 * @param consumable TRUE if the object is consumable, FALSE if it is not
 * @return OK if everything goes well, ERROR if there was some mistake
*/
STATUS object_setIfConsumable(Object* object, BOOL consumable);

#endif
