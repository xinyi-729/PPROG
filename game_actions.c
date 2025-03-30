/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1
 * @date 13-02-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"
#include "space.h"
#include "player.h"
#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

void game_actions_unknown(Game *game);

void game_actions_exit(Game *game);

/**
 * @brief It take an especific object in the same space
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @return OK if everything goes well or ERROR if there was some mistake
 */
Status game_actions_take(Game *game);

/**
 * @brief It drops the object to the actual space
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @return OK if everything goes well or ERROR if there was some mistake
 */
Status game_actions_drop(Game *game);

/**
 * @brief It attacks an enemy character
 * @author David Buendía
 *
 * @param game a pointer to the game
 * @return OK if everything goes well or ERROR if there was some mistake
 */
Status game_actions_attack(Game *game);

/**
 * @brief It chats with a friendly character
 * @author David Buendía
 *
 * @param game a pointer to the game
 * @return OK if everything goes well or ERROR if there was some mistake
 */
Status game_actions_chat(Game *game);

/**
 * @brief It inspects a specific object from the description
 * @author Lucía Ordovás
 *
 * @param game a pointer to the game
 * @return OK if everything goes well or ERROR if there was some mistake
 */
char* game_actions_inspect(Game *game);



void game_actions_move(Game *game);



Status game_actions_update(Game *game, Command *command)
{
  CommandCode cmd;

  game_set_last_command(game, command);

  cmd = command_get_code(command);

  switch (cmd)
  {
  case UNKNOWN:
    game_actions_unknown(game);
    break;

  case EXIT:
    game_actions_exit(game);
    break;

  case MOVE:
    game_actions_move(game);
    break;

  case TAKE:
    game_actions_take(game);
    break;

  case DROP:
    game_actions_drop(game);
    break;

  case ATTACK:
    game_actions_attack(game);

  case CHAT:
    game_actions_chat(game);
    break;

  case INSPECT:
    game_actions_inspect(game);
    break;
  
  default:
    break;
  }

  return OK;
}

/**
   Calls implementation for each action

*/

void game_actions_unknown(Game *game)
{
  command_set_exit(game_get_last_command(game), ERROR);
}

void game_actions_exit(Game *game)
{
  command_set_exit(game_get_last_command(game), OK);
}

Status game_actions_take(Game *game)
{
  Id player_space_id = NO_ID;
  Id object_id = NO_ID;
  Space *space = NULL;
  Command *cmd = NULL;
  char *name_obj = NULL;

  if (!game)
    return ERROR;

  player_space_id = game_get_player_location(game);
  if (player_space_id == NO_ID)
    return ERROR;

  if (player_backpack_is_full(game_get_player(game)) == TRUE)
    return ERROR;

  if (!(cmd = game_get_last_command(game)))
    return ERROR;

  name_obj = command_get_argument(cmd);
  if (name_obj == NULL)
  {
    return ERROR;
  }

  if ((object_id = game_get_object_id(game, name_obj)) == NO_ID)
  {
    return ERROR;
  }

  space = game_get_space(game, player_space_id);
  if (!space)
    return ERROR;

  /*Comprobar que si este espacio hay ese objeto*/
  if (space_has_object(space, object_id) == FALSE)
  {
    return ERROR;
  }

  /*Ahora, toca guardar el object en el jugador*/
  if (player_add_object(game_get_player(game), object_id) == ERROR)
    return ERROR;

  /*Como ya hicimos take, el objeto desaparece de ese espacio llamando a space_del_object*/
  if (space_del_object(space, object_id) == ERROR)
    return ERROR;

  return OK;
}

Status game_actions_drop(Game *game)
{
  Space *player_space = NULL;
  Player *player = NULL;
  Id object_id = NO_ID;
  Command *cmd = NULL;
  char *name_obj = NULL;

  if (game == NULL)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }


  player_space = game_get_space(game, game_get_player_location(game));
  if (player_space == NULL)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }

  player = game_get_player(game);
  if (player == NULL || player_backpack_is_empty(player) == TRUE)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }

  if (!(cmd = game_get_last_command(game)))
  return ERROR;

  name_obj = command_get_argument(cmd);
  if (name_obj == NULL)
  {
    return ERROR;
  }

  if ((object_id = game_get_object_id(game, name_obj)) == NO_ID)
  {
    return ERROR;
  }

  if (space_add_object(player_space, object_id) == ERROR)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }

  if (player_del_object(player, object_id) == ERROR)
  {

    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }



  command_set_exit(game_get_last_command(game), OK);
  return OK;
}

Status game_actions_attack(Game *game)
{

  Space *player_space = NULL;
  Character *character = NULL;
  Bool character_friend;
  Player *player = NULL;

  int character_hp;
  int player_hp;

  int variable;

  if (game == NULL)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }

  player_space = game_get_space(game, game_get_player_location(game));
  if (player_space == NULL)
  {
    return ERROR;
  }

  character = game_get_character(game, space_get_character_id(player_space));
  if (character == NULL)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }

  character_hp = character_get_health(character);
  character_friend = character_get_friend(character);
  if (character_hp <= 0 || character_friend == TRUE)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }

  player = game_get_player(game);
  if (player == NULL)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return ERROR;
  }

  player_hp = player_get_health(player);
  if (player_hp <= 0)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    game_set_finished(game, TRUE);
    return ERROR;
  }

  variable = rand() % 10;

  printf("%d", variable);

  if (variable <= 4)
  {
    if (player_set_health(player, player_hp - 1) == ERROR)
    {
      command_set_exit(game_get_last_command(game), OK);
      return ERROR;
    }
    else
    {
      command_set_exit(game_get_last_command(game), OK);
      return OK;
    }
  }
  else
  {
    if (character_set_health(character, character_hp - 1) == ERROR)
    {
      command_set_exit(game_get_last_command(game), OK);
      return ERROR;
    }
    else
    {
      command_set_exit(game_get_last_command(game), OK);
      return OK;
    }
  }

  if (player_get_health(player) <= 0)
  {
    command_set_exit(game_get_last_command(game), OK);
    game_set_finished(game, TRUE);
    return OK;
  }

  command_set_exit(game_get_last_command(game), OK);
  return OK;
}

Status game_actions_chat(Game *game)
{
  Space *player_space = NULL;
  Character *character = NULL;
  Bool character_friend;

  if (game == NULL)
  {
    return ERROR;
  }

  player_space = game_get_space(game, game_get_player_location(game));
  if (player_space == NULL)
  {
    return ERROR;
  }

  character = game_get_character(game, space_get_character_id(player_space));
  if (character == NULL || character_get_id(character) == NO_ID)
  {
    return ERROR;
  }

  character_friend = character_get_friend(character);
  if (character_friend == TRUE)
  {
    command_set_exit(game_get_last_command(game), OK);
    return OK;
  }

  command_set_exit(game_get_last_command(game), ERROR);
  return ERROR;
}

char* game_actions_inspect(Game *game)
{
  Command *cmd = NULL;
  char *name_obj = NULL;

  if (!game)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return NULL;
  }

  /* Obtenemos el ultimo comando */
  if (!(cmd = game_get_last_command(game)))
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return NULL;
  }

  /* Obtenemos el nombre del objeto */
  name_obj = command_get_argument(cmd);
  if (!name_obj)
  {
    command_set_exit(game_get_last_command(game), ERROR);
    return NULL;
  }

  command_set_exit(game_get_last_command(game), OK);

  /* Retornamos la descripcion del objeto a partir de su nombre */
  return game_get_object_description(game, name_obj);
}


void game_actions_move(Game *game){
  Id current_id=NO_ID;
  Id space_id = NO_ID;
  char *arg;
  Direction dir=NOTKNOWN;

  if(!game){
    command_set_exit(game_get_last_command(game), ERROR);
    return ;
  }

  space_id = game_get_player_location(game);
  if(space_id == NO_ID){
    command_set_exit(game_get_last_command(game), ERROR);
    return;
  }

  if((arg = command_get_argument(game_get_last_command(game))) == NULL){
    command_set_exit(game_get_last_command(game), ERROR);
    return;
  }


  /*Para no repetir códigos...*/
  if(strcmp(arg, "n")==0 || strcmp(arg, "north") == 0 ){
    dir = N;
  }
  if(strcmp(arg, "s")==0 || strcmp(arg, "south") == 0 ){
    dir = S;
  }
  if(strcmp(arg, "w")==0 || strcmp(arg, "west") == 0 ){
    dir = W;
  }
  if(strcmp(arg, "e")==0 || strcmp(arg, "east") == 0 ){
    dir = E;
  }

  
  current_id = game_get_connection(game, space_id, dir);
  if(game_connection_is_open(game, space_id, dir) == FALSE){/*SI ESTÁ CERRADO NO PUEDES MOVERTE*/
    command_set_exit(game_get_last_command(game), ERROR);
    return;
  }

  if(current_id != NO_ID)
    game_set_player_location(game,current_id);

  command_set_exit(game_get_last_command(game), OK);
  return;
}


