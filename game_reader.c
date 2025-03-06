/**
 * @brief Define el lector de juegos
 *
 * @file game_reader.c
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 31-01-2025
 * @copyright GNU Public License
 */
#include "game_reader.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*-----------------------------------------------------------------------------------------------------*/
Status game_create_from_file(Game *game, char *filename) {
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_load_spaces(game, filename) == ERROR) {
    return ERROR;
  }

  /* El jugador y el objeto estan en el primer espacio */
  game_set_player_location(game, game_get_space_id_at(game, 0));

  return OK;
}

/*-----------------------------------------------------------------------------------------------------*/

Status game_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  Status status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

/*---------------------------------------------------------------------*/
Status game_load_objects(Game *game, char *filename) {
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
        game_add_object(game, object);
        game_set_object_location(game, location);

      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

