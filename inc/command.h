/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H
#include "types.h"

#define N_CMDT 2
#define N_CMD 10 /*max number of commands*/

typedef enum enum_CmdType {
  CMDS,
  CMDL
} T_CmdType;

/**
 * @brief Different commands.
 * 
*/
typedef enum enum_Command {
  NO_CMD = -1,  /*no imput*/ 
  UNKNOWN,      /*command not recognized*/ 
  EXIT,         /*exit the game*/
  TAKE,         /*take the object*/
  DROP,         /*drop the object*/
  MOVE,         /*move the player*/
  INSPECT,      /*inspect the object or the space*/
  COMBAT,       /*combat with the enemie*/
  USE,          /*use the object*/
  ADMIN,        /*admin mode*/
} T_Command;

/**
 * @brief Gets the user's input and compare it with the commands created
 * 
 * 
 * @return Returns the command, if it exists,
*/
T_Command command_get_user_input();

#endif
