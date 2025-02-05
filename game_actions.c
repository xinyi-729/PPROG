/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"
#include "space.h"

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

/****************!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
void game_actions_take(Game *game){
  Id player_space_id= NO_ID;
  Id object_space_id = NO_ID, object_id=NO_ID;
  Space *space=NULL;

  if(!game)
    return;

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

  /*Ahora, toca guardar el object en otro lugar (?)*/  

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

  /*DUDA: ¿Hay que controlar si el objeto ya existe en el espacio? O no se da el caso?*/

  space = game_get_space(game, player_space_id);
  if(!space)
    return;

  /*Obtener el id del objeto!!! 
  ---Capaz le añadimos una entrada Id object?*/


  if(space_set_object_id(space, object_id) ==ERROR)
    return;

  /*Después de poner el object_id en el espacio, eliminarlo del "basurero"*/

  return;
}