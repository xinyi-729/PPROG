/**
 * @brief Define la interfaz de actualización del juego a traves de las acciones del usuario
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

/*-----------------------------------------------------------------------------------------------------*/
/* Funciones privadas*/

void game_actions_unknown(Game *game);

void game_actions_exit(Game *game);

void game_actions_next(Game *game);

void game_actions_back(Game *game);

/**New functions take/drop */

void game_actions_take(Game *game, char *obj_name);
void game_actions_drop(Game *game, char *obj_name);

/*-----------------------------------------------------------------------------------------------------*/

/* Implementacion de funciones de la interfaz */
/**---Por ahora le añado un campo char *obj_name, luego ya veré qué hacer con él */
Status game_actions_update(Game *game, Command *command, char *obj_name) {
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
      game_actions_take(game, obj_name);
      break;

    case DROP:
      game_actions_drop(game, obj_name);
      break; 

    default:
      break;
  }

  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
/* Implementacion de las funciones privadas */

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

  /* Obtener la ubicacion del jugador */
  space_id = game_get_player_location(game);
  if (NO_ID == space_id) {
    return; /* Si el jugador no está en ningún espacio, no hacemos nada */
  }
  
  /* Mover al jugador a esa nueva ubicacion*/
  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_actions_take(Game *game, char *obj_name){
  Id player_space_id= NO_ID;
  Id object_id=NO_ID;
  Space *space=NULL;

  if(!game)
    return;

  player_space_id = game_get_player_location(game);
  if(player_space_id == NO_ID)
    return;

  /*Obtener el id del objeto*/
  if((object_id = game_get_object_id(game, obj_name)) == NO_ID)
    return ;

  /*Obtener el TAD del espacio que está player*/
  space = game_get_space(game, player_space_id);
  if(!space)
    return;

  /*Comprobar que si este espacio hay ese objeto*/
  if(space_has_object(space, object_id) == FALSE)
    return;

  /*Como ya hicimos take, el objeto desaparece de ese espacio llamando a space_del_object*/
  if(space_del_object(space, object_id) == ERROR)
    return;

  /*Ahora, toca guardar el object en el jugador*/  
  if(player_set_object(game_get_player(game), object_id) == ERROR)
  return;


  return;
}

void game_actions_drop(Game *game, char *obj_name){
  Id player_space_id=NO_ID;
  Id object_id=NO_ID;
  Space *space=NULL;

  if(!game)
    return;

  /*Conseguir el id del jugador*/
  player_space_id = game_get_player_location(game);
  if(player_space_id == NO_ID)  
    return;

  /*Conseguir el espacio*/
  space = game_get_space(game, player_space_id);
  if(!space)
    return;
  
  /*Comprobar si el player tenga el object*/
  object_id =player_get_object(game_get_player(game));
  if(!object_id)
    return;

  /*Llamamos a space_del_obj para eliminar de este espacio*/
  if(space_del_object(space, object_id) == ERROR)
    return;

  /*Ahora, borrarlo del jugador*/
  if(player_set_object(game_get_player(game), NO_ID) == ERROR)
    return;

  return;
}