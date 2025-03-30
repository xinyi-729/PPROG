/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author David Buendía
 * @version 1
 * @date 13-02-2025
 * @copyright GNU Public License
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "types.h"

#define MAX_OBJS 5

struct _Player{
Id id;
char name [WORD_SIZE+1];
Id player_location;
int health;
Inventory *backpack;
};

Player* player_create (Id id){

  Player* newPlayer = NULL;

  if(id == NO_ID){
  return NULL;
  };

  newPlayer = (Player*)malloc(sizeof(Player));

  if (newPlayer == NULL)
  {
    return NULL;
  };

  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->player_location = NO_ID;
  newPlayer->health = 10;
  newPlayer->backpack = inventory_create(MAX_OBJS);

  return newPlayer;
}

void player_destroy (Player* player)
{
  inventory_destroy(player->backpack);
  free(player);
  player = NULL;
}

Id player_get_id(Player* player){

  if(!player){
    return NO_ID;
  }

  return player->id;
}


char* player_get_name(Player* player){

  if(!player){
    return NULL;
  }

  return player->name;
}

Status player_set_name(Player* player, char* name){
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}

Id player_get_location(Player* player){
  if (player == NULL){
    return NO_ID;
  }
  
  return player->player_location;
}

Status player_set_location(Player* player, Id id){
  if (player == NULL|| id == NO_ID){
    return ERROR;
  }
  
  player->player_location = id;
  return OK;
}

int player_get_health(Player *player)
{
  if (player == NULL)
  {
    return -1;
  }

  return player->health;
}

Status player_set_health(Player *player, int hp)
{
  if (player == NULL || hp < 0)
  {
    return ERROR;
  }

  player->health = hp;
  return OK;
}

Inventory *player_get_backpack(Player *player){
  if (player == NULL){
    return NULL;
  }
  
  return player->backpack;
}

Status player_del_object(Player *player, Id id){

  if(player == NULL || id == NO_ID){
    return ERROR;
  }

  if(inventory_del(player->backpack, id) == ERROR){
    return ERROR;
  }

  return OK;
}

Status player_add_object(Player* player, Id id){
  if (player == NULL){
    return ERROR;
  }
  
  if(inventory_add(player->backpack, id) == ERROR){
    return ERROR;
  }

  return OK;
}

Bool player_has_object(Player *player, Id id){

  return inventory_has_object(player->backpack, id);
}

Bool player_backpack_is_full(Player *player){

  if (player == NULL)
  {
    return TRUE;
  }
  
  return inventory_is_full(player->backpack);
}

Bool player_backpack_is_empty(Player *player){

  if (player == NULL)
  {
    return TRUE;
  }
  
  return inventory_is_empty(player->backpack);
}

Status player_print(const Player* player) {
  if (!player) return ERROR;
  printf("Player ID: %ld, Name: %s, Location: %ld", player->id, player->name, player->player_location);
  printf("Player Objects: ");
  inventory_print(player->backpack);
  return OK;
}

