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
#include "player.h"

#include "set.h"
#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------------------------------*/
 /**
  * @brief Juego
  *
  * Esta estructura almacena toda la informacion de un juego.
  */
 struct _Game {
  Player *player;
  Object *object[MAX_OBJECTS];
  int n_objects;
  Space *spaces[MAX_SPACES];
  int n_spaces;
  Command *last_cmd;
  Bool finished;
  
};
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
 /* Funciones de la interfaz implementadas */

Game* game_create() {
  Game *game=NULL;
  int i;

  game = (Game*) malloc(sizeof(Game));
  if(!game)
    return NULL;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
    game->object[i] = NULL; /*Poner los punteros a NULL*/
  }

  game->n_spaces = 0;
  game->n_objects = 0;
  game->player = player_create(ID_PLAYER);
  game->last_cmd = command_create();
  game->finished = FALSE;

  return game;
}

Status game_destroy(Game *game) {
  int i = 0;
  if(!game)
    return ERROR;

  for (i = 0; i < game->n_spaces; i++) {
    space_destroy(game->spaces[i]);
    object_destroy(game->object[i]);
  }

  player_destroy(game->player);

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
 
Id game_get_object_location(Game *game, Id obj_id) {
  int i;

  if(!game || obj_id ==NO_ID)
    return NO_ID;

  /*hacer set de obj y ver en los set de cada espacio, buscar el espacio q está el objz*/

  for(i=0; i<game->n_spaces; i++){
    /*si el objeto está en este espacio, devolvemos el id de este espacio*/
    if( space_has_object(game->spaces[i], obj_id) == TRUE){
     return space_get_id(game->spaces[i]);
    }
  /*si no, seguimos buscando en el siguiente espacio*/
  }

  return NO_ID;
}

/*aquí, el campo de Id puede ser o de espacio(para load) o de objeto (para drop)*/
Status game_set_object_location(Game *game, Id id_space) {
  Command *cmd=NULL;
  char *nombre_obj=NULL;
  Id obj_id;

  if (!game) {
    return ERROR;
  }
  /*NO ESTOY SEGURO SI UTILIZAR ESTO*/
  cmd = game_get_last_command(game);
  if(!cmd)
    return ERROR;

  /*conseguir el nombre del objeto que quiero drop*/
  nombre_obj = command_get_argument(cmd);
  if(!nombre_obj)
    return ERROR;

  obj_id = game_get_object_id(game, nombre_obj);
  if( obj_id == NO_ID){
    return ERROR;
  }


  if(space_add_object(game_get_space(game, id_space), obj_id) == ERROR){
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

  printf("=> Objetos: \n");
  for(i=0; i<game->n_objects;i++){
    object_print(game->object[i]);
  }
   /* printf("No se ha asignado un objeto.\n");*/
  
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
/*NUEVA*/
Status game_add_object(Game *game, Object *obj){
  if(!game || !obj || game->n_objects >= MAX_OBJECTS)
    return ERROR;

  game->object[game->n_objects] = obj;
  game->n_objects++;

  return OK;
}

/*-------------------------------------------------*/
/*FUNCIONES NUEVAS*/
Player* game_get_player(Game *game){
  if(!game)
    return NULL;

  return game->player;
}

Id game_get_object_id(Game *game, char *obj_name){
  int i;
  if(!game || !obj_name)
    return NO_ID;

  /*Busca en la lista de objetos, si lo encuentra, retorna su id*/
  for(i=0; i<game->n_objects; i++){
    if(object_get_name(game->object[i]) == obj_name){
      return object_get_id(game->object[i]);
    }
  }

  return NO_ID;
}