/**
 * @brief Implements the buff_debuff module
 *
 * @file buff_debuff.c
 * @author Javier Agüero 
 * @date 27-02-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buff_debuff.h"

struct _BD{
    BDTYPE type;
    float value;  
};

BD *bd_create()
{
    BD *newBD = NULL;

    newBD = (BD *)malloc(sizeof(BD));
    if (newBD == NULL)
        return NULL;
    

    newBD->type = Unkown;
    newBD->value = 0;
    
    return newBD;
}

STATUS bd_destroy(BD *bd)
{
    if (!bd)
        return ERROR;

    free(bd);
    bd = NULL;
    return OK;
}

STATUS bd_setType(BD *bd, BDTYPE type)
{
    if (!bd || (type < 0) || (type > 3))
        return ERROR;

    bd->type = type;
    
    return OK;
}

STATUS bd_setValue(BD *bd, float BDvalue)
{
    if (!bd)
        return ERROR;
    
    bd->value = BDvalue;
    
    return OK;
}

BDTYPE bd_getType(BD *bd)
{
    if (!bd)
        return Unkown;

    return bd->type;
}

float bd_getValue(BD *bd, BDTYPE type)
{
    if (!bd)
        return 0;

    return bd->value;
}


STATUS bd_print(BD *bd)
{
    if (!bd)
    {
        return ERROR;
    }

    printf("Buff type: %d ", bd->type);
    printf("Buff value: %f\n", bd->value);

    return OK;
}



