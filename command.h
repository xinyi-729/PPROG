/**
 * @brief It defines the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 1
 * @date 13-02-2025
 * @copyright GNU Public License
 */

 #ifndef COMMAND_H
 #define COMMAND_H
 
 #include "types.h"
 
 #define N_CMDT 2
 #define N_CMD 12
 
 typedef enum { CMDS, CMDL } CommandType;
 
 typedef enum { NO_CMD = -1, UNKNOWN, EXIT, MOVE, TAKE, DROP, ATTACK, CHAT, INSPECT} CommandCode;
 
 typedef struct _Command Command;
 
 
 /**
  * @brief It creates a new command, allocating memory and initializing it code
  * @author Profesores PPROG
  *
  * @param
  * @return a new command initializated
  */
 Command* command_create();
 
 
 /**
  * @brief It destroy a command, freeing its allocated memory
  * @author Profesores PPROG
  *
  * @param command a pointer to the command that must be destroyed
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
 Status command_destroy(Command* command);
 
 /**
  * @brief It sets a code to a command
  * @author Profesores PPROG
  *
  * @param command a pointer to the command that we want to change the code and the code that we want to set
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
 Status command_set_code(Command* command, CommandCode code);
 
 /**
  * @brief It gets a code from a command
  * @author Profesores PPROG
  *
  * @param command a pointer to the command that we want to get the code
  * @return The code of the command
  */
 CommandCode command_get_code(Command* command);
 
 
 /**
  * @brief It gets the user input and transform it into a command
  * @author Profesores PPROG
  *
  * @param command a pointer to the command
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
 Status command_get_user_input(Command* command);
 
 /**
  * @brief It gets the second argument of command
  * @author Alejandro Fernández
  *
  * @param command a pointer to the command
  * @return a pointer to the name or NULL
  */
 char *command_get_argument(Command *command);
 
 /**
  * @brief It sets the argument
  * 
  * @author Xinyi Huang
  * 
  * @param command a pointer to the command
  * @param argument the second argument
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
 Status command_set_argument(Command *command, char *argument);
 
 /**
  * @brief It sets the exit status of the command
  * @author Alejandro Fernández
  *
  * @param command a pointer to the command
  * @param exit the status
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
 Status command_set_exit(Command *command, Status exit);
 
 /**
  * @brief It gets the exit status of the command
  * @author Alejandro Fernández
  *
  * @param command a pointer to the command
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
 Status command_get_exit(Command *command);
 
 #endif