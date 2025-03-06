/**
 * @brief Define la interfaz de actualización del juego
 * 
 * @file game_actions.h
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "types.h"
#include "game.h"

/**
 * @brief Actualiza el estado del juego segun el comando recibido
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @param command Puntero al comando 
 * @return OK si la actualizacion fue exitosa, ERROR en caso contrario
 */
Status game_actions_update(Game *game,Command *cmd);

#endif
