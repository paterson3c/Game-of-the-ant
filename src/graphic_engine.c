/**
 * @brief It defines a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#include <stdlib.h>
#include <stdio.h>
#include "graphic_engine.h"
#include "libscreen.h"
#include "command.h"
#include "space.h"
#include "types.h"

#define ROWS 50
#define COLUMNS 185
#define MAX_STR 1024

struct _Graphic_engine
{
  Area *map, *minmap, *descript, *inventory, *worklist, *dialogue;
};

Graphic_engine *graphic_engine_create()
{
  static Graphic_engine *ge = NULL;

  if (ge)
  {
    return ge;
  }

  screen_init(ROWS, COLUMNS);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL)
  {
    return NULL;
  }

  ge->map = screen_area_init(50, 1, 100, 30);
  ge->minmap = screen_area_init(151, 1, 30, 15);
  ge->inventory = screen_area_init(70, 32, 60, 3);
  ge->descript = screen_area_init(1, 1, 48, 30);
  ge->worklist = screen_area_init(151, 17, 30, 14);
  ge->dialogue = screen_area_init(1, 38, 181, 10);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge)
{
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->minmap);
  screen_area_destroy(ge->inventory);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->worklist);
  screen_area_destroy(ge->dialogue);


  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_north = NO_ID, id_south = NO_ID, id_east = NO_ID, id_west = NO_ID, obj_loc = NO_ID, player_loc = NO_ID, enemy_loc = NO_ID, *id = NULL;
  // Id link_north = NO_ID, link_south = NO_ID, link_east = NO_ID, link_west = NO_ID;
  int hp_player, hp_enemy, i = 0, num_obj, z;
  Space *space_north = NULL, *space_west = NULL, *space_act = NULL, *space_east = NULL, *space_south = NULL;
  const char *gdesc_north[GDESC], *gdesc_west[GDESC], *gdesc_act[GDESC], *gdesc_east[GDESC], *gdesc_south[GDESC];
  char enemy[4] = "";
  char status[6] = "";
  char desc[235] = "";
  char str[MAX_STR] = "";
  char aux[100] = "", obj_north[100] = "", obj_west[100] = "", obj_act[100] = "", obj_east[100] = "", obj_south[100] = "";
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);

  if ((id_act = game_get_player_location(game)) != NO_ID)
  {
    
    space_act = game_get_space(game, id_act);

    /*Sets the ids*/
    id_north = link_getDestination(game_get_link(game, space_get_north(space_act)));
    id_south = link_getDestination(game_get_link(game, space_get_south(space_act)));
    id_east = link_getDestination(game_get_link(game, space_get_east(space_act)));
    id_west = link_getDestination(game_get_link(game, space_get_west(space_act)));

    space_north = game_get_space(game, id_north);
    space_west = game_get_space(game, id_west);
    space_east = game_get_space(game, id_east);
    space_south = game_get_space(game, id_south);

    /*Gets space descrpition*/
    /*
    for (i = 0; i < (GDESC - 1); i++)
    {
      gdesc_north[i] = space_get_gdesc(space_north, i);
      gdesc_west[i] = space_get_gdesc(space_west, i);
      gdesc_act[i] = space_get_gdesc(space_act, i);
      gdesc_east[i] = space_get_gdesc(space_east, i);
      gdesc_south[i] = space_get_gdesc(space_south, i);
    }

    /*Initialize objects*/
    /*
    obj_north[0] = '\0';
    obj_west[0] = '\0';
    obj_act[0] = '\0';
    obj_east[0] = '\0';
    obj_south[0] = '\0';
    aux[0] = '\0';

    /*Prints the objects of each space*/
    /*
    id = space_get_objects(space_north);
    if (id != NULL)
    {
      aux[0] = '\0';
      num_obj = set_get_numberofIds(space_get_set(space_north));
      for (i = 0; i < num_obj; i++)
      {
        if (id[i] != NO_ID)
        {
          sprintf(aux, " %s", object_get_name(game_get_object(game, id[i])));
          strcat(obj_north, aux);
        }
      }
    }

    id = space_get_objects(space_west);
    if (id != NULL)
    {
      aux[0] = '\0';
      num_obj = set_get_numberofIds(space_get_set(space_west));
      for (i = 0; i < num_obj; i++)
      {
        if (id[i] != NO_ID)
        {
          sprintf(aux, " %s", object_get_name(game_get_object(game, id[i])));
          strcat(obj_west, aux);
        }
      }
    }

    id = space_get_objects(space_act);
    if (id != NULL)
    {
      aux[0] = '\0';
      num_obj = set_get_numberofIds(space_get_set(space_act));
      for (i = 0; i < num_obj; i++)
      {
        if (id[i] != NO_ID)
        {
          sprintf(aux, " %s", object_get_name(game_get_object(game, id[i])));
          strcat(obj_act, aux);
        }
      }
    }

    id = space_get_objects(space_east);
    if (id != NULL)
    {
      aux[0] = '\0';
      num_obj = set_get_numberofIds(space_get_set(space_east));
      for (i = 0; i < num_obj; i++)
      {
        if (id[i] != NO_ID)
        {
          sprintf(aux, " %s", object_get_name(game_get_object(game, id[i])));
          strcat(obj_east, aux);
        }
      }
    }

    id = space_get_objects(space_south);
    if (id != NULL)
    {
      aux[0] = '\0';
      num_obj = set_get_numberofIds(space_get_set(space_south));
      for (i = 0; i < num_obj; i++)
      {
        if (id[i] != NO_ID)
        {
          sprintf(aux, " %s", object_get_name(game_get_object(game, id[i])));
          strcat(obj_south, aux);
        }
      }
    }

    i = 0;
    */

    /*Paints north space*/
    /***************************************************************************************************/
    /*
    if (enemy_getLocation(game->enemy[0]) == id_north)
      strcpy(enemy, "UAM");
    else
      strcpy(enemy, "   ");
    
    printf("N:%ld\n", id_north);
    if(id_north != NO_ID)
    {
      sprintf(str, " ");
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                        +----------------+");
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                        |    %s      %3d|", enemy, (int)id_north);
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                        |   %10s   |", gdesc_north[i]);
      i++;
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                        |   %10s   |", gdesc_north[i]);
      i++;
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                        |   %10s   |", gdesc_north[i]);
      i++;
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                        |   %10s   |", gdesc_north[i]);
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                        |%16s|", obj_north);
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                        +----------------+");
      screen_area_puts(ge->map_north, str);
      sprintf(str, "                                 ^        ");
      screen_area_puts(ge->map_north, str);
      i = 0;
    }
    */
    /*Paints west space*/
    /***************************************************************************************************/
    /*
    if (enemy_getLocation(game->enemy[0]) == id_west)
      strcpy(enemy, "UAM");
    else
      strcpy(enemy, "   ");
    
    printf("W:%ld\n", id_west);
    if(id_west != NO_ID)
    {
      sprintf(str, " +----------------+");
      screen_area_puts(ge->map_west, str);
      sprintf(str, " |    %s      %3d|   ", enemy, (int)id_west);
      screen_area_puts(ge->map_west, str);
      sprintf(str, " |   %10s   |   ", gdesc_west[i]);
      i++;
      screen_area_puts(ge->map_west, str);
      sprintf(str, " |   %10s   | <", gdesc_west[i]);
      i++;
      screen_area_puts(ge->map_west, str);
      sprintf(str, " |   %10s   |   ", gdesc_west[i]);
      i++;
      screen_area_puts(ge->map_west, str);
      sprintf(str, " |   %10s   |   ", gdesc_west[i]);
      screen_area_puts(ge->map_west, str);
      sprintf(str, " |%16s|", obj_west);
      screen_area_puts(ge->map_west, str);
      sprintf(str, " +----------------+");
      screen_area_puts(ge->map_west, str);
      i = 0;
    }

    */
    /*Paints actual space*/
    /***************************************************************************************************/
    /*
    if (enemy_getLocation(game->enemy[0]) == id_act)
      strcpy(enemy, "UAM");
    else
      strcpy(enemy, "   ");
    
    printf("A:%ld\n", id_act);
    if (id_act != NO_ID)
    {
      sprintf(str, "+----------------+");
      screen_area_puts(ge->map_act, str);
      sprintf(str, "|m0^ %s      %3d|", enemy, (int)id_act);
      screen_area_puts(ge->map_act, str);
      sprintf(str, "|   %10s   |", gdesc_act[i]);
      i++;
      screen_area_puts(ge->map_act, str);
      sprintf(str, "|   %10s   |", gdesc_act[i]);
      i++;
      screen_area_puts(ge->map_act, str);
      sprintf(str, "|   %10s   |", gdesc_act[i]);
      i++;
      screen_area_puts(ge->map_act, str);
      sprintf(str, "|   %10s   |", gdesc_act[i]);
      screen_area_puts(ge->map_act, str);
      sprintf(str, "|%16s|", obj_act);
      screen_area_puts(ge->map_act, str);
      sprintf(str, "+----------------+");
      screen_area_puts(ge->map_act, str);
      i = 0;
    }
    */
    /*Paints east space*/
    /***************************************************************************************************/
    /*
    if (enemy_getLocation(game->enemy[0]) == id_east)
      strcpy(enemy, "UAM");
    else
      strcpy(enemy, "   ");
    
    printf("E:%ld\n", id_east);
    if(id_east != NO_ID)
    {
      sprintf(str, "   +----------------+");
      screen_area_puts(ge->map_east, str);
      sprintf(str, "   |    %s      %3d|   ", enemy, (int)id_east);
      screen_area_puts(ge->map_east, str);
      sprintf(str, "   |   %10s   |", gdesc_east[i]);
      i++;
      screen_area_puts(ge->map_east, str);
      sprintf(str, " > |   %10s   |", gdesc_east[i]);
      i++;
      screen_area_puts(ge->map_east, str);
      sprintf(str, "   |   %10s   |", gdesc_east[i]);
      i++;
      screen_area_puts(ge->map_east, str);
      sprintf(str, "   |   %10s   |", gdesc_east[i]);
      screen_area_puts(ge->map_east, str);
      sprintf(str, "   |%16s|", obj_east);
      screen_area_puts(ge->map_east, str);
      sprintf(str, "   +----------------+");
      screen_area_puts(ge->map_east, str);
      i = 0;
    }
    */
    /*Paints south space*/
    /***************************************************************************************************/
    /*
    if (enemy_getLocation(game->enemy[0]) == id_south)
      strcpy(enemy, "UAM");
    else
      strcpy(enemy, "   ");
    
    printf("S:%ld\n", id_south);
    if (id_south != NO_ID)
    {
      sprintf(str, "                                 v       ");
      screen_area_puts(ge->map_south, str);
      sprintf(str, "                        +----------------+");
      screen_area_puts(ge->map_south, str);
      sprintf(str, "                        |    %s      %3d|", enemy, (int)id_south);
      screen_area_puts(ge->map_south, str);
      sprintf(str, "                        |   %10s   |", gdesc_south[i]);
      i++;
      screen_area_puts(ge->map_south, str);
      sprintf(str, "                        |   %10s   |", gdesc_south[i]);
      i++;
      screen_area_puts(ge->map_south, str);
      sprintf(str, "                        |   %10s   |", gdesc_south[i]);
      i++;
      screen_area_puts(ge->map_south, str);
      sprintf(str, "                        |   %10s   |", gdesc_south[i]);
      screen_area_puts(ge->map_south, str);
      sprintf(str, "                        |%16s|", obj_south);
      screen_area_puts(ge->map_south, str);
      sprintf(str, "                        +----------------+");
      screen_area_puts(ge->map_south, str);
      i = 0;
    }
    */
    /* Paint in the description area */
    /***************************************************************************************************/

    screen_area_clear(ge->descript);
    for (z = 0; z < MAX_OBJECTS && game->objects[z] != NULL; z++)
    {
      if ((obj_loc = game_get_object_location(game, object_get_id(game->objects[z]))) == CARRIED)
      {
        sprintf(str, "  Object %s CARRIED", object_get_name(game->objects[z]));
        screen_area_puts(ge->descript, str);
      }
      else if ((obj_loc = game_get_object_location(game, object_get_id(game->objects[z]))) != NO_ID)
      {
        sprintf(str, "  Object %s location:%d", object_get_name(game->objects[z]), (int)obj_loc);
        screen_area_puts(ge->descript, str);
      }
    }
    /*PLAYER*/
    if ((player_loc = player_getLocation(game->play)) != NO_ID)
    {
      sprintf(str, "  Player location:%d", (int)player_loc);
      screen_area_puts(ge->descript, str);
    }
    if ((hp_player = player_getHealth(game->play)) > 0)
    {
      sprintf(str, "  Player HP:%d", hp_player);
      screen_area_puts(ge->descript, str);
    }
    /*ENEMY*/
    if ((enemy_loc = enemy_getLocation(game->enemy[0])) != NO_ID)
    {
      sprintf(str, "  Enemy location:%d", (int)enemy_loc);
      screen_area_puts(ge->descript, str);
    }
    if (((hp_enemy = enemy_getHealth(game->enemy[0])) > 0) && (enemy_loc != NO_ID))
    {
      sprintf(str, "  Enemy HP:%d", hp_enemy);
      screen_area_puts(ge->descript, str);
    }
    else if (enemy_loc == NO_ID)
    {
      sprintf(str, "  Enemy HP:DEAD");
      screen_area_puts(ge->descript, str);
    }

    /*DESCRIPTION*/
    desc[0] = '\0';
    strcpy(desc, game_get_description(game));
    if(desc[0] != '\0') {
      sprintf(str, "  Description: %s", desc);
      screen_area_puts(ge->descript, str);
    }

    /* Paint in the feedback area */
    /*
    last_cmd = game_get_last_command(game);
    if (game->cmd_st == ERROR)
    {
      strcpy(status, "ERROR");
    }
    else
    {
      strcpy(status, "OK");
    }

    sprintf(str, " %s (%s) = %s", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS], status);
    screen_area_puts(ge->feedback, str);
    */

    /* Dump to the terminal */
    screen_paint();
    printf("prompt:> ");
  }
}
