/**
 * @brief Define la interfaz del interprete de comandos
 *
 * @file command.h
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2
#define N_CMD 7

typedef enum { CMDS, CMDL } CommandType;

typedef enum { NO_CMD = -1, UNKNOWN, EXIT, NEXT, BACK, TAKE, DROP } CommandCode;

typedef struct _Command Command;

Command* command_create();
Status command_destroy(Command* command);
Status command_set_code(Command* command, CommandCode code);
CommandCode command_get_code(Command* command);
Status command_get_user_input(Command* command);

#endif
