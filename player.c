/**
 * @brief Implementa el modulo del jugador
 *
 * @file player.c
 * @author Lucia Ordovas
 * @version 0
 * @date 31-01-2025
 * @copyright Licencia Publica GNU
 */

#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Jugador
 *
 * Esta estructura almacena toda la informacion sobre el jugador
 */
struct _Player {
  Id id;                    /*!< ID del jugador, unico */
  char name[WORD_SIZE + 1]; /*!< Nombre del jugador */
  Id location;              /* Ubicacion del jugador */
  Id object;                /* Que objeto tiene el jugador */
  Id health;                /* Puntos de vida del jugador */    
};

/*-----------------------------------------------------------------------------------------------------*/
/* Funciones implementadas*/

/* Creacion e inicializacion de un jugador */
Player* player_create(Id id) {
  Player* newPlayer = NULL;

  /* Control de errores de los parametros */
  if (id == NO_ID) return NULL;

  /* Reserva de memoria dinamica */
  newPlayer = (Player*)malloc(sizeof(Player));
  if (newPlayer == NULL) {
    return NULL;
  }

  /* Inicializacion */
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->object = NO_ID;
  newPlayer->health = INIT_HEALTH;

  return newPlayer;
}
Status player_destroy(Player* player) {
  /*Cde*/
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;
  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
/* Obtenemos el ID del jugador, no cambiamos el ID en ningun modulo, por eso no hay set para el ID*/
Id player_get_id(Player* player) {
  /* Control de errores */
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

/*-----------------------------------------------------------------------------------------------------*/
Status player_set_name(Player* player, char* name) {
  /*Cde*/
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* player_get_name(Player* player) {
  /* Control de errores */
  if (!player) {
    return NULL;
  }
  return player->name;
}

/*-----------------------------------------------------------------------------------------------------*/
Status player_set_object(Player* player, Id value) {
  /* Control de errores */
  if (!player) {
    return ERROR;
  }

  player->object = value;
  return OK;
}

Id player_get_object(Player* player) {
  /* Control de errores */
  if (!player) {
    return NO_ID;
  }
  return player->object;
}

/*-----------------------------------------------------------------------------------------------------*/
Status player_set_location(Player* player, Id value) {
  /* Control de errores */
  if (!player) {
    return ERROR;
  }

  player->location = value;
  return OK;
}

Id player_get_location(Player* player) {
  /* Control de errores */
  if (!player) {
    return NO_ID;
  }
  return player->location;
}

/*-----------------------------------------------------------------------------------------------------*/
Status player_set_health(Player *player, long value){
  /* Cde */
  if(!player||value<0){
    return ERROR;
  }

  player->health=value;

  return OK;
}

long player_get_health(Player *player){
  /* Cde */
  if(!player||player->health<0){
    return -1;
  }

  return player->health;
}

/*-----------------------------------------------------------------------------------------------------*/
Status player_decrease_health(Player *player) {
  /* Cde */
  if (!player || player->health <= 0) {
    return ERROR;
  }

  player->health--;

  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/
Status player_print(Player* player) {
  /* Control de errores */
  if (!player) {
    return ERROR;
  }

  /* Mostramos el nombre, ubicacion y objeto del jugador */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld; Object: %ld, Health: %ld)\n", player->id, player->name, player->location, player->object, player->health);

  return OK;
}