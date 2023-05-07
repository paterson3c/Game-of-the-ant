#include "game_reader.h"

STATUS game_create_from_file(Game *game, char *filename) {
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_load_spaces(game, filename) == ERROR) {
    return ERROR;
  }

  if(game_load_objects(game, filename) == ERROR) {
    return ERROR;
  }

  if (game_load_player(game, filename) == ERROR) {
    return ERROR;
  }

  if(game_load_enemy(game, filename) == ERROR) {
    return ERROR;
  }

  if(game_load_links(game, filename) == ERROR) {
    return ERROR;
  }
  
  return OK;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/

STATUS game_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  int nlines = 0;
  Id id = NO_ID;
  Space *space = NULL;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      nlines = atoi(toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%s|%d\n", id, name, desc, nlines);
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);
        space_set_desc(space, name);
        space_set_nlines(space, nlines);
        for (int i = 0; i < nlines; i++)
        {  
          fgets(line, WORD_SIZE, file);
          line[strlen(line)-1] = '\0';
          space_set_gdesc(space, line, i);
        }
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/

STATUS game_load_objects(Game *game, char *filename) 
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, id_loc = NO_ID;
  Object *object = NULL;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#o:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      id_loc = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(desc, toks);
      toks = strtok(NULL, "|");
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n"|%s, id, name, id_loc, desc);
#endif
      object = object_create(id);
      if (object != NULL)
      {
        object_set_name(object, name);
        object_set_desc(object, desc);
        game_add_object(game, object);
        space_add_object(game_get_space(game, id_loc), id);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/

STATUS game_load_player(Game *game, char *filename) 
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, id_loc = NO_ID;
  int health, capacity;
  Player *player = NULL;
  Inventory *inventory = NULL;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#p:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      id_loc = atol(toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
      capacity = atol(toks);
      toks = strtok(NULL, "|");
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d|%d\n", id, name, id_loc, health, capacity);
#endif
      player = player_create(id);
      if (player != NULL)
      {
        if((inventory = inventory_create()) == NULL)
        {
          player_destroy(player);
          return ERROR;
        }
        player_setName(player, name);
        player_setLocation(player, id_loc);
        player_setHealth(player, health);
        inventory_setCapacity(inventory, capacity);
        player_setInventory(player, inventory);
        game_add_player(game, player);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/

STATUS game_load_enemy(Game *game, char *filename) 
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, id_loc = NO_ID;
  int health;
  Enemy *enemy = NULL;
  STATUS status = OK;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#e:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      id_loc = atol(toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%d\n", id, name, id_loc, health);
#endif
      enemy = enemy_create();
      if (enemy != NULL)
      {
        enemy_setId(enemy, id);
        enemy_setName(enemy, name);
        enemy_setLocation(enemy, id_loc);
        enemy_setHealth(enemy, health);
        game_add_enemy(game, enemy);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/

STATUS game_load_links(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, orig = NO_ID, dest = NO_ID, req = NO_ID;
  DIRECTION dir = UNKNOWN;
  Link *link = NULL;
  BOOL open = TRUE;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#l:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      orig = atol(toks);
      toks = strtok(NULL, "|");
      dest = atol(toks);
      toks = strtok(NULL, "|");
      dir = atol(toks);
      toks = strtok(NULL, "|");
      open = atol(toks);
      toks = strtok(NULL, "|");
      req = atol(toks);
      toks = strtok(NULL, "|");

#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%d|%d|%ld|", id, name, orig, dest, dir, open, req);
#endif
      link = link_create();
      if (link != NULL) {
        link_setName(link, name);
        link_setId(link, id);
        link_setOrigin(link, orig);
        link_setDestination(link, dest);
        link_setDirection(link, dir);
        link_setOpen(link, open);
        link_setRequirement(link, req);

        if(dir == 1)
          space_set_north(game_get_space(game, orig), id);
        else if(dir == 2)
          space_set_south(game_get_space(game, orig), id);
        else if(dir == 3)
          space_set_east(game_get_space(game, orig), id);
        else if(dir == 4)
          space_set_west(game_get_space(game, orig), id);
  
        game_add_link(game, link);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}
