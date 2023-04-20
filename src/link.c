/** 
 * @brief It implements the link module
 * 
 * @file link.c
 * @author Miguel Paterson
 * @version 1.0 
 * @date 23-03-2023 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

/**
 * @brief Stores all the information of a link.
 */
struct _Link {
  Id id;                    /*!< Id number of the link, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the link */
  Id origin;                /*!< Id of the origin space */
  Id destination;           /*!< Id of the destination space */
  DIRECTION direction;         /*!< Direction of the link */
  Id requirement;           /*!< Id of the object or enemy required to open the link */
  BOOL open;                /*!< Open or closed */
};

/*--------------------------------------------------------------------------------------------------------*/
Link *link_create() {

  Link *newLink = NULL;

  newLink = (Link *)malloc(sizeof(Link));

  if (!newLink)
    return NULL;

  newLink->id = NO_ID;
  newLink->name[0] = '\0';
  newLink->origin = NO_ID;
  newLink->destination = NO_ID;
  newLink->direction = Unkown;
  newLink->open = FALSE;
  newLink->requirement = NO_ID;

  return newLink;
}

/*--------------------------------------------------------------------------------------------------------*/
STATUS link_destroy(Link *link) {
  if (!link)
    return ERROR;

  free(link);
  link = NULL;

  return OK;
}

/*--------------------------------------------------------------------------------------------------------*/
STATUS link_setId(Link *link, Id id) {
  if (!link || id == NO_ID)
    return ERROR;

  link->id = id;
  return OK;
}


/*--------------------------------------------------------------------------------------------------------*/
STATUS link_setName(Link *link, char *name) {
  if (!link || !name)
    return ERROR;

  if (!strcpy(link->name, name))
    return ERROR;

  return OK;
}

/*--------------------------------------------------------------------------------------------------------*/
STATUS link_setOrigin(Link *link, Id origin) {
  if (!link || origin == NO_ID)
    return ERROR;

  link->origin = origin;
  return OK;
}

/*--------------------------------------------------------------------------------------------------------*/
STATUS link_setDestination(Link *link, Id destination) {
  if (!link || destination == NO_ID)
    return ERROR;

  link->destination = destination;
  return OK;
}

/*--------------------------------------------------------------------------------------------------------*/
STATUS link_setDirection(Link *link, DIRECTION direct) {
  if (!link || direct == Unkown)
    return ERROR;

  link->direction = direct;
  return OK;
}

/*--------------------------------------------------------------------------------------------------------*/
STATUS link_setOpen(Link *link, BOOL open) {
  if (!link)
    return ERROR;

  link->open = open;
  return OK;
}

/*--------------------------------------------------------------------------------------------------------*/
STATUS link_setRequirement(Link *link, Id requirement) {
  if (!link || requirement == NO_ID)
    return ERROR;

  link->requirement = requirement;
  return OK;
}

/*--------------------------------------------------------------------------------------------------------*/
Id link_getId(Link *link) {
  if (!link)
    return NO_ID;

  return link->id;
}

/*--------------------------------------------------------------------------------------------------------*/
const char *link_getName(Link *link) {
  if (!link)
    return NULL;

  return link->name;
}

/*--------------------------------------------------------------------------------------------------------*/
Id link_getOrigin(Link *link) {
  if (!link)
    return NO_ID;

  return link->origin;
}

/*--------------------------------------------------------------------------------------------------------*/
Id link_getDestination(Link *link) {
  if (!link)
    return NO_ID;

  return link->destination;
}

/*--------------------------------------------------------------------------------------------------------*/
DIRECTION link_getDirection(Link *link) {
  if (!link)
    return Unkown;

  return link->direction;
}

/*--------------------------------------------------------------------------------------------------------*/
BOOL link_getOpen(Link *link) {
  if (!link)
    return FALSE;

  return link->open;
}

/*--------------------------------------------------------------------------------------------------------*/
Id link_getRequirement(Link *link) {
  if (!link)
    return NO_ID;

  return link->requirement;
}

/*--------------------------------------------------------------------------------------------------------*/
STATUS link_print(Link *link) {
    if (!link)
        return ERROR;
    
    if(fprintf(stdout, "--> Link (Id: %ld; Name: %s; Origin: %ld; Destination: %ld; Open: %d)" , link->id, link->name, link->origin, link->destination, link->open) < 0)
        return ERROR;

    return OK;
}

/*--------------------------------------------------------------------------------------------------------*/
