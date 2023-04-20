#include <stdio.h>
#include <stdlib.h>
#include "graphic_engine.h"
#include "game.h"
#include "command.h"
#include "game_reader.h"

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);
void game_loop_run(Game game, Graphic_engine *gengine, FILE *glog);
void game_loop_cleanup(Game game, Graphic_engine *gengine, FILE *glog);
