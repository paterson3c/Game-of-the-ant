/**
 * @brief It defines the buff_debuff
 *  interface
 * @name buuf
 * @author Javier Agüero and Paterson
 * @date 20-04-2023
 * @copyright GNU Public License
*/

#ifndef BUFF_H
#define BUFF_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MX_BUFF_DEBUFF 3


/**
 * @brief It destroys a BD, freeing the allocated memory
 * @param bd a pointer to the buff/debuff structure that must be destroyed  
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
STATUS bd_destroy(BD *bd);

/**
 * @brief It sets the type of the buff/debuff
 * @param bd a pointer to the BD
 * @param Btype the buff type
 * @param Dtype the debuff type
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS bd_setType(BD *bd, BDTYPE Btype);

/**
 * @brief It sets the value of the buff/debuff
 * @param bd a pointer to the BD
 * @param Bvalue the buff value
 * @param Dvalue the debuff value
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS bd_setValue(BD *bd, float BDvalue);

/**
 * @brief It gets the type of the buff/debuff
 * @param bd a pointer to the BD
 * @param type 0 for buff, 1 for debuff
 * @return the type of the buff/debuff
 */
BDTYPE bd_getType(BD *bd);

/**
 * @brief It gets the value of the buff/debuff
 * @param bd a pointer to the BD
 * @param type 0 for buff, 1 for debuff
 * @return the value of the buff/debuff
 */
float bd_getValue(BD *bd);

/**
 * @brief It prints the buff/debuff
 * @param bd a pointer to the BD
 * @return OK, if everything goes well or ERROR if there was some mistake 
 */
STATUS bd_print(BD *bd);

#endif