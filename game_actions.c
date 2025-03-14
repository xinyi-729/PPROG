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
#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------------------------------*/
/* Funciones privadas*/

void game_actions_unknown(Game *game);

void game_actions_exit(Game *game);

void game_actions_next(Game *game);

void game_actions_back(Game *game);

void game_actions_take(Game *game);

void game_actions_drop(Game *game);

void game_actions_left(Game *game);

void game_actions_right(Game *game);

void game_actions_attack(Game *game);

char* game_actions_chat(Game *game);

/*-----------------------------------------------------------------------------------------------------*/

/* Implementacion de funciones de la interfaz */
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

    case LEFT:
      game_actions_left(game);
      break; 

    case RIGHT:
      game_actions_right(game);
      break; 

    case ATTACK:
      game_actions_attack(game);
      break; 

    case CHAT:
      game_actions_chat(game);
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
/*------------------------------------------------------------------------------*/
void game_actions_take(Game *game){
  Id player_space_id= NO_ID;
  Id object_id=NO_ID;
  Space *space=NULL;
  Command *cmd = NULL;
  //Si tiene algo no puede coger otra cosa

  if(!game)
    return;

  player_space_id = game_get_player_location(game);
  if(player_space_id == NO_ID)
    return;

  /*Obtener el ultimo comando*/
  if(!(cmd = game_get_last_command(game)))
    return;

  /*Obtener el id del objeto*/
  if((object_id = game_get_object_id(game, command_get_argument(cmd))) == NO_ID)
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

/*------------------------------------------------------------------------------*/
/*modificando*/
void game_actions_drop(Game *game){
  Id player_space_id=NO_ID;
  Id object_id=NO_ID;
  Space *space=NULL;

  if(!game)
    return;

  /*Conseguir el id del jugador*/
  player_space_id = game_get_player_location(game);
  if(player_space_id == NO_ID)  
    return;

  /*Conseguir el espacio que está el jugador*/
  space = game_get_space(game, player_space_id);
  if(!space)
    return;
  
  /*Comprobar si el player tenga el object*/
  object_id =player_get_object(game_get_player(game));
  if(object_id == NO_ID)
    return;

  /*Llamamos a space_add_obj para que aparezca en este espacio*/
  if(space_add_object(space, object_id) == ERROR)
    return;

  /*Ahora, borrarlo del jugador*/
  if(player_set_object(game_get_player(game), NO_ID) == ERROR)
    return;

  return;
}
/*------------------------------------------------------------------------------*/

void game_actions_left(Game *game){
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if(space_id == NO_ID)
    return ;

  current_id = space_get_west(game_get_space(game, space_id));
  if(current_id == NO_ID)
    return ;
  
  game_set_player_location(game, current_id);

  return;
}

void game_actions_right(Game *game){
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if(space_id == NO_ID)
    return ;

  current_id = space_get_east(game_get_space(game, space_id));
  if(current_id == NO_ID)
    return ;
  
  game_set_player_location(game, current_id);

  return;
}
/*------------------------------------------------------------------------------*/

void game_actions_attack(Game *game){
  Id player_space_id = NO_ID;
  Character *character = NULL;
  Player *player = NULL;
  int random_number; 

  if (!game) return;

  /* Veo en que espacio esta el player del juego */
  player_space_id = game_get_player_location(game);
  if (player_space_id == NO_ID) return;

  /* Obtengo el character que esta en ese espacio */
  character = game_get_character_in_space(game, player_space_id);
  if (!character || character_get_is_friendly(character)) 
    return; /* Solamente ataca si no es amigo */

  /* Obtengo al player */
  player = game_get_player(game);
  if (!player) return;

  if (character_get_health(character) == 0) return;
  
  /* Genero numero aleatorio */
  srand(time(NULL));
  random_number = rand() % 10;

  /* Si el numero generado esta entre 0 y 4 gana el adversario */
  if (random_number < 5) {
    /* El player pierde 1 punto de vida */
    player_decrease_health(player);

    /* Si no le quedan corazones ha perdido */
    if (player_get_health(player) == 0) {
      game_set_finished(game, TRUE);
    }
   else if (random_number > 4 && random_number < 10){
     /* Si esta entre 5 y 9 gana el player */
     character_decrease_health(character);
   }
   } else {
    return;
   }
}

char* game_actions_chat(Game *game);