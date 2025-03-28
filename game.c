/**
 * @brief It implements the game structure
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 2
 * @date 7-03-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_reader.h"
#include "game.h"



#define PLAYERID 1            /*The id of the player*/
#define FRIENDLYCHARACTERID 2 /*The id of the friendly character*/
#define ENEMYCHARACTERID 3    /*The id of the hostile character*/

/**
 * @brief Game
 *
 * This struct stores the information of the player and object location, the spaces,
 * the number of spaces, the last command given by the user and if the game is finished or not.
 */
struct _Game
{
  Player *player;
  Object *object[MAX_OBJECTS];
  Character *character[MAX_CHARACTERS];
  Space *spaces[MAX_SPACES];
  int n_spaces;
  int n_objects;
  int n_characters;
  Command *last_cmd;
  Bool finished;
  link *links[MAX_LINKS];
  int n_links;
};

/**
   Game interface implementation
*/

Game *game_create()
{
  int i;
  Game *newGame = NULL;

  newGame = (Game *)malloc(sizeof(Game));
  if (newGame == NULL)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES; i++)
  {
    newGame->spaces[i] = NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++)
  {
    newGame->object[i] = NULL;
  }

  for (i = 0; i < MAX_CHARACTERS; i++)
  {
    newGame->character[i] = NULL;
  }

  newGame->n_spaces = 0;
  newGame->n_objects = 0;
  newGame->n_characters = 0;
  newGame->player = player_create(729);
  newGame->last_cmd = command_create();
  newGame->finished = FALSE;

  return newGame;
}

Status game_destroy(Game *game)
{
  int i = 0;

  if (!game)
    return ERROR;

  for (i = 0; i < game->n_spaces; i++)
  {
    space_destroy(game->spaces[i]);
  }

  command_destroy(game->last_cmd);

  for (i = 0; i < game->n_objects; i++)
  {
    object_destroy(game->object[i]);
  }

  for (i = 0; i < game->n_characters; i++)
  {
    character_destroy(game->character[i]);
  }

  player_destroy(game->player);
  free(game);
  game = NULL;
  return OK;
}

Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID || game == NULL)
  {
    return NULL;
  }

  for (i = 0; i < game->n_spaces; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

Id game_get_player_location(Game *game)
{
  if (game == NULL)
  {
    return NO_ID;
  }
  return player_get_location(game->player);
}

Status game_set_player_location(Game *game, Id id)
{
  if (game == NULL || id == NO_ID)
  {
    return ERROR;
  }

  return player_set_location(game->player, id);
}

/*ESTAS DOS FUNCIONES SE QUITAN*/
// Set *game_get_objects_location(Game *game, Id id)
// {

//   Space *space = NULL;
//   if (game == NULL || id == NO_ID)
//   {
//     return NULL;
//   }

//   space = game_get_space(game, id);

//   return space_get_object(space);
// }

// Status game_set_object_location(Game *game, Id id)
// {
//   Space *space = NULL;
//   if (game == NULL)
//   {
//     return ERROR;
//   }

//   space = game_get_space(game, id);
//   space_set_object(space, id);

//   return OK;
// }

Command *game_get_last_command(Game *game)
{
  if (!game)
    return NULL;
  return game->last_cmd;
}

Status game_set_last_command(Game *game, Command *command)
{
  game->last_cmd = command;

  return OK;
}

Bool game_get_finished(Game *game) { return game->finished; }

Status game_set_finished(Game *game, Bool finished)
{
  game->finished = finished;

  return OK;
}

void game_print(Game *game)
{
  int i;

  printf("\n\n-------------\n\n");

  printf("=> Espacios: \n");
  for (i = 0; i < game->n_spaces; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Jugador: ");
  if (game->player)
  {
    player_print(game->player);
  }
  else
  {
    printf("No se ha asignado un jugador.\n");
  }

  printf("=> Objetos: \n");
  for (i = 0; i < game->n_objects; i++)
  {
    object_print(game->object[i]);
  }
}

Status game_add_space(Game *game, Space *space)
{
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES))
  {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}

Player *game_get_player(Game *game)
{
  if (game == NULL)
  {
    return NULL;
  }

  return game->player;
}

Character *game_get_character(Game *game, Id id)
{
  int i;
  if (game == NULL || id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < game->n_characters; i++)
  {
    if (character_get_id(game->character[i]) == id)
    {
      return game->character[i];
    }
  }

  return NULL;
}

Status game_add_object(Game *game, Object *object)
{

  if (game == NULL || game->n_objects >= MAX_OBJECTS)
  {
    return ERROR;
  }

  game->object[game->n_objects] = object;
  game->n_objects++;

  return OK;
}

Status game_add_character(Game *game, Character *character)
{

  if (game == NULL || game->n_characters >= MAX_CHARACTERS)
  {
    return ERROR;
  }

  game->character[game->n_characters] = character;
  game->n_characters++;

  return OK;
}

int game_get_numspaces(Game *game)
{
  if (game == NULL)
  {
    return -1;
  }

  return game->n_spaces;
}

Id game_get_space_id_at(Game *game, int position)
{
  if (position < 0 || position >= game->n_spaces)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

char *game_get_object_name(Game *game, Id id)
{

  int i;
  if (game == NULL || id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < game->n_objects; i++)
  {
    if (object_get_id(game->object[i]) == id)
    {
      return object_get_name(game->object[i]);
    }
  }

  return NULL;
}
/*----NEWS--- */
Id game_get_object_id(Game *game, char *obj_name)
{
  int i;
  char *n = NULL;
  if (!game || !obj_name)
    return NO_ID;

  /*Busca en la lista de objetos, si lo encuentra, retorna su id*/
  for (i = 0; i < game->n_objects; i++)
  {
    n = object_get_name(game->object[i]);
    if (strcmp(n, obj_name) == 0)
    {
      return object_get_id(game->object[i]);
    }
  }
  return NO_ID;
}

Space *game_get_space_at(Game *game, int position)
{
  if (game == NULL || position < 0 || position >= game->n_spaces)
  {
    return NULL;
  }



  return game->spaces[position];
}

Id game_get_object_id_at(Game *game, int position)
{
  if (game == NULL || position < 0 || position >= game->n_objects)
  {
    return NO_ID;
  }

  return object_get_id(game->object[position]);
}

int game_get_numobj(Game *game)
{
  if (!game)
    return -1;

  return game->n_objects;
}

Object *game_get_object(Game *game, Id id)
{
  int i;

  if (!game || id == NO_ID)
    return NULL;

  for (i = 0; i < game->n_objects; i++)
  {
    if (id == object_get_id(game->object[i]))
      return game->object[i];
  }

  return NULL;
}

Character *game_get_character_in_space(Game *game, Id space_id)
{
  int character_id, i, j;

  if (!game || space_id == NO_ID)
  {
    return NULL;
  }

  /* Primero encuentro el TAD del espacio con ese ID */
  for (i = 0; i < game->n_spaces; i++)
  {
    if (space_get_id(game->spaces[i]) == space_id)
    {
      character_id = space_get_character_id(game->spaces[i]);
      if (character_id == NO_ID)
      {
        return NULL;
      }

      /* Ahora encuentro el TAD del character con el ID que busco */
      for (j = 0; j < MAX_CHARACTERS; j++)
      {
        if (character_get_id(game->character[j]) == character_id)
        {
          return game->character[j];
        }
      }
    }
  }

  return NULL;
}

char *game_get_message(Game *game)
{
  if (!game)
    return NULL;

  return character_get_message(game_get_character_in_space(game, game_get_player_location(game)));
}

char *game_get_object_description(Game *game, char *obj_name){
  if(!game || !obj_name) return NULL;

  return object_get_description(game_get_object(game, game_get_object_id(game, obj_name)));
}
/*--------------nuevas------------*/

link *game_get_link(Game *game, Id id_link){
  int i;
  if(!game || id_link == NO_ID)
    return NULL;

  for(i=0; i<game->n_links; i++){
    if(link_get_id(game->links[i]) == id_link){
      return game->links[i];
    }
  }

  return NULL;
}

// Status game_set_link(Game *game, link *link){

// }

Id game_get_connection(Game *game, Id space_act, Direction dir){
  int i;
  if(!game || space_act==NO_ID || dir == NOTKNOWN)
    return  NO_ID;

  for(i=0; i<game->n_links; i++){
    if(link_get_originID(game->links[i]) == space_act && link_get_direction(game->links[i]) == dir){
      return link_get_destID(game->links[i]);
    }
  }
  return NO_ID;
}

Bool game_connection_is_open(Game *game, Id space_act, Direction dir ){
  int i;

  for(i=0; i<game->n_links; i++){
    if(link_get_originID(game->links[i]) == space_act && link_get_direction(game->links[i]) == dir){
      return link_is_open(game->links[i]);
    }
  }

  return FALSE; /*cerrado*/
}

Status game_add_link(Game *game, link *link){
  if(!game || !link || game->n_links>=MAX_LINKS)
    return ERROR;
  game->links[game->n_links] = link;
  game->n_links++;

  return OK;
}