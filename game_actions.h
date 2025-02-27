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

Status game_actions_update(Game *game,Command *cmd);

#endif
