/**
 * @brief Names the ser module
 * 
 * @file set.c
 * @author Miguel Paterson
 * @date 27-02-2023
 * @copyright GNU Public License
*/

#ifndef SET_H
#define SET_H

#include <stdio.h>
#include "types.h"

/*Names the struct Set as a _Set structure*/
typedef struct _Set Set;

/**
 * @brief allocates memory for a new set structure
 * @return a Pointer to the new structure Set
*/
Set *set_create();

/**
 * @brief frees all the memory allocated for the set
 * @param s Pointer to structure Set
 * @return Ok if it freed all or ERROR
*/
STATUS set_destroy(Set *s);

/**
 * @brief adds a new id to the set
 * @param s Pointer to structure Set
 * @param id new id of the object
 * @return OK if correctly added or ERROR
*/
STATUS set_add(Set *s, Id id);

/**
 * @brief deletes an existing set's id
 * @param s Pointer to structure Set
 * @param id id we want to delete
 * @return OK if correctly deleted or ERROR
*/
STATUS set_del(Set *s, Id id);

/**
 * @brief says wether the id is contained in the set or not
 * @param s Pointer to structure Set
 * @param id id we want to check
 * @return TRUE if the id is contained or FALSE
*/
BOOL set_contains(Set *s, Id id);

/**
 * @brief it gives a dinamic array of all ids contained
 * @param s Pointer to structure Set
 * @return a dinamic array of all ids contained
*/
Id *set_get_ids(Set *s);

/**
 * @brief  gives the number of ids allocated
 * @param s Pointer to structure Set
 * @return number of id allocated
*/
int set_get_numberofIds(Set *s);

/**
 * @brief prints the structure Set
 * @param pf File were to print
 * @param s Pointer to structure Set
 * @return number of characters printed
*/
int set_print(FILE *pf, Set *s);

#endif
