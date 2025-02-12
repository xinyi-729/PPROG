/**
 * @brief Implementa la estructura del juego
 *
 * @file game.c
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------------------------------*/
 /* Funciones de la interfaz implementadas */

Status game_create(Game *game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->n_spaces = 0;
  game->player = player_create(ID_PLAYER);
  game->object = object_create(ID_OBJECT);
  game->last_cmd = command_create();
  game->finished = FALSE;

  return OK;
}

Status game_destroy(Game *game) {
  int i = 0;
  if(!game)
    return ERROR;

  for (i = 0; i < game->n_spaces; i++) {
    space_destroy(game->spaces[i]);
  }

  player_destroy(game->player);
  object_destroy(game->object);
  command_destroy(game->last_cmd);

  return OK;
}
/*-----------------------------------------------------------------------------------------------------*/
 
Space *game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

   /* Recorremos los espacios del juego */
  for (i = 0; i < game->n_spaces; i++) {
    /* Si el id coincide con el id del espacio devolvemos ese id */
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}
/*-----------------------------------------------------------------------------------------------------*/
 
Id game_get_player_location(Game *game) { 
    
  if(!game)
    return NO_ID;
  
  return player_get_location(game->player);
}

Status game_set_player_location(Game *game, Id id) {
  if (!game || id == NO_ID) {
    return ERROR;
  }

  if(player_set_location(game->player, id) == ERROR)
    return ERROR;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
 
Id game_get_object_location(Game *game) { 
  int i;

  for(i=0; i<game->n_spaces; i++){
    if(object_get_id(game->object) == space_get_object_id(game->spaces[i]))
      return space_get_id(game->spaces[i]);
  }

  return NO_ID;
}

Status game_set_object_location(Game *game, Id id_space) {

  if (!game) {
    return ERROR;
  }

  if(space_set_object_id(game_get_space(game, id_space), object_get_id(game->object)) == ERROR){
    return ERROR;
  }

  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/

Command* game_get_last_command(Game *game) { return game->last_cmd; }

Status game_set_last_command(Game *game, Command *command) {
  game->last_cmd = command;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
 
Bool game_get_finished(Game *game) { return game->finished; }

Status game_set_finished(Game *game, Bool finished) {
  game->finished = finished;

  return OK;
}
/*-----------------------------------------------------------------------------------------------------*/

void game_print(Game *game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Espacios: \n");
  for (i = 0; i < game->n_spaces; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Jugador: ");
  if (game->player) {
    player_print(game->player);
  } else {
    printf("No se ha asignado un jugador.\n");
  }

  printf("=> Objeto: ");
  if (game->object) {
    object_print(game->object);
  } else {
    printf("No se ha asignado un objeto.\n");
  }
}
/*-----------------------------------------------------------------------------------------------------*/

Status game_add_space(Game *game, Space *space) {
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES)) {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}

Id game_get_space_id_at(Game *game, int position) {
  if (position < 0 || position >= game->n_spaces) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}
