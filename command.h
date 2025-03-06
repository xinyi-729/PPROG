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

/**
 * @brief Crea un nuevo comando
 * 
 * @author Xinyi Huang y Lucia Ordovas

 * @return Puntero a la nueva estructura Command, NULL si falla
 */
Command* command_create();

/**
 * @brief Libera la memoria de un comando
 * 
 * @author Xinyi Huang y Lucia Ordovas
 * 
 * @param command Puntero al comando a destruir
 * @return OK si se destruyó correctamente, ERROR en caso contrario
 */
Status command_destroy(Command* command);

/**
 * @brief Establece el código de un comando
 * 
 * @author Xinyi Huang y Lucia Ordovas
 * 
 * @param command Puntero al comando
 * @param code Código del comando a establecer
 * @return OK si se asignó correctamente, ERROR en caso contrario
 */
Status command_set_code(Command* command, CommandCode code);

/**
 * @brief Obtiene el código de un comando
 * 
 * @author Xinyi Huang y Lucia Ordovas
 * 
 * @param command Puntero al comando
 * @return Código del comando o NO_CMD si no es válido
 */
CommandCode command_get_code(Command* command);

/**
 * @brief Obtiene el input del usuario
 * 
 * @author Xinyi Huang y Lucia Ordovas
 * 
 * @param command Puntero al comando
 * @return OK si el input es válido, ERROR en caso contrario
 */
Status command_get_user_input(Command* command);

/*Nuevas*/
Status command_set_argument(Command *command, char *argument);
char *command_get_argument(Command *cmd);

#endif
