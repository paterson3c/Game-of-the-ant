/**
 * @brief Implements the xp interface
 *
 * @file xp.c
 * @author Javier Agüero 
 * @date 27-02-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xp.h"

struct _XP
{
    int xp;
    int level;
    int maxLevel;
    int max_XP;
    int lvl;
};

XP *xp_create()
{
    XP *newXP = NULL;

    newXP = (XP *)malloc(sizeof(XP));
    if (newXP == NULL)
    {
        return NULL;
    }

    newXP->xp = 0;
    newXP->level = 1;
    newXP->maxLevel = 7;
    newXP->max_XP = 10;

    return newXP;
}

STATUS xp_destroy(XP *xp)
{
    if (!xp)
    {
        return ERROR;
    }

    free(xp);
    return OK;
}

STATUS xp_setXp(XP *xp, int value)
{
    if (!xp || value < 0)
    {
        return ERROR;
    }

    xp->xp = value;
    return OK;
}

STATUS xp_setLevel(XP *xp, int value)
{
    if (!xp || value < 0 || value > xp->maxLevel)
    {
        return ERROR;
    }

    xp->level = value;
    return OK;
}

int xp_getXp(XP *xp)
{
    if (!xp)
    {
        return -1;
    }

    return xp->xp;
}

STATUS xp_getMaxXp(XP *xp)
{
    if (!xp)
    {
        return ERROR;
    }

    return xp->max_XP;
}

int xp_getLevel(XP *xp)
{
    if (!xp)
    {
        return -1;
    }

    return xp->level;
}

STATUS xp_levelUp(XP *xp)
{
    if (!xp)
    {
        return ERROR;
    }

    
    xp_setLevel(xp, xp_getLevel(xp) + 1);

    if(xp->level == 5)
        xp_setMaxXp(xp, xp_getXp(xp)+10);
    
    xp_setMaxXp(xp, xp_getXp(xp)+10);
    xp_setXp(xp, 0);

    return OK;
}

STATUS xp_addXp(XP *xp, int value)
{
    if (!xp || value < 0)
    {
        return ERROR;
    }

    xp->xp += value;
    return OK;
}

STATUS xp_setMaxXp(XP *xp, int value)
{
    if (!xp || value < 0)
    {
        return ERROR;
    }

    xp->max_XP = value;
    return OK;
}

STATUS xp_print(XP *xp)
{
    if (!xp)
    {
        return ERROR;
    }

    fprintf(stdout, "--> XP (level %d): %d\n", xp->level, xp->xp);
    return OK;
}



