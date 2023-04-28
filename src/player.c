/**
 * @brief Implements the functions defined in player.h
 * @name player.c
 * @author Miguel Paterson
 * @date 10-02-2022
 * @copyright GNU Public License
*/

#include "player.h"

struct _Player {
    Id id;      /*Structure player's id*/
    char name[WORD_SIZE + 1]; /*Player's name*/
    Id location; /*Where the player is*/
    Inventory *objects; /*Objects weared by the player*/
    int health; /*player's health*/
};

/*----------------------------------------------------------------------------------------------------*/
Player *player_create(Id id) {
    Player *aux = NULL;

    if(id == NO_ID) 
        return NULL;
    
    aux = (Player*) malloc(sizeof(Player));
    if(!aux)
        return NULL;
    
    /*initialization of Player Struct*/
    aux->id = id;
    aux->name[0] = 0;
    aux->objects = NULL; 
    aux->health = 5;

    return aux;
}

/*----------------------------------------------------------------------------------------------------*/
Id player_getId(Player *p) {
    if(!p)
        return NO_ID;
    
    return p->id;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setId(Player *p, Id id) {
    if(!p || id<0)
        return ERROR;
    
    p->id = id;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
char *player_getName(Player *p) {
    if(!p)
        return NULL;
    
    return p->name;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setName(Player *p, char *name) {
    if(!p || !name)
        return ERROR;
    
    strcpy(p->name, name);
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
Id player_getLocation(Player *p) {
    if(!p) 
        return NO_ID;
    
    return p->location;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setLocation(Player *p, Id id) {
    if(!p || id<0)
        return ERROR;
    
    p->location = id;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
BOOL player_hasObject(Player *p, Id id) {
    if(!p) 
        return FALSE;
    
    return inventory_contains(p->objects, id);
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_addObject(Player *p, Id id) {
    STATUS st = OK;
    if(!p) {
        return ERROR;
    }

    st = inventory_add(p->objects, id);
    
    return st;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_deleteObject(Player *p, Id id) {
    if(!p)
        return ERROR;
    
    return inventory_del(p->objects, id);
}


/*----------------------------------------------------------------------------------------------------*/
Id *player_getObjects(Player *p) {
    Id *ids;
    if(!p) {
     return NULL;
    }

    ids = inventory_getIds(p->objects);

    return ids;
}


/*----------------------------------------------------------------------------------------------------*/
int player_getHealth(Player *p) {
    if(!p) 
        return NO_ID;
    
    return p->health;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setHealth(Player *p, int hp) {
    if(!p)
        return ERROR;
    
    p->health = hp;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_destroy(Player *p) {
    if(!p)
        return ERROR;
    
    inventory_destroy(p->objects);
    free(p);
    p = NULL;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
int player_print(FILE *pf, Player *p) {
    int n=0;

    if(!p)
        return -1;

    /*prints player's id, name and location*/
    n += printf("Player(Id: %ld, Name: %s, Location: %ld)\n", player_getId(p), player_getName(p), player_getLocation(p));
    
    /*prints the objects weared by the player*/
    n += inventory_print(pf, p->objects);

    return n;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setInventory(Player *p, Inventory *inv) { 
    if(!inv)
        return ERROR;

    if((p->objects = inv) == NULL)
        return ERROR;
    
    return OK;
}