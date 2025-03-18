/**
 * @brief Implementa el interprete de comandos
 *
 * @file command.c
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define CMD_LENGHT 30

char *cmd_to_str[N_CMD][N_CMDT] = {
  {"", "No command"}, 
  {"", "Unknown"}, 
  {"e", "Exit"}, 
  {"n", "Next"}, 
  {"b", "Back"}, 
  {"t", "Take"},
  {"d", "Drop"}, 
  {"l", "Left"}, 
  {"r", "Right"}, 
  {"a", "Attack"}, 
  {"c", "Chat"}
};

/*----------------------------------------------------------------------------------------------------------------------------------*/
/**
 * @brief Command
 *
 * Guarda todas las informaciones relacionadas con el commando
 */
struct _Command {
  CommandCode code; /*!< Name of the command */
  char argument[WORD_SIZE+1];
  
};
/*--------------------------------------------------------------------------------------------------------------------------------------*/
 /** command_create reserva memoria para un nuevo comando
  *  e inicializa sus miembros
  */
Command* command_create() {
  Command* newCommand = NULL;

  newCommand = (Command*)malloc(sizeof(Command));
  if (newCommand == NULL) {
    return NULL;
  }

   /* Inicializacion de un comando vacio */
  newCommand->code = NO_CMD;


  return newCommand;
}

Status command_destroy(Command* command) {
  if (!command) {
    return ERROR;
  }

  free(command);
  command = NULL;
  return OK;
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/
Status command_set_code(Command* command, CommandCode code) {
  if (!command) {
    return ERROR;
  }

  command->code=code;

  return OK;
}

CommandCode command_get_code(Command* command) {
  if (!command) {
    return NO_CMD;
  }
  return command->code;
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/
Status command_set_argument(Command *command, char *argument){
  if(!command)
    return ERROR;

  strcpy(command->argument, argument);

  return OK;
}

char *command_get_argument(Command *cmd){
  if(!cmd)
    return NULL;

  return cmd->argument;
}

/*--------------------------------------------------------------------------------------------------------------------------------------*/

Status command_get_user_input(Command* command) {
  char input[CMD_LENGHT] = "", *token = NULL, *token2=NULL, argum[128] = "";
  int i = UNKNOWN - NO_CMD + 1;
  CommandCode cmd;

  if (!command) {
    return ERROR;
  }
  
  if (fgets(input, CMD_LENGHT, stdin)) {
    token = strtok(input, " \n");
    if (!token) {
      command_set_code(command, UNKNOWN);
    }

    token2 = strtok(NULL, "\n");
    if(token2 != NULL){
      strcpy(argum, token2);
      command_set_argument(command, argum);
    }

    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD) {
      if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL])) {
        cmd = i + NO_CMD;
      } else {
        i++;
      }
    }
    return command_set_code(command, cmd);
  }
  else
    return command_set_code(command, EXIT);
  
}
