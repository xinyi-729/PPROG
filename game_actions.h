/**
 * @brief It defines the game update interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 1
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "game.h"
#include "types.h"

/**
 * @brief It gets the last command, gets it code and update the game with it
 * @author Profesores PPROG
 *
 * @param game a pointer to the game and a pointer to the command
 * @return 
 */
Status game_actions_update(Game *game, Command *cmd);



#endif
