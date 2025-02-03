/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author Xinyi Huang and Lucía Ordovás
 * @version 0
 * @date 31-01-2025
 * @copyright GNU Public License
 */

#include "player.h"
#include "space.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Player
 *
 * This structure stores all the information about the player
 */
struct _Player {
  Id id;                    /*!< Player ID, unique */
  char name[WORD_SIZE + 1]; /*!< Player name */
  Id location;             /*!< El espacio en el que se sitúa player*/
  Id object;                /*!< El id del objeto */
};

/** player_create allocates memory for a new player and initializes its elements */
Player* player_create(Id id) {
  Player* newPlayer = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  /* Memory allocation */
  newPlayer = (Player*)malloc(sizeof(Player));
  if (newPlayer == NULL) {
    return NULL;
  }

  /* Initialization of an empty player */
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = 11;
  newPlayer->object = NO_ID;

  return newPlayer;
}

Status player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;
  return OK;
}

Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

Status player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}
/************** */
Status player_set_object(Player* player, Id obj) {
  if (!player) {
    return ERROR;
  }
  player->object = obj;
  return OK;
}

Bool player_get_object(Player* player) {
  if (!player) {
    return FALSE;
  }
  return player->object;
}

Status player_print(Player* player) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the player */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);


  /* 3. Print if there is an object in the player or not */
  if (player_get_object(player)) {
    fprintf(stdout, "---> Object in the player.\n");
  } else {
    fprintf(stdout, "---> No object in the player.\n");
  }

  return OK;
}
