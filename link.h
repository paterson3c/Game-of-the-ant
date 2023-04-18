/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"


/**
 * Defines the link structure
*/
typedef struct _Link Link;

/**
 * @brief Creates a link
 * @return Pointer to structure link created
 */
Link *link_create();

/**
 * @brief Destroys a link
 * @param link Pointer to structure link to be destroyed
 * @return the status of the operation
 */
STATUS link_destroy(Link *link);

/**
 * @brief Sets the Id of a link
 * @param link Pointer to structure link
 * @param id the id of the link
 * @return the status of the operation
 */
STATUS link_setId(Link *link, Id id);

/**
 * @brief Gets the Id of a link
 * @param link Pointer to structure link
 * @return the id of the link
 */
Id link_getId(Link *link);

/**
 * @brief Sets the name of a link
 * @param link Pointer to structure link
 * @param name the name of the link
 * @return the status of the operation
 */
STATUS link_setName(Link *link, char *name);

/**
 * @brief Gets the name of a link
 * @param link Pointer to structure link
 * @return the name of the link
 */
const char *link_getName(Link *link);

/**
 * @brief Sets the origin of a link
 * @param link Pointer to structure link
 * @param origin the origin of the link
 * @return the status of the operation
 */
STATUS link_setOrigin(Link *link, Id origin);

/**
 * @brief Gets the origin of a link
 * @param link Pointer to structure link
 * @return the origin of the link
 */
Id link_getOrigin(Link *link);

/**
 * @brief Sets the destination of a link
 * @param link Pointer to structure link
 * @param destination the destination of the link
 * @return the status of the operation
 */
STATUS link_setDestination(Link *link, Id destination);

/**
 * @brief Gets the destination of a link
 * @param link Pointer to structure link
 * @return the destination of the link
 */
Id link_getDestination(Link *link);

/**
 * @brief Sets the status of a link
 * @param link Pointer to structure link
 * @param open the status of the link
 * @return the status of the operation
 */
STATUS link_setOpen(Link *link, BOOL open);

/**
 * @brief Gets wether a link is open or not
 * @param link Pointer to structure link
 * @return TRUE if the link is open, FALSE if it's closed
 */
BOOL link_getOpen(Link *link);

/**
 * @brief Prints the data of a link
 * @param link Pointer to structure link
 * @return the status of the operation
 */
STATUS link_print(Link *link);

/**
 * @brief Sets the direction of a link
 * @param link Pointer to structure link
 * @param direct the direction of the link
 * @return the status of the operation
 */
STATUS link_setDirection(Link *link, DIRECTION direct);

/**
 * @brief Gets the direction of a link
 * @param link Pointer to structure link
 * @return the direction of the link
 */
DIRECTION link_getDirection(Link *link);

/**
 * @brief Sets the requirement of a link
 * @param link Pointer to structure link
 * @param requirement the requirement of the link
 * @return the status of the operation
 */
STATUS link_setRequirement(Link *link, Id requirement);

/**
 * @brief Gets the requirement of a link
 * @param link Pointer to structure link
 * @return the requirement of the link
 */
Id link_getRequirement(Link *link);

#endif