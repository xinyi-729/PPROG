/**
 * @brief Define la interfaz del juego
 *
 * @file game.h
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h" 
#include "types.h"
#include "player.h"
#include "object.h"

#define MAX_SPACES 100
#define ID_PLAYER 729
#define ID_OBJECT 407

/*-----------------------------------------------------------------------------------------------------*/
 /**
  * @brief Juego
  *
  * Esta estructura almacena toda la informacion de un juego.
  */
 typedef struct _Game {
  Player *player;
  Object *object;
  Space *spaces[MAX_SPACES];
  int n_spaces;
  Command *last_cmd;
  Bool finished;
} Game;
/*-----------------------------------------------------------------------------------------------------*/

Status game_create(Game *game);

Status game_destroy(Game *game);

Space *game_get_space(Game *game, Id id);

Id game_get_player_location(Game *game);

Status game_set_player_location(Game *game, Id id);

Id game_get_object_location(Game *game);

Status game_set_object_location(Game *game, Id id_space);

Command* game_get_last_command(Game *game);

Status game_set_last_command(Game *game, Command *command);

Bool game_get_finished(Game *game);

Status game_set_finished(Game *game, Bool finished);

void game_print(Game *game);

/*-----------------------------------------------------------------------------------------------------*/
Id game_get_space_id_at(Game *game, int position);
Status game_add_space(Game *game, Space *space);


#endif
