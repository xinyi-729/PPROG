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


// Status game_reader_load_character(Game *game, char*filename);
Status game_reader_load_links(Game *game, char*filename);

/*----------------------------------------------------------------*/

Status game_create_from_file(Game *game, char *filename) {
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_reader_load_spaces(game, filename) == ERROR ) {
    return ERROR;
  }

  if (game_reader_load_objects(game, filename) == ERROR ) {
    return ERROR;
  }
  if(game_reader_load_links(game, filename) == ERROR){
    return ERROR;
  }

  /* El jugador estan en el primer espacio */
  game_set_player_location(game, game_get_space_id_at(game, 0));

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
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld\n", id, obj_name, location);
#endif
      /* Creamos el objeto a partir del fichero */
      object = object_create(id);
      if (object != NULL) {
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

// Status game_reader_load_character(Game *game, char*filename){
  
// }



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
