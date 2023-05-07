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
#define MAX_STR 2048

struct _Graphic_engine
{
  Area *map, *minmap, *descript, *inventory, *inspace, *dialogue, *feedback, *descriptplayer;
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
  ge->descript = screen_area_init(1, 1, 48, 15);
  ge->descriptplayer = screen_area_init(1, 16, 48, 15);
  ge->inspace = screen_area_init(151, 17, 30, 14);
  ge->dialogue = screen_area_init(1, 42, 181, 7);
  ge->feedback = screen_area_init(1, 36, 181, 5);

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
  screen_area_destroy(ge->descriptplayer);
  screen_area_destroy(ge->inspace);
  screen_area_destroy(ge->dialogue);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
{
  Id id_act = NO_ID, id_north = NO_ID, id_south = NO_ID, id_east = NO_ID, id_west = NO_ID, player_loc = NO_ID, enemy_loc = NO_ID, id_start = 1122;
  int hp_player, hp_enemy, i = 0, nlines, num_obj, interaction, lines1, lines2, lines3, player_xp, player_def, player_atk;
  Space *space_act = NULL;
  Id *inv = NULL, *obj_in_space = NULL;
  char enemy[4] = "";
  char status[6] = "";
  char desc[235] = "";
  char str[MAX_STR] = "";
  char objnames[MAX_STR] = "";
  char aux[MAX_STR] = " ", aux1[MAX_STR] = " ", aux2[MAX_STR] = " ", aux3[MAX_STR] = " ", aux4[MAX_STR] = " ", aux5[MAX_STR] = " ";
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  const char *gdesc[100];

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

    /*Gets space descrpition*/

    nlines = space_get_nlines(space_act);
    lines1 = (nlines - 6) / 3;
    lines2 = lines1 + lines1;
    lines3 = lines2 + lines1;

    for (int i = 0; i < nlines; i++)
    {
      gdesc[i] = space_get_gdesc(space_act, i);
    }

    /*Paints space design*/
    /***************************************************************************************************/

    if (enemy_getLocation(game->enemy[0]) == id_act)
      strcpy(enemy, "UAM");
    else
      strcpy(enemy, "   ");

    if (id_act != NO_ID)
    {
      /*PRIMER TERCIO*/
      if (player_isHere(game->play, 0, 0))
      {
        printf("0");
        for (i = lines1; i < lines3; i++)
        {
          sprintf(str, "   %s", gdesc[i]);
          screen_area_puts(ge->map, str);
        }
      }
      else if (player_isHere(game->play, 0, 1))
      {
        printf("1");
        for (i = lines1; i < lines3; i++)
        {
          sprintf(str, "   %s", gdesc[i]);
          screen_area_puts(ge->map, str);
        }
      }
      else if (player_isHere(game->play, 0, 2))
      {
        printf("2");
        for (i = lines1; i < lines3; i++)
        {
          sprintf(str, "   %s", gdesc[i]);
          screen_area_puts(ge->map, str);
        }
      }
    }

    /*SEGUNDO TERCIO*/
    /*
    else if (player_isHere(game->play, 1, 0))
    {
      for (i = 0; i < lines1; i++)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
      for (i = lines2; i < lines3; i++)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
    }
    else if (player_isHere(game->play, 1, 1))
    {
      for (i = 0; i <lines1; i++)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
      for (i = lines2; i < lines3; i++)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
    }
    else if (player_isHere(game->play, 1, 2))
    {
      for (i = 0; i < lines1; i++)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
      for (i = lines2; i < lines3; i++)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
    }
    */
    /*TERCER TERCIO*/
    /*
    else if (player_isHere(game->play, 2, 0))
    {
      for (i = lines2 - 1; i <= 0; i--)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
    }
    else if (player_isHere(game->play, 2, 1))
    {
      for (i = lines2 - 1; i <= 0; i--)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
    }
    else if (player_isHere(game->play, 2, 2))
    {
      for (i = lines2 - 1; i <= 0; i--)
      {
        sprintf(str, "   %s", gdesc[i]);
        screen_area_puts(ge->map, str);
      }
    }
  }
  */

    /*Paint the inspace area*/

    screen_area_clear(ge->inspace);
    enemy_loc = enemy_getLocation(space_get_enemy(space_act));

    if (id_act != id_start)
    {
      if (enemy_loc == NO_ID)
      {
        sprintf(str, "   __");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "  | .|");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "  \\__<  / ");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "  | |  /");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "  | __/");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "  |___");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "  | |");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "  | |");
        screen_area_puts(ge->inspace, str);
      }
      else if (space_get_enemy(space_act) != NULL)
      {
        {
          sprintf(str, "   __");
          screen_area_puts(ge->inspace, str);
          sprintf(str, "  | .|             ,-\"\"\"\"-.  ");
          screen_area_puts(ge->inspace, str);
          sprintf(str, "  \\__<  /         /        \\ ");
          screen_area_puts(ge->inspace, str);
          sprintf(str, "  | |  /    \\/    :(_)  (_);  ");
          screen_area_puts(ge->inspace, str);
          sprintf(str, "  | __/     /\\    `   '`   ' ");
          screen_area_puts(ge->inspace, str);
          sprintf(str, "  |___              `++++' ");
          screen_area_puts(ge->inspace, str);
          sprintf(str, "  | |                `--' ");
          screen_area_puts(ge->inspace, str);
          sprintf(str, "  | |");
          screen_area_puts(ge->inspace, str);
        }
      }

      num_obj = set_get_numberofIds(space_get_set(space_act));

      if (num_obj != 0)
      {
        sprintf(str, "             ____");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "            |    | ");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "            | ^^ |");
        screen_area_puts(ge->inspace, str);
        sprintf(str, "            ******");
        screen_area_puts(ge->inspace, str);
      }
    }

    /*Paint the Minmap*/
    /***************************************************************************************************/

    screen_area_clear(ge->minmap);
    sprintf(str, " ");
    screen_area_puts(ge->minmap, str);

    if (id_act != id_start)
    {
      /*North*/
      if (id_north != NO_ID)
      {
        sprintf(str, "             ____");
        screen_area_puts(ge->minmap, str);
        sprintf(str, "            |%4ld|", id_north);
        screen_area_puts(ge->minmap, str);
        sprintf(str, "            |____|");
        screen_area_puts(ge->minmap, str);
        sprintf(str, " ");
        screen_area_puts(ge->minmap, str);
        sprintf(str, "              ^^");
        screen_area_puts(ge->minmap, str);
      }
      else
      {
        sprintf(str, " ");
        screen_area_puts(ge->minmap, str);
        screen_area_puts(ge->minmap, str);
        screen_area_puts(ge->minmap, str);
        screen_area_puts(ge->minmap, str);
      }

      /*West, Act, East*/

      /*WAE*/
      if (id_west != NO_ID && id_act != NO_ID && id_east != NO_ID)
      {
        sprintf(str, "  ____       ____       ____");
        screen_area_puts(ge->minmap, str);
        sprintf(str, " |%4ld|   < |%4ld| >   |%4ld|", id_west, id_act, id_east);
        screen_area_puts(ge->minmap, str);
        sprintf(str, " |____|   < |____| >   |____|");
        screen_area_puts(ge->minmap, str);
        sprintf(str, " ");
        screen_area_puts(ge->minmap, str);
      }
      /*WA*/
      else if (id_west != NO_ID && id_act != NO_ID && id_east == NO_ID)
      {
        sprintf(str, "  ____       ____");
        screen_area_puts(ge->minmap, str);
        sprintf(str, " |%4ld|   < |%4ld|", id_west, id_act);
        screen_area_puts(ge->minmap, str);
        sprintf(str, " |____|   < |____|");
        screen_area_puts(ge->minmap, str);
        sprintf(str, " ");
        screen_area_puts(ge->minmap, str);
      }
      /*AE*/
      else if (id_west == NO_ID && id_act != NO_ID && id_east != NO_ID)
      {
        sprintf(str, "             ____       ____");
        screen_area_puts(ge->minmap, str);
        sprintf(str, "            |%4ld| >   |%4ld|", id_act, id_east);
        screen_area_puts(ge->minmap, str);
        sprintf(str, "            |____| >   |____|");
        screen_area_puts(ge->minmap, str);
        sprintf(str, " ");
        screen_area_puts(ge->minmap, str);
      }
      /*A*/
      else
      {
        sprintf(str, "             ____");
        screen_area_puts(ge->minmap, str);
        sprintf(str, "            |%4ld|", id_act);
        screen_area_puts(ge->minmap, str);
        sprintf(str, "            |____|");
        screen_area_puts(ge->minmap, str);
        sprintf(str, " ");
        screen_area_puts(ge->minmap, str);
      }

      /*South*/
      if (id_south != NO_ID)
      {
        sprintf(str, "              vv");
        screen_area_puts(ge->minmap, str);
        sprintf(str, "             ____");
        screen_area_puts(ge->minmap, str);
        sprintf(str, "            |%4ld|", id_south);
        screen_area_puts(ge->minmap, str);
        sprintf(str, "            |____|");
        screen_area_puts(ge->minmap, str);
      }
      else
      {
        sprintf(str, " ");
        screen_area_puts(ge->minmap, str);
        screen_area_puts(ge->minmap, str);
        screen_area_puts(ge->minmap, str);
        screen_area_puts(ge->minmap, str);
      }
    }

    /*Paints the inventroy*/
    /***************************************************************************************************/

    screen_area_clear(ge->inventory);

    if (id_act == id_start)
    {
      sprintf(objnames, "TYPE \"n\" OR \"next\" TO START");
    }
    else
    {
      aux[0] = '\0';
      sprintf(objnames, "Inventory: ");

      inv = player_getObjects(game->play);

      num_obj = set_get_numberofIds(inventory_getObjs(player_getInventory(game->play)));
      for (i = 0; i < num_obj; i++)
      {
        if (inv[i] != NO_ID)
        {
          sprintf(aux, " %s", object_get_name(game_get_object(game, inv[i])));
          strcat(objnames, aux);
        }
      }
    }

    screen_area_puts(ge->inventory, objnames);

    /* Paint in the description area */
    /***************************************************************************************************/

    /*OBJECTS*/
    screen_area_clear(ge->descript);

    obj_in_space = space_get_objects(space_act);

    for (i = 0; i < num_obj; i++)
    {
      if (obj_in_space[i] != NO_ID)
      {
        sprintf(str, "  Object %s can be found in this room", object_get_name(game->objects[i]));
        screen_area_puts(ge->descript, str);
      }
    }

    /*ENEMY*/
    if (enemy_loc == player_getLocation(game->play))
    {
      sprintf(str, " ");
      screen_area_puts(ge->descript, str);
      screen_area_puts(ge->descript, str);
      screen_area_puts(ge->descript, str);
      screen_area_puts(ge->descript, str);
      sprintf(str, "  !!!!!!!!!!!!       /\\ ");
      screen_area_puts(ge->descript, str);
      sprintf(str, "  Enemy nearby      /||\\ ");
      screen_area_puts(ge->descript, str);
      sprintf(str, "  ^^^^^^^^^^^^     /_OO_\\");
      screen_area_puts(ge->descript, str);

      if (((hp_enemy = enemy_getHealth(space_get_enemy(space_act))) > 0) && (enemy_loc != NO_ID))
      {
        sprintf(str, "  Enemy HP:%d", hp_enemy);
        screen_area_puts(ge->descript, str);

        int num = hp_enemy;
        while (num > 0)
        {
          sprintf(str, "<3 ");
          strcat(aux4, str);
          num--;
        }
        screen_area_puts(ge->descript, aux4);
      }
      else if (enemy_loc == NO_ID)
      {
        sprintf(str, "  Enemy HP:DEAD");
        screen_area_puts(ge->descript, str);
      }
    }

    /*PLAYER*/

    screen_area_clear(ge->descriptplayer);

    if (id_act != id_start)
    {

      if ((player_loc = player_getLocation(game->play)) != NO_ID)
      {
        sprintf(str, "  Player location:%d", (int)player_loc);
        screen_area_puts(ge->descriptplayer, str);
      }
      if ((hp_player = player_getHealth(game->play)) > 0)
      {
        sprintf(str, "  Player HP:%d", hp_player);
        screen_area_puts(ge->descriptplayer, str);

        int num = hp_player;
        while (num > 0)
        {
          sprintf(str, "<3 ");
          strcat(aux1, str);
          num--;
        }
        screen_area_puts(ge->descriptplayer, aux1);
      }
      if ((player_def = player_getDefense(game->play) >= 0))
      {
        sprintf(str, "  Player Defense:%d", player_def);
        screen_area_puts(ge->descriptplayer, str);

        int num = player_def;
        while (num > 0)
        {
          sprintf(str, "D ");
          strcat(aux3, str);
          num--;
        }
        screen_area_puts(ge->descriptplayer, aux3);
      }
      if ((player_atk = player_getAttack(game->play)) >= 0)
      {
        sprintf(str, "  Player Attack:%d", player_atk);
        screen_area_puts(ge->descriptplayer, str);

        int num = player_atk;
        while (num > 0)
        {
          sprintf(str, "! ");
          strcat(aux5, str);
          num--;
        }
        screen_area_puts(ge->descriptplayer, aux5);
      }

      if ((player_xp = player_getXP(game->play)) >= 0)
      {
        sprintf(str, " ");
        screen_area_puts(ge->descriptplayer, str);
        screen_area_puts(ge->descriptplayer, str);

        sprintf(str, "  Player XP:%d", player_xp);
        screen_area_puts(ge->descriptplayer, str);

        int num = player_xp;
        while (num > 0)
        {
          sprintf(str, "*");
          strcat(aux2, str);
          num--;
        }
        screen_area_puts(ge->descriptplayer, aux2);
      }
    }

    /* Paint in the feedback area */

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

    /* Paints the dialogue area*/

    /*Inspect an object*/
    desc[0] = '\0';
    strcpy(desc, game_get_description(game));
    if (desc[0] != '\0')
    {
      sprintf(str, "  Description: %s", desc);
      screen_area_puts(ge->dialogue, str);
    }

    /* Interactions*/

    enum InteractionsAttack
    {
      Attack1,
      Attack2,
      Attack3,
    };

    if (last_cmd == 8 && game->cmd_st == OK)
    {
      interaction = rand() % 3;

      switch (interaction)
      {
      case Attack1:
      {
        sprintf(str, "\"Arghhh\"");
        screen_area_puts(ge->dialogue, str);
        break;
      }
      case Attack2:
      {
        sprintf(str, "*CLANK*");
        screen_area_puts(ge->dialogue, str);
        break;
      }
      case Attack3:
      {
        sprintf(str, "\"I wont give up!\"");
        screen_area_puts(ge->dialogue, str);
        break;
      }
      }
    }

    /* Dump to the terminal */
    screen_paint();
    printf("prompt:> ");
  }
}
