/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 30-11-2020
 * @copyright GNU Public License
 */

#include "game_loop.h"

/*main program*/
int main(int argc, char *argv[]) {
  Game game;
  Graphic_engine *gengine;
  FILE *glog;

  glog = fopen("game.log", "a");
  if(!glog)
    return -1;

  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }
 
  if (!game_loop_init(&game, &gengine, argv[1])) { /*if not 0, initializes the game*/
    game_loop_run(game, gengine, glog); /*Initializes the game*/
    game_loop_cleanup(game, gengine, glog); /*Destroys the game*/
  }

  return 0;
}

/**
 * @brief Initializes the game and the graphic engine
 * @param game Pointer to stucture Game
 * @param gengine Matrix Pointer to structure graphic engine
 * @param file_name Name of the file where it's gonna be played
 * @return Returns 0 if it initializes, else returns ERROR
*/
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name) {
  if (game_create_from_file(game, file_name) == ERROR) { /*fails creating the game from a file*/
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL) { /*fails graphic engine*/
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }

  return 0;
}

/**
 * @brief It runs the game on a loop until it receives the command EXIT
 * @param game Pointer to stucture Game
 * @param gengine Matrix Pointer to structure graphic engine
*/
void game_loop_run(Game game, Graphic_engine *gengine, FILE *f) {
  T_Command command = NO_CMD;
  char str[6];
  extern char *cmd_to_str[N_CMD][N_CMDT];

  while ((command != EXIT) && !game_is_over(&game)) {
    graphic_engine_paint_game(gengine, &game);
    command = command_get_user_input();

    game_update(&game, command); 
    if(game.cmd_st == ERROR)
      strcpy(str, "ERROR");
    else
      strcpy(str, "OK");

    fprintf(f, " %s (%s) = %s\n", cmd_to_str[command - NO_CMD][CMDL], cmd_to_str[command - NO_CMD][CMDS], str);

    if(game_is_over(&game))
      printf("\n<<++++++++++++++++++>>\n\n      GAME OVER     \n\n<<++++++++++++++++++>>\n\n");
  }
}

/**
 * @brief It ends the game and clean up the screen/file
 * @param game Pointer to stucture Game
 * @param gengine Matrix Pointer to structure graphic engine
*/
void game_loop_cleanup(Game game, Graphic_engine *gengine,FILE *glog) {
  fclose(glog);
  game_destroy(&game);
  graphic_engine_destroy(gengine);
}
