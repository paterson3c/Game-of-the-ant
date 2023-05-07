/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "object.h"
#include "set.h"
#include "enemy.h"

typedef struct _Space Space;

#define MAX_SPACES 200
#define FIRST_SPACE 1

/**
  * @brief It creates a new space, allocating memory and initializing its memebers
  * @author Profesores PPROG
  * 
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Space* space_create(Id id);

/**
  * @brief It destroys a space, freeing the allocated memory
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_destroy(Space* space);

/**
  * @brief It gets the id of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id space_get_id(Space* space);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_name(Space* space, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* space_get_name(Space* space);

/**
  * @brief It sets the description of a space
  * @author Rafael Romero
  * 
  * @param space a pointer to the space
  * @param name a string with the description to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_desc(Space* space, char* desc);

/**
  * @brief It gets the description of a space
  * @author Rafael Romero
  * 
  * @param space a pointer to the space
  * @return  a string with the description of the space
  */

char *space_get_desc(Space* space);
/**
  * @brief It sets the id of the space located at the north
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param id the id number of the space located at the north
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_north(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the north
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the north 
  */
Id space_get_north(Space* space);

/**
  * @brief It sets the id of the space located at the south
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the south
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_south(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the south
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the south 
  */
Id space_get_south(Space* space);

/**
  * @brief It sets the id of the space located at the east
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the east
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_east(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the east
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the east
  */
Id space_get_east(Space* space);

/**
  * @brief It sets the id of the space located at the west
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param id the id number of the space located at the west
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_set_west(Space* space, Id id);
/**
  * @brief It gets the id of the space located at the west
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return the id number of the space located at the west
  */
Id space_get_west(Space* space);

/**
  * @brief It adds an object not contained in the space
  * @author Miguel Paterson
  *
  * @param space a pointer to the space
  * @param id id of the object we want to add
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_add_object(Space* space, Id id);

/**
  * @brief It deletes an object contained in the space
  * @author Miguel Paterson
  *
  * @param space a pointer to the space
  * @param id id of the object we want to delete
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS space_delete_object(Space* space, Id id);

/**
  * @brief It gets whether the space has the object or not
  * @author Miguel Paterson
  *
  * @param space a pointer to the space
  * @param id id of the object we want to check
  * @return a boolean, specifying if the space has the object (TRUE) or not (FALSE)
  */
BOOL space_has_object(Space* space, Id id);

/**
  * @brief It gives the list of objects contained in the space
  * @author Miguel Paterson
  *
  * @param space a pointer to the space
  * @return a dinamic array with the obects's ids that are contained in the space
  */
Id *space_get_objects(Space *space);


/**
  * @brief It gives the set of objects contained in the space
  * @author Miguel Paterson
  *
  * @param space a pointer to the space
  * @return a set with the obects's ids that are contained in the space
  */
Set *space_get_set(Space *space);

/**
  * @brief It sets the description of a space
  *
  * @param space a pointer to the space
  * @param gdesd a description of the space
  * @param i number of a char of the string gdesc
  * 
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_set_gdesc(Space *space, char *gdesc, int i);


/**
  * @brief It gets the description of a space
  *
  * @param space a pointer to the space
  * @param i number of a char of the string gdesc
  * 
  * @return the space desc or NULL in case of ERROR
  */
const char * space_get_gdesc(Space *space, int i);


/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_print(Space* space);

/**
  * @brief It sets the number of lines of a space
  *
  * @param space a pointer to the space
  * @param n number of lines 
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS space_set_nlines(Space *space, int n);

/**
  * @brief It gets the number of lines of a space
  *
  * @param space a pointer to the space
  * 
  * @return the number of lines or -1 in case of ERROR
  */
int space_get_nlines(Space *space);


Enemy *space_get_enemy(Space *space);
STATUS space_set_enemy(Space *space, Enemy *enemy);

#endif
