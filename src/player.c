/**
 * @brief Implements the functions defined in player.h
 * @name player.c
 * @author Miguel Paterson
 * @date 10-02-2022
 * @copyright GNU Public License
*/

#include "player.h"

struct _Player {
    Id id;                      /*Structure player's id*/
    char name[WORD_SIZE + 1];   /*Player's name*/
    Id location;                /*Where the player is*/
    Inventory *objects;         /*Objects weared by the player*/
    int health;                 /*player's health*/
    XP* xp;                     /*player's xp*/
    float attack;                 /*player's attack*/
    float defense;                /*player's defense*/
    BOOL position[3][3];         /*Player's position*/
    int i_pos;                  /*Player's i position*/
    int j_pos;                  /*Player's j position*/
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
    aux->health = 25;
    aux->xp = xp_create();
    aux->attack = 1;
    aux->defense = 0;
    aux->i_pos = -1;
    aux->j_pos = -1;

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

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setAttack(Player *p, int value) {
    if(!p || value<0)
        return ERROR;
    
    p->attack = value;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
int player_getAttack(Player *p) {
    if(!p)
        return -1;
    
    return p->attack;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setDefense(Player *p, int value) {
    if(!p || value<0)
        return ERROR;
    
    p->defense = value;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
int player_getDefense(Player *p) {
    if(!p)
        return -1;
    
    return p->defense;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setXP(Player *p, XP *xp) {
    if(!p || !xp)
        return ERROR;
    
    xp_setXp(p->xp, xp_getXp(xp));
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
int player_getXP(Player *p) {
    if(!p)
        return -1;
    
    return xp_getXp(p->xp);
}

/*----------------------------------------------------------------------------------------------------*/
int player_getMaxXP(Player *p) {
    if(!p)
        return -1;
    
    return xp_getMaxXp(p->xp);
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setMaxXP(Player *p, XP *xp) {
    if(!p || !xp)
        return ERROR;
    
    xp_setMaxXp(p->xp, xp_getMaxXp(xp));
    return OK;
}

STATUS player_levelUp(Player *p) {
    if(!p)
        return ERROR;
    
    xp_levelUp(p->xp);
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
Inventory *player_getInventory(Player *p) {
    if(!p)
        return NULL;
    
    return p->objects;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setPosition(Player *p, int x, int y) {
    if(!p || x<0 || x>2 || y<0 || y>2)
        return ERROR;

    if(player_resetPosition(p) == ERROR) 
        return ERROR;
    
    p->position[x][y] = TRUE;
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
BOOL player_isHere(Player *p, int x, int y) {
    if(!p)
        return FALSE;
    
    return p->position[x][y];
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_resetPosition(Player *p) {
    int i, j;
    if(!p)
        return ERROR;
    
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            p->position[i][j] = FALSE;
        }
    }
    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
int player_getPositionI(Player *p) {
    int i, j;
    if(!p)
        return -1;
    
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(p->position[i][j] == TRUE)
                return i;
        }
    }

    return -1;
}

/*----------------------------------------------------------------------------------------------------*/
int player_getPositionJ(Player *p) {
    int i, j;
    if(!p)
        return -1;
    
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(p->position[i][j] == TRUE)
                return j;
        }
    }

    return -1;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setPositionI(Player *p, int i) {
    if(!p || i<0 || i>2)
        return ERROR;
    
    if(player_setPosition(p, i, Player_getPositionJ(p)) == ERROR)
        return ERROR;

    return OK;
}

/*----------------------------------------------------------------------------------------------------*/
STATUS player_setPositionJ(Player *p, int j) {
    if(!p || j<0 || j>2)
        return ERROR;
    
    if(player_setPosition(p, player_getPositionI(p), j) == ERROR)
        return ERROR;

    return OK;
}