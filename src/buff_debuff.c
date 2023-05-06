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

struct _BDValue
{
    float Bvalue;
    float Dvalue;
};

struct _BDType
{
    int Btype;
    int Dtype;
};


struct _BD{
    BDType *type;
    BDValue *value;
};

BD *bd_create()
{
    BD *newBD = NULL;

    newBD = (BD *)malloc(sizeof(BD));
    if (newBD == NULL)
    {
        return NULL;
    }

    newBD->type = (BDType *)malloc(sizeof(BDType));
    if (newBD->type == NULL)
    {
        free(newBD);
        return NULL;
    }

    newBD->value = (BDValue *)malloc(sizeof(BDValue));
    if (newBD->value == NULL)
    {
        free(newBD->type);
        free(newBD);
        return NULL;
    }

    newBD->type->Btype = 0;
    newBD->type->Dtype = 0;
    newBD->value->Bvalue = 0;
    newBD->value->Dvalue = 0;

    return newBD;
}

STATUS bd_destroy(BD *bd)
{
    if (!bd)
    {
        return ERROR;
    }

    free(bd->type);
    free(bd->value);
    free(bd);
    bd = NULL;
    return OK;
}

STATUS bd_setType(BD *bd, int Btype, int Dtype)
{
    if (!bd || (Btype < -1 && Btype > 3) || (Dtype < -1 || Dtype > 3))
    {
        return ERROR;
    }

    bd->type->Btype = Btype;
    bd->type->Dtype = Dtype;
    return OK;
}

STATUS bd_setValue(BD *bd, float Bvalue, float Dvalue)
{
    if (!bd || Bvalue < 0 || Dvalue < 0)
    {
        return ERROR;
    }

    bd->value->Bvalue = Bvalue;
    bd->value->Dvalue = Dvalue;
    return OK;
}

int bd_getType(BD *bd, int type) //type = 0 -> buff, type = 1 -> debuff
{
    if (!bd || (type != 0 && type != 1))
    {
        return -1;
    }

    if (type == 0)
    {
        return bd->type->Btype;
    }
    else
    {
        return bd->type->Dtype;
    }
}

float bd_getValue(BD *bd, int type) //type = 0 -> buff, type = 1 -> debuff
{
    if (!bd || (type != 0 && type != 1))
    {
        return -1;
    }

    if (type == 0)
    {
        return bd->value->Bvalue;
    }
    else
    {
        return bd->value->Dvalue;
    }
}

/* 
STATUS bd_print(BD *bd)
{
    if (!bd)
    {
        return ERROR;
    }

    printf("Buff type: %d\n", bd->type->Btype);
    printf("Buff value: %f\n", bd->value->Bvalue);
    printf("Debuff type: %d\n", bd->type->Dtype);
    printf("Debuff value: %f\n", bd->value->Dvalue);

    return OK;
}
*/


