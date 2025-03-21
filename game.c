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
  Character *character[MAX_CHARACTERS];
  int n_characters;
  
};

/*-----------------------------------------------------------------------------------------------------*/
Game* game_create() {
  Game *game=NULL;
  int i;

  game = (Game*) malloc(sizeof(Game));
  if(!game)
    return NULL;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++) {
    game->object[i] = NULL; /*Poner los punteros a NULL*/
  }

  for (i = 0; i < MAX_CHARACTERS; i++) {
    game->character[i] = NULL;
  }

  game->n_spaces = 0;
  game->n_objects = 0;
  game->n_characters = 0;
  game->player = player_create(PLAYER_ID);
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
    
  }

  for (i = 0; i < game->n_objects; i++) {
    object_destroy(game->object[i]);
    
  }

  player_destroy(game->player);

  command_destroy(game->last_cmd);
  free(game);

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
  
}
/*-----------------------------------------------------------------------------------------------------*/

Id game_get_space_id_at(Game *game, int position) {
  if (position < 0 || position >= game->n_spaces) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Status game_add_space(Game *game, Space *space) {
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES)) {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}
/*-----------------------------------------------------------------------------------------------------*/

Status game_add_object(Game *game, Object *obj){
  if(!game || !obj || game->n_objects >= MAX_OBJECTS)
    return ERROR;

  game->object[game->n_objects] = obj;
  game->n_objects++;

  return OK;
}

Id game_get_object_id(Game *game, char *obj_name){
  int i;
  char *n=NULL;
  if(!game || !obj_name)
    return NO_ID;

  /*Busca en la lista de objetos, si lo encuentra, retorna su id*/
  for(i=0; i<game->n_objects; i++){
    n= object_get_name(game->object[i]);
    if(strcmp(n, obj_name) == 0){
      return object_get_id(game->object[i]);
    }
  }
  return NO_ID;
}

/*-----------------------------------------------------------------------------------------------------*/

Player* game_get_player(Game *game){
  if(!game)
    return NULL;

  return game->player;
}

/*-----------------------------------------------------------------------------------------------------*/

int game_get_n_obj(Game *game){
  if(!game)
    return -1;

  return game->n_objects;
}
/*-----------------------------------------------------------------------------------------------------*/

Object *game_get_object(Game *game, Id id){
  int i;

  if(!game || id ==NO_ID)
    return NULL;

  for(i=0; i<game->n_objects; i++){
    if(id == object_get_id(game->object[i]))
      return game->object[i];
  }

  return NULL;
}
Character * game_get_character_in_space(Game *game, Id space_id){
  int character_id, i,j;

  if(!game || space_id == NO_ID){
    return NULL;
  }

  /* Primero encuentro el TAD del espacio con ese ID */
  for(i=0; i<game->n_spaces; i++){
    if(space_get_id(game->spaces[i]) == space_id){
      character_id = space_get_character_id(game->spaces[i]);
      if(character_id == NO_ID){
        return NULL;
      }

      /* Ahora encuentro el TAD del character con el ID que busco */
      for(j=0; j<MAX_CHARACTERS; j++){
        if(character_get_id(game->character[j]) == character_id){
          return game->character[j];
        }
      }
    }
  }
  
  return NULL;
}

/*---------------------------------------------------------------------------*/
char * game_get_message(Game *game){
  if(!game) return NULL;

  return character_get_message(game_get_character_in_space(game,game_get_player_location(game)));
}

