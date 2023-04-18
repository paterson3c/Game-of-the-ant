/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 3.0
 * @date 26-01-2023
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

/**
   Private functions
*/

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);
void game_command_right(Game *game);
void game_command_left(Game *game);
void game_command_take(Game *game);
void game_command_drop(Game *game);
void game_command_attack(Game *game);
void game_command_move(Game *game);
void game_command_inspect(Game *game);

Id _game_getObjectId_fromName(Game *game, char *name) {
  int i = 0;
  BOOL found = FALSE;
  Id id = NO_ID;

  while (i < MAX_OBJECTS && !found) {
    if (object_get_name(game->objects[i]) != NULL) {
      if (strcmp(object_get_name(game->objects[i]), name) == 0) {
        found = TRUE;
        id = object_get_id(game->objects[i]);
      }
    }
    i++;
  }
  return id;
}

/**
   Game interface implementation
*/

/**
 * @brief Initializes the game
 * @param game pointer to structure Game
 * @return OK if it could initialize the game or ERROR if it couldn't
 */
STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    game->objects[i] = NULL;
  }
  for (i = 0; i < MAX_LINKS; i++)
  {
    game->links[i] = NULL;
  }
  for (i = 0; i < MAX_ENEMY; i++)
  {
    game->enemy[i] = NULL;
  }

  game->play = NULL;
  game->last_cmd = NO_CMD;
  game->description[0] = '\0';

  srand(time(NULL));

  return OK;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief Destroy the game
 * @param game Pointer to structure Game
 * @return Ok if it cans destroy it, else it returns ERROR
 */
STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }
  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    object_destroy(game->objects[i]);
  }
  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++)
  {
    link_destroy(game->links[i]);
  }
  for (i = 0; i < MAX_ENEMY && game->enemy[i] != NULL; i++)
  {
    enemy_destroy(game->enemy[i]);
  }


  player_destroy(game->play);
  game = NULL;

  return OK;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief Creates a new space
 * @param game Pointer to structure Game
 * @param space Pointer to structure Space
 * @return OK if it created the new space, else, returns ERROR
 */
STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------------*/

/**
 * @brief Creates a new object
 * @param game Pointer to structure Game
 * @param object Pointer to structure Object
 * @return OK if it created the new object, else, returns ERROR
 */
STATUS game_add_object(Game *game, Object *object)
{
  int i = 0;

  if (object == NULL)
  {
    return ERROR;
  }

  while (i < MAX_OBJECTS && game->objects[i] != NULL)
    i++;

  if (i >= MAX_OBJECTS)
    return ERROR;

  game->objects[i] = object;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------------*/

/**
 * @brief Creates a new link
 * @param game Pointer to structure Game
 * @param link Pointer to structure Link
 * @return OK if it created the new link, else, returns ERROR
 */
STATUS game_add_link(Game *game, Link *link)
{
  int i = 0;

  if (link == NULL)
  {
    return ERROR;
  }

  while (i < MAX_LINKS && game->links[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_LINKS)
  {
    return ERROR;
  }

  game->links[i] = link;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------------*/

/**
 * @brief Creates a new player
 * @param game Pointer to structure Game
 * @param player Pointer to structure Player
 * @return OK if it created the new player, else, returns ERROR
 */
STATUS game_add_player(Game *game, Player *player) {
  if (player == NULL)
    return ERROR;

  game->play = player;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------------*/

/**
 * @brief Creates a new enemy
 * @param game Pointer to structure Game
 * @param enemy Pointer to structure Enemy
 * @return OK if it created the new enemy, else, returns ERROR
 */
STATUS game_add_enemy(Game *game, Enemy *enemy) {
  int i =0;

  if (enemy == NULL)
    return ERROR;

  while (i < MAX_ENEMY && game->enemy[i] != NULL) {
    i++;
  }

  if (i >= MAX_ENEMY)
    return ERROR;
  
  game->enemy[i] = enemy;

  return OK;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets the position's id
 * @param game Pointer to structure Game
 * @param position position
 * @return Position's id
 */
Id game_get_space_id_at(Game *game, int position)
{
  if (position < 0 || position >= MAX_SPACES)
    return NO_ID;

  return space_get_id(game->spaces[position]);
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets a space from it's id
 * @param game Pointer to structure Game
 * @param id Space's ID
 * @return It returns the space related with the id, else it returns NULL
 */
Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets a link from it's id
 * @param game Pointer to structure Game
 * @param id Link's ID
 * @return It returns the link related with the id, else it returns NULL
*/
Link *game_get_link(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID)
    return NULL;

  for (i = 0; i < MAX_LINKS && game->links[i] != NULL; i++) {
    if (id == link_getId(game->links[i]))
      return game->links[i];
  }

  return NULL;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets an object from it's id
 * @param game Pointer to structure Game
 * @param id Object's ID
 * @return It returns the object related with the id, else it returns NULL
 */
Object *game_get_object(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID)
    return NULL;

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if (id == object_get_id(game->objects[i]))
      return game->objects[i];
  }

  return NULL;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets an enemy from it's id
 * @param game Pointer to structure Game
 * @param id Enemy's ID
 * @return It returns the enemy related with the id, else it returns NULL
 */
Enemy *game_get_enemy(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID)
    return NULL;

  for (i = 0; i < MAX_ENEMY && game->enemy[i] != NULL; i++) {
    if (id == enemy_getId(game->enemy[i]))
      return game->enemy[i];
  }

  return NULL;
}

/*----------------------------------------------------------------------------------------------------------*/
/**
 * @brief It sets the space where the player is
 * @param game Pointer to structure Game
 * @param id new Id where the player is
 * @return it returns OK if it goes well, else returns ERROR
 */
STATUS game_set_player_location(Game *game, Id id)
{
  if (id == NO_ID)
  {
    return ERROR;
  }

  return player_setLocation(game->play, id);
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets the space where the player is
 * @param game Pointer to structure Game
 * @return it returns the ID of the space the player is
 */
Id game_get_player_location(Game *game)
{
  return player_getLocation(game->play);
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It sets the space where the object is
 * @param game Pointer to structure Game
 * @param id new Id where the object is
 * @return it returns OK if it goes well, else returns ERROR
 */
STATUS game_set_object_location(Game *game, Id id, Id location)
{
  int i;
  
  Space *aux = NULL;
  if (id == NO_ID)
  {
    return ERROR;
  }
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (game_get_space_id_at(game, i) == location)
    {
      aux = game->spaces[i];
      break;
    }
  }

  return space_add_object(aux, id);
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets the space where the object is
 * @param game Pointer to structure Game
 * @return it returns the ID of the space the object is
 */
Id game_get_object_location(Game *game, Id id)
{
  int i;

  if (!game)
  {
    return NO_ID;
  }

  if (player_hasObject(game->play, id))
  {
    return CARRIED;
  }
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (space_has_object(game->spaces[i], id))
    {
      return game_get_space_id_at(game, i);
    }
  }

  return NO_ID;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets the description 
 * @param game Pointer to structure Game
 * @return it returns the game description
 */
char *game_get_description(Game *game)
{
  if (!game)
  {
    return NULL;
  }

  return game->description;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief Updates the game with the last command given
 * @param game Pointer to structure Game
 * @param cmd Last command given
 * @return Ok if it can update the game, else it returns ERROR
 */
STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  game->cmd_st = OK;

  switch (cmd)
  {
  case UNKNOWN:
    game_command_unknown(game);
    break;

  case EXIT:
    game_command_exit(game);
    break;

  case NEXT:
    game_command_next(game);
    break;

  case BACK:
    game_command_back(game);
    break;

  case RIGHT:
    game_command_right(game);
    break;

  case LEFT:
    game_command_left(game);
    break;

  case TAKE:
    game_command_take(game);
    break;

  case DROP:
    game_command_drop(game);
    break;

  case ATTACK:
    game_command_attack(game);
    break;

  case MOVE:
    game_command_move(game);
    break;

  case INSPECT:
    game_command_inspect(game);
    break;

  default:
    break;
  }

  return OK;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It gets the last command from the imput
 * @param game Pointer to structure Game
 * @return it returns the last command given
 */
T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief Prints on screen the Game data
 * @param game Pointer to structure Game
 */
void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
  {
    printf("=> Object %d location: %d\n", (int)object_get_id(game->objects[i]), (int)game_get_object_location(game, object_get_id(game->objects[i])));
  }
  printf("=> Player location: %d\n", (int)player_getLocation(game->play));
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief It says wether the game is over or not
 * @param game Pointer to structure Game
 * @return TRUE if it is over, FALSE if it isn't
 */
BOOL game_is_over(Game *game)
{
  if (player_getHealth(game->play) <= 0)
    return TRUE;

  return FALSE;
}

/**
   Calls implementation for each action
*/

/**
 * @brief If no commands are used nothing happens
 * @param game Pointer to structure Game
 */
void game_command_unknown(Game *game)
{
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief If e or exit command is used the game ends
 * @param game Pointer to structure Game
 */
void game_command_exit(Game *game)
{
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief If n or next command it moves the player move to the next space
 * @param game Pointer to structure Game
 * @return OK or ERROR
 */
void game_command_next(Game *g)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID, link_id = NO_ID, req = NO_ID, aux = NO_ID;
  long first_digit = 0;

  space_id = game_get_player_location(g);
  g->description[0] = '\0';

  if (NO_ID == space_id)
  { 
    printf("Error 0");
    g->cmd_st = ERROR;
    return;
  }

  link_id = space_get_south(game_get_space(g, space_id));
    if (link_id != NO_ID) {
      if(link_getOpen(game_get_link(g, link_id)) == FALSE) {
        aux = req = link_getRequirement(game_get_link(g, link_id));
        while (aux != 0) {
            first_digit = aux % 10;
            aux /= 10;
        }
        if (first_digit == 2) {
          if(player_hasObject(g->play, req) == TRUE) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else { 
            fprintf(stdout, "You need to have the object %s to open this door\n", object_get_name(game_get_object(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else if(first_digit == 4) {
          
          if(enemy_getHealth(game_get_enemy(g, req)) == 0) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else {
            fprintf(stdout, "You need to kill the enemy %s to open this door\n", enemy_getName(game_get_enemy(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else {
          printf("Error 4");
          g->cmd_st = ERROR;
          return;
        }
      }
      if(link_getOpen(game_get_link(g, link_id)) == TRUE) {
        if((current_id = link_getDestination(game_get_link(g, link_id))) == NO_ID) {
          printf("Error 5");
          g->cmd_st = ERROR;
          return;
        }
        else
          player_setLocation(g->play, current_id);
      }
    }
    else {
      printf("Error 6");
      g->cmd_st = ERROR;
      return;
    }
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief If b or back command it makes the player move to the previous space
 * @param game Pointer to structure Game
 * @return OK or ERROR
 */
void game_command_back(Game *g)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID, link_id = NO_ID, req = NO_ID, aux = NO_ID;
  long first_digit = 0;

  space_id = game_get_player_location(g);
  g->description[0] = '\0';

  if (NO_ID == space_id)
  { 
    printf("Error 0");
    g->cmd_st = ERROR;
    return;
  }

  link_id = space_get_north(game_get_space(g, space_id));
    link_print(game_get_link(g, link_id));
    printf("\n");
    if (link_id != NO_ID) {
      if(link_getOpen(game_get_link(g, link_id)) == FALSE) {
        aux = req = link_getRequirement(game_get_link(g, link_id));
        while (aux != 0) {
            first_digit = aux % 10;
            aux /= 10;
        }
        if (first_digit == 2) {
          if(player_hasObject(g->play, req) == TRUE) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else { 
            fprintf(stdout, "You need to have the object %s to open this door", object_get_name(game_get_object(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else if(first_digit == 4) {
          if(enemy_getHealth(game_get_enemy(g, req)) <= 0) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else {
            fprintf(stdout, "You need to kill the enemy %s to open this door", enemy_getName(game_get_enemy(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else {
          printf("Error 1");
          g->cmd_st = ERROR;
          return;
        }
      }
      if(link_getOpen(game_get_link(g, link_id)) == TRUE) {
        if((current_id = link_getDestination(game_get_link(g, link_id))) == NO_ID) {
          printf("Error 5");
          g->cmd_st = ERROR;
          return;
        }
        else
          player_setLocation(g->play, current_id);
      }
    }
    else {
      printf("Error 3");
      g->cmd_st = ERROR;
      return;
    }
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief If r or right command it makes the player move to the right space
 * @param game Pointer to structure Game
 * @return OK or ERROR
 */
void game_command_right(Game *g)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID, link_id = NO_ID, req = NO_ID, aux = NO_ID;
  long first_digit = 0;

  space_id = game_get_player_location(g);
  g->description[0] = '\0';

  if (NO_ID == space_id)
  { 
    printf("Error 0");
    g->cmd_st = ERROR;
    return;
  }

  link_id = space_get_east(game_get_space(g, space_id));
    link_print(game_get_link(g, link_id));
    printf("\n");
    if (link_id != NO_ID) {
      if(link_getOpen(game_get_link(g, link_id)) == FALSE) {
        aux = req = link_getRequirement(game_get_link(g, link_id));
        while (aux != 0) {
            first_digit = aux % 10;
            aux /= 10;
        }
        if (first_digit == 2) {
          if(player_hasObject(g->play, req) == TRUE) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else { 
            fprintf(stdout, "You need to have the object %s to open this door", object_get_name(game_get_object(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else if(first_digit == 4) {
          if(enemy_getHealth(game_get_enemy(g, req)) <= 0) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else {
            fprintf(stdout, "You need to kill the enemy %s to open this door", enemy_getName(game_get_enemy(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else {
          printf("Error 10");
          g->cmd_st = ERROR;
          return;
        }
      }
      if(link_getOpen(game_get_link(g, link_id)) == TRUE) {
        if((current_id = link_getDestination(game_get_link(g, link_id))) == NO_ID) {
          printf("Error 5");
          g->cmd_st = ERROR;
          return;
        }
        else
          player_setLocation(g->play, current_id);
      }
    }
    else {
      printf("Error 12");
      g->cmd_st = ERROR;
      return;
    }
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief If l or left command it makes the player move to the right space
 * @param game Pointer to structure Game
 * @return OK or ERROR
 */
void game_command_left(Game *g)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID, link_id = NO_ID, req = NO_ID, aux = NO_ID;
  long first_digit = 0;

  space_id = game_get_player_location(g);
  g->description[0] = '\0';

  if (NO_ID == space_id)
  { 
    printf("Error 0");
    g->cmd_st = ERROR;
    return;
  }

  link_id = space_get_west(game_get_space(g, space_id));
    link_print(game_get_link(g, link_id));
    printf("\n");
    if (link_id != NO_ID) {
      if(link_getOpen(game_get_link(g, link_id)) == FALSE) {
        aux = req = link_getRequirement(game_get_link(g, link_id));
        while (aux != 0) {
            first_digit = aux % 10;
            aux /= 10;
        }
        if (first_digit == 2) {
          if(player_hasObject(g->play, req) == TRUE) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else { 
            fprintf(stdout, "You need to have the object %s to open this door", object_get_name(game_get_object(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else if(first_digit == 4) {
          if(enemy_getHealth(game_get_enemy(g, req)) <= 0) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else {
            fprintf(stdout, "You need to kill the enemy %s to open this door", enemy_getName(game_get_enemy(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else {
          printf("Error 7");
          g->cmd_st = ERROR;
          return;
        }
      }
      if(link_getOpen(game_get_link(g, link_id)) == TRUE) {
        if((current_id = link_getDestination(game_get_link(g, link_id))) == NO_ID) {
          printf("Error 5");
          g->cmd_st = ERROR;
          return;
        }
        else
          player_setLocation(g->play, current_id);
      }
    }
    else {
      printf("Error 9");
      g->cmd_st = ERROR;
      return;
    }
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief If t or take command it makes the player take the object
 * @param game Pointer to structure Game
 * @return OK or ERROR
 */
void game_command_take(Game *g)
{
  Id space_id, object_id = NO_ID;
  char object_name[WORD_SIZE + 1];

  if (g == NULL)
  {
    g->cmd_st = ERROR;
    return;
  }
  g->description[0] = '\0';

  scanf(" %s", object_name);
  space_id = game_get_player_location(g);
  if (object_name[0] == '\0')
  {
    g->cmd_st = ERROR;
    return;
  }

  object_id = _game_getObjectId_fromName(g, object_name);
  if(object_id == NO_ID) {
    g->cmd_st = ERROR;
    return;
  }

  if ((game_get_object_location(g, object_id) != space_id) || (space_has_object(game_get_space(g, space_id), object_id) == FALSE))
  {
    g->cmd_st = ERROR;
    return;
  }

  space_delete_object(game_get_space(g, space_id), object_id);
  player_addObject(g->play, object_id);
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief If d or drop command it makes the player drop the object
 * @param game Pointer to structure Game
 * @return OK or ERROR
 */
void game_command_drop(Game *g)
{
  Id space_id, object_id = NO_ID;
  char object_name[WORD_SIZE + 1];
  if (!g)
  {
    g->cmd_st = ERROR;
    return;
  }
  g->description[0] = '\0';

  scanf(" %s", object_name);
  space_id = game_get_player_location(g);
  if (object_name[0] == '\0')
  {
    g->cmd_st = ERROR;
    return;
  }

  object_id = _game_getObjectId_fromName(g, object_name);
  if(object_id == NO_ID) {
    g->cmd_st = ERROR;
    return;
  }

  if (player_hasObject(g->play, object_id) == FALSE)
  {
    g->cmd_st = ERROR;
    return;
  }

  space_add_object(game_get_space(g, space_id), object_id);
  player_deleteObject(g->play, object_id);
}

/*---------------------------------------------------------------------------------------------------------*/

/**
 * @brief If a or attack command it makes a combat between
 * @param game Pointer to structure Game
 * @return OK or ERROR
 */
void game_command_attack(Game *g)
{
  int dmg, player_hp, enemy_hp;
  Id player_loc, enemy_loc;

  if (!g)
  {
    g->cmd_st = ERROR;
    return;
  }
  g->description[0] = '\0';

  player_loc = player_getLocation(g->play);
  enemy_loc = enemy_getLocation(g->enemy[0]);
  player_hp = player_getHealth(g->play);
  enemy_hp = enemy_getHealth(g->enemy[0]);

  if (player_loc != enemy_loc || enemy_hp<=0 )
  {
    g->cmd_st = ERROR;
    return;
  }

  dmg = (rand() % 10);

  if (dmg <= 4)
  {
    if (dmg == 0)
    {
      player_hp -= 2;
    }
    else
    {
      player_hp--;
    }
    player_setHealth(g->play, player_hp);
  }
  else
  {
    if (dmg == 9)
    {
      enemy_hp -= 2;
    }
    else
    {
      enemy_hp--;
    }
    enemy_setHealth(g->enemy[0], enemy_hp);
  }

  if (enemy_hp <= 0)
  {
    enemy_setLocation(g->enemy[0], NO_ID);
  }
}

/*----------------------------------------------------------------------------------------------------------*/

/**
 * @brief If m or move command it makes the player move to the direction requested
 * @param game Pointer to structure Game
 */
void game_command_move(Game *g)
{
  Id current_id = NO_ID;
  Id space_id = NO_ID, link_id = NO_ID, req = NO_ID, aux = NO_ID;
  long first_digit = 0;
  char direction;

  if (!g)
  { 
    printf("Error -1");
    g->cmd_st = ERROR;
    return;
  }

  space_id = game_get_player_location(g);
  g->description[0] = '\0';

  if (NO_ID == space_id)
  { 
    printf("Error 0");
    g->cmd_st = ERROR;
    return;
  }

  scanf(" %c", &direction);
/*NORTH*/
  if (direction == 'n' || direction == 'N') {

    link_id = space_get_north(game_get_space(g, space_id));
    if (link_id != NO_ID) {
      if(link_getOpen(game_get_link(g, link_id)) == FALSE) {
        aux = req = link_getRequirement(game_get_link(g, link_id));
        while (aux != 0) {
            first_digit = aux % 10;
            aux /= 10;
        }
        if (first_digit == 2) {
          if(player_hasObject(g->play, req) == TRUE) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else { 
            fprintf(stdout, "You need to have the object %s to open this door\n", object_get_name(game_get_object(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else if(first_digit == 4) {
          if(enemy_getHealth(game_get_enemy(g, req)) == 0) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else {
            fprintf(stdout, "You need to kill the enemy %s to open this door\n", enemy_getName(game_get_enemy(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else {
          printf("Error 4");
          g->cmd_st = ERROR;
          return;
        }
      }
      if(link_getOpen(game_get_link(g, link_id)) == TRUE) {
        if((current_id = link_getDestination(game_get_link(g, link_id))) == NO_ID) {
          printf("Error 5");
          g->cmd_st = ERROR;
          return;
        }
        else
          player_setLocation(g->play, current_id);
      }
    }
    else {
      printf("Error 6");
      g->cmd_st = ERROR;
      return;
    }
  }
  /*SOUTH*/
  else if (direction == 's' || direction == 'S') {
    link_id = space_get_south(game_get_space(g, space_id));
    if (link_id != NO_ID) {
      if(link_getOpen(game_get_link(g, link_id)) == FALSE) {
        aux = req = link_getRequirement(game_get_link(g, link_id));
        while (aux != 0) {
            first_digit = aux % 10;
            aux /= 10;
        }
        if (first_digit == 2) {
          if(player_hasObject(g->play, req) == TRUE) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else { 
            fprintf(stdout, "You need to have the object %s to open this door", object_get_name(game_get_object(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else if(first_digit == 4) {
          if(enemy_getHealth(game_get_enemy(g, req)) <= 0) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else {
            fprintf(stdout, "You need to kill the enemy %s to open this door", enemy_getName(game_get_enemy(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else {
          printf("Error 4");
          g->cmd_st = ERROR;
          return;
        }
      }
      if(link_getOpen(game_get_link(g, link_id)) == TRUE) {
        if((current_id = link_getDestination(game_get_link(g, link_id))) == NO_ID) {
          printf("Error 5");
          g->cmd_st = ERROR;
          return;
        }
        else
          player_setLocation(g->play, current_id);
      }
    }
    else {
      printf("Error 6");
      g->cmd_st = ERROR;
      return;
    }
  }
  /*WEST*/
  else if (direction == 'w' || direction == 'W') {
    link_id = space_get_west(game_get_space(g, space_id));
    if (link_id != NO_ID) {
      if(link_getOpen(game_get_link(g, link_id)) == FALSE) {
        aux = req = link_getRequirement(game_get_link(g, link_id));
        while (aux != 0) {
            first_digit = aux % 10;
            aux /= 10;
        }
        if (first_digit == 2) {
          if(player_hasObject(g->play, req) == TRUE) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else { 
            fprintf(stdout, "You need to have the object %s to open this door", object_get_name(game_get_object(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else if(first_digit == 4) {
          if(enemy_getHealth(game_get_enemy(g, req)) <= 0) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else {
            fprintf(stdout, "You need to kill the enemy %s to open this door", enemy_getName(game_get_enemy(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else {
          printf("Error 7");
          g->cmd_st = ERROR;
          return;
        }
      }
      if(link_getOpen(game_get_link(g, link_id)) == TRUE) {
        if((current_id = link_getDestination(game_get_link(g, link_id))) == NO_ID) {
          printf("Error 5");
          g->cmd_st = ERROR;
          return;
        }
        else
          player_setLocation(g->play, current_id);
      }
    }
    else {
      printf("Error 9");
      g->cmd_st = ERROR;
      return;
    }
  }
  /*EAST*/
  else if (direction == 'e' || direction == 'E') {
    link_id = space_get_east(game_get_space(g, space_id));
    if (link_id != NO_ID) {
      if(link_getOpen(game_get_link(g, link_id)) == FALSE) {
        aux = req = link_getRequirement(game_get_link(g, link_id));
        while (aux != 0) {
            first_digit = aux % 10;
            aux /= 10;
        }
        if (first_digit == 2) {
          if(player_hasObject(g->play, req) == TRUE) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else { 
            fprintf(stdout, "You need to have the object %s to open this door", object_get_name(game_get_object(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else if(first_digit == 4) {
          if(enemy_getHealth(game_get_enemy(g, req)) <= 0) {
            link_setOpen(game_get_link(g, link_id), TRUE);
          }
          else {
            fprintf(stdout, "You need to kill the enemy %s to open this door", enemy_getName(game_get_enemy(g, req)));
            g->cmd_st = ERROR;
            return;
          }
        }
        else {
          printf("Error 10");
          g->cmd_st = ERROR;
          return;
        }
      }
      if(link_getOpen(game_get_link(g, link_id)) == TRUE) {
        if((current_id = link_getDestination(game_get_link(g, link_id))) == NO_ID) {
          printf("Error 5");
          g->cmd_st = ERROR;
          return;
        }
        else
          player_setLocation(g->play, current_id);
      }
    }
    else {
      printf("Error 12");
      g->cmd_st = ERROR;
      return;
    }
  }
  g->description[0] = '\0';
}

/*----------------------------------------------------------------------------------------------------------*/
/**
 * @brief If i or inspect command it obtains the description of an object that the player has or the space where the player is
 * @param game Pointer to structure Game
 */
void game_command_inspect(Game *g) {
  Id object_id = NO_ID, p_loc = NO_ID;
  char name[WORD_SIZE + 1];
   if (g == NULL)
  {
    g->cmd_st = ERROR;
    return;
  }
  g->description[0] = '\0';
  p_loc = game_get_player_location(g);

  scanf(" %s", name);
  if (name[0] == '\0')
    {
      g->cmd_st = ERROR;
      return;
    }
  if (strcmp(name, "s")==0||strcmp(name,"space")==0) {
    strcpy(g->description, space_get_desc(game_get_space(g, p_loc)));
  }
  else 
  {
    object_id = _game_getObjectId_fromName(g, name);
    if(object_id == NO_ID) {
      g->cmd_st = ERROR;
      return;
    }

    if ((game_get_object_location(g, object_id) != p_loc) && (player_hasObject(g->play, object_id) == FALSE))
    {
      g->cmd_st = ERROR;
      return;
    }

    strcpy(g->description, object_get_desc(game_get_object(g, object_id)));
  }
}
