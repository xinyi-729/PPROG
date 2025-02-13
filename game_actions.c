/**
 * @brief It implements the game update through user actions
 *
 * @file game_actions.c
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"
#include "space.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

void game_actions_unknown(Game *game);

void game_actions_exit(Game *game);

void game_actions_next(Game *game);

void game_actions_back(Game *game);

/**New functions take/drop */

void game_actions_take(Game *game);
void game_actions_drop(Game *game);


/**
   Game actions implementation
*/

Status game_actions_update(Game *game, Command *command) {
  CommandCode cmd;

  game_set_last_command(game, command);

  cmd = command_get_code(command);

  switch (cmd) {
    case UNKNOWN:
      game_actions_unknown(game);
      break;

    case EXIT:
      game_actions_exit(game);
      break;

    case NEXT:
      game_actions_next(game);
      break;

    case BACK:
      game_actions_back(game);
      break;
    
    case TAKE:
      game_actions_take(game);
      break;

    case DROP:
      game_actions_drop(game);
      break; 

    default:
      break;
  }

  return OK;
}

/**
   Calls implementation for each action
*/

void game_actions_unknown(Game *game) {}

void game_actions_exit(Game *game) {}

void game_actions_next(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_actions_back(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (NO_ID == space_id) {
    return;
  }

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_actions_take(Game *game){
  Id player_space_id= NO_ID;
  Id object_space_id = NO_ID, object_id=NO_ID;
  Space *space=NULL;

  if(!game)
    return;

  /*Conseguir el id del espacio de player y object*/
  object_space_id = game_get_object_location(game);
  if(object_space_id ==NO_ID)
    return;

  player_space_id = game_get_player_location(game);
  if(player_space_id == NO_ID)
    return;

  if(player_space_id != object_space_id){
    return;
  }
  
  /*Obtener el TAD del espacio que está player y objeto*/
  space = game_get_space(game, player_space_id);
  if(!space)
    return;

  /*Obtener el id de ese objeto*/
  object_id = space_get_object_id(space);
  if(object_id == NO_ID)
    return;

  /*Como ya hicimos take, el objeto desaparece de ese espacio, lo que asignamos NO_ID para este espacio*/
  if(space_set_object_id(space,NO_ID) ==ERROR)
    return;

  /*Ahora, toca guardar el object en el jugador*/  
  if(player_set_object(game->player, object_id) == ERROR)
    return;

  return;
}

void game_actions_drop(Game *game){
  Id player_space_id=NO_ID;
  Id object_id=NO_ID;
  Space *space=NULL;

  if(!game)
    return;

  player_space_id = game_get_player_location(game);
  if(player_space_id == NO_ID)    /**EL ==NO_ID lo puedo escribir como !player... no? */
    return;
  if(!player_space_id)    
    return;

  space = game_get_space(game, player_space_id);
  if(!space)
    return;
  
  /*Comprobar si el player tenga el object*/
  object_id =player_get_object(game->player);
  if(!object_id)
    return;

  /*Asignamos el id del objeto en este espacio*/
  if(space_set_object_id(space, object_id) ==ERROR)
    return;

  /*Ahora, borrarlo del jugador*/
  if(player_set_object(game->player, NO_ID) == ERROR)
    return;

  return;
}