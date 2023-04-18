/**
 * @brief Implements the set module
 *
 * @file set.c
 * @author Miguel Paterson
 * @date 27-02-2023
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include "set.h"

struct _Set
{
    Id *id;   /*Dinamic array to ids*/
    int n_id; /*Number of Id*/
};

Set *set_create()
{
    Set *set_new;

    set_new = (Set *)calloc(1, sizeof(Set));
    if (!set_new)
        return NULL;

    set_new->id = NULL;
    set_new->n_id = 0;
    
    return set_new;
}

STATUS set_destroy(Set *s)
{
    if (s == NULL)
        return ERROR;

    free(s->id);
    free(s);

    return OK;
}

STATUS set_add(Set *s, Id id)
{
    if (!s || set_contains(s, id) || id == NO_ID)
        return ERROR;

    s->n_id++;
    s->id = realloc(s->id, (s->n_id) * sizeof(Id));
    s->id[s->n_id - 1] = id;

    return OK;
}

STATUS set_del(Set *s, Id id)
{
    int i;

    if (!s || s->n_id == 0)
        return ERROR;

    for (i = 0; i < s->n_id; i++)
    {
        if (s->id[i] == id)
        {
            s->id[i] = s->id[s->n_id - 1];
            s->id[s->n_id - 1] = NO_ID;
            break;
        }
    }

    s->n_id--;

    return OK;
}

BOOL set_contains(Set *s, Id id)
{
    int i;

    if (!s || id == NO_ID)
        return ERROR;

    for (i = 0; i < s->n_id; i++)
    {
        if (s->id[i] == id)
            return TRUE;
    }

    return FALSE;
}

Id *set_get_ids(Set *s)
{
    if (!s)
        return NULL;

    return s->id;
}

int set_get_numberofIds(Set *s)
{
    if (!s)
        return NO_ID;

    return s->n_id;
}

int set_print(FILE *pf, Set *s)
{
    int n = 0, i;

    if (!s || !pf)
        return n;

    n += fprintf(pf, "Numero de ids: %d", s->n_id);

    for (i = 0; i < s->n_id; i++)
    {
        n += fprintf(pf, "   Id %d: %ld", i, s->id[i]);
    }

    return n;
}