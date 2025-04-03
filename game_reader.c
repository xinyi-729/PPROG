/**
 * @brief It defines the game reader interface
 *
 * @file game_reader.h
 * @author Alejandro Fernández
 * @version 1
 * @date 04-03-2025
 * @copyright GNU Public License
 */

 #include "game_reader.h"

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 #define FRIENDLY_ID 1

/*------PRIVATE FUNCTIONS BECAUSE WE DONT USE IT IN OTHERS FILES--------*/
/**
 * @brief It loads the spaces and its graphic description from a file
 * @author Profesores PPROG
 *
 * @param game a pointer to the game 
 * @param filename a pointer to the file name
 * @return status (OK), if everything goes well or ERROR if there was some mistake
*/
Status game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief It loads the objects from a file
 * @author Profesores PPROG
 *
 * @param game a pointer to the game 
 * @param filename a pointer to the file name
 * @return status (OK), if everything goes well or ERROR if there was some mistake
*/
Status game_reader_load_objects(Game* game, char *filename);

/**
 * @brief It loads the players from a file
 * @author Ana Maria
 *
 * @param game a pointer to the game 
 * @param filename a pointer to the file name
 * @return status (OK), if everything goes well or ERROR if there was some mistake
*/
Status game_reader_load_players(Game *game, char *filename);
/**
 * @brief It loads the characters from a file
 * @author Ana Maria
 *
 * @param game a pointer to the game 
 * @param filename a pointer to the file name
 * @return status (OK), if everything goes well or ERROR if there was some mistake
*/
Status game_reader_load_character(Game *game, char*filename);
/**
 * @brief It loads the links from a file
 * @author Ana Maria
 *
 * @param game a pointer to the game 
 * @param filename a pointer to the file name
 * @return status (OK), if everything goes well or ERROR if there was some mistake
*/
Status game_reader_load_links(Game *game, char*filename);

/*----------------------------------------------------------------*/

Status game_create_from_file(Game *game, char *filename) {

  if (game_reader_load_spaces(game, filename) == ERROR ) {
    return ERROR;
  }

  if (game_reader_load_objects(game, filename) == ERROR ) {
    return ERROR;
  }

  if(game_reader_load_links(game, filename) == ERROR){
    return ERROR;
  }
  if(game_reader_load_character(game, filename) == ERROR){
    return ERROR;
  }

  if(game_reader_load_players(game,filename)==ERROR){
    return ERROR;
  }

  return OK;
}


Status game_reader_load_objects(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char obj_name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object *object = NULL;
  Status status = OK;
  char gdesc[GDESC_SIZE] = "";

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(obj_name, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc, toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, obj_name, location);
#endif
      /* Creamos el objeto a partir del fichero */
      object = object_create(id);
      if (object != NULL) {
        object_set_description(object,gdesc);
        object_set_name(object, obj_name);
        space_add_object(game_get_space(game,location), id);
        game_add_object(game, object);
      }

    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

Status game_reader_load_spaces(Game *game, char *filename)
{
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID;
  Space *space = NULL;
  Status status = OK;
  char gdescaux[GDESC_ROWS][GDESC_COLS];
  int i;

  if (!filename)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file))
  {
    if (strncmp("#s:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      for (i = 0; i < GDESC_ROWS; i++)
      {
        toks = strtok(NULL, "|");
        if (toks)
        {
          strcpy(gdescaux[i], toks);
        }

      }
    

#ifdef DEBUG
    printf("Leido: %ld|%s|%s|%s|%s|%s|%s\n", id, name, gdescaux[0], gdescaux[1],gdescaux[2], gdescaux[3], gdescaux[4]) ;
#endif
      space = space_create(id);
      if (space != NULL)
      {
        space_set_name(space, name);

        for (i = 0; i < GDESC_ROWS; i++)
        {
          space_set_gdesc(space, gdescaux[i], i);
        }
        game_add_space(game, space);
        
        
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);

  return status;
}

Status game_reader_load_character(Game *game, char*filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char gdesc[GDESC_SIZE] = "", message[WORD_SIZE] = "";
  char *toks = NULL;
  Id id= NO_ID, location = NO_ID;
  Character *c= NULL;
  Status status = OK;
  int health;
  Bool friend;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#c:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
      friend = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(message,toks);

#ifdef DEBUG
      printf("Leido: %ld|%s|%s|%ld|%d|%d|%s\n", id, name, gdesc, location,health, friend,message);
#endif
      c = character_create(id);
      if (c != NULL) {
        character_set_name(c,name);
        character_set_graphic_description(c, gdesc);
        character_set_health(c,health);
        character_set_friend(c, friend);
        character_set_message(c,message);
        space_set_character_id(game_get_space(game, location), id);
        game_add_character(game, c);
      }

    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}



Status game_reader_load_links(Game *game, char*filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, origen= NO_ID, destino =NO_ID;
  Direction dir=NOTKNOWN;
  link *link = NULL;
  Status status = OK;
  Bool open;

  if(!game || !filename){
    return ERROR;
  }
  file = fopen(filename, "r");
  if (file == NULL)
  {
    return ERROR;
  }
  

  while (fgets(line, WORD_SIZE, file))
  {

    if (strncmp("#l:", line, 3) == 0)
    {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      origen = atol(toks);
      toks = strtok(NULL, "|");
      destino = atol(toks);
      toks = strtok(NULL, "|");
      dir = atol(toks);
      toks = strtok(NULL, "|");
      open = atol(toks);


#ifdef DEBUG
    printf("Leido: %ld|%s|%ld|%ld|%d|%d\n", id, name, origen, destino, dir, open) ;
#endif
      link = link_create(id);
      if (link != NULL){
        link_set_name(link, name);
        link_set_originID(link, origen);
        link_set_destID(link,destino);
        link_set_direction(link, dir);
        link_set_open(link, open);

        game_add_link(game, link);
      }
    }
  }

  if (ferror(file))
  {
    status = ERROR;
  }

  fclose(file);
  return status;

}

Status game_reader_load_players(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char player_name[WORD_SIZE] = "";
  char player_desc[WORD_SIZE] = "";
  char *toks = NULL;
  int health,objects;
  Id id = NO_ID, location = NO_ID;
  Player *player  = NULL;
  Status status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#p:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(player_name, toks);
      toks = strtok(NULL, "|");
      strcpy(player_desc, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      health = atol(toks);
      toks = strtok(NULL, "|");
      objects = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%s|%ld|%d|%d\n", id, player_name, player_desc,location,health,objects);
#endif
      /* Creamos el jugador a partir del fichero */
      player = player_create(id);
      if (player != NULL) {
        player_set_health(player, health);
        player_set_location(player, location);
        player_set_name(player,player_name);
       
       
       player_set_graphic_description(player, player_desc);
        
        
        
        inventory_set_max_objs(player_get_backpack(player),objects);

        /*hacer un game add player ya q ahora hay mas de uno como pasaba con los objetos en la anterior*/
        game_add_player(game,player);
      }

    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}
