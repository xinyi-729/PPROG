/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 1
 * @date 13-02-2025
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
  {"m", "Move"},
  {"t", "Take"},
  {"d", "Drop"}, 
  {"a", "Attack"}, 
  {"c", "Chat"},
  {"i", "Inspect"}
};

/**
 * @brief Command
 *
 * This struct stores all the information related to a command.
 */
struct _Command
{
  CommandCode code;           /*!< Name of the command */
  char argument[WORD_SIZE+1]; /*!< Name of the object that we want to take if we use the take command*/
  Status Exit;  
};

/** command_create allocates memory for a new command
 *  and initializes it code
 */
Command *command_create()
{
  Command *newCommand = NULL;

  newCommand = (Command *)malloc(sizeof(Command));
  if (newCommand == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty command*/
  newCommand->code = NO_CMD;
  newCommand->argument[0] = '\0';
  newCommand->Exit = OK;
  /*Para qué sirve el exit???*/

  return newCommand;
}

/** command_destroy  checks if the command exist
 * and if it exist it free his allocated memory
 */
Status command_destroy(Command *command)
{
  if (!command)
  {
    return ERROR;
  }

  free(command);
  command = NULL;
  return OK;
}
/** command_set_code set a code to a command
 */
Status command_set_code(Command *command, CommandCode code)
{
  if (!command)
  {
    return ERROR;
  }

  /* Sets a code that receive as a parametter to the command*/
  command->code = code;

  return OK;
}

/** command_get_code gets the code of a command
 */

CommandCode command_get_code(Command *command)
{
  if (!command)
  {
    return NO_CMD;
  }
  return command->code;
}

Status command_get_exit(Command *command)
{
  if (command == NULL)
  {
    return ERROR;
  }

  return command->Exit;
}

Status command_set_exit(Command *command, Status exit)
{
  if (!command)
  {
    return ERROR;
  }


  command->Exit = exit;

  return OK;
}

char *command_get_argument(Command *command)
{

  if (command == NULL)
  {
    return NULL;
  }

  return command->argument;
}

Status command_set_argument(Command *command, char *argument){
  if(!command)
    return ERROR;

  strcpy(command->argument, argument);

  return OK;
}

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
      return command_set_code(command, UNKNOWN);
    }

    token2 = strtok(NULL, "\n");
    if(token2 != NULL){
      strcpy(argum, token2);
      return command_set_argument(command, argum);
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