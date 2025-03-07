/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */
#include "space.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GDESC_LINES 5

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Space
 *
  * Esta estructura almacena toda la informacion de un espacio.
 */
struct _Space {
  Id id;                    /*!< Numero de identificacion del espacio, debe ser unico */
  char name[WORD_SIZE + 1]; /*!< Nombre del espacio */
  Id north;                 /*!< Id del espacio al norte */
  Id south;                 /*!< Id del espacio al sur */
  Id east;                  /*!< Id del espacio al este */
  Id west;                  /*!< Id del espacio al oeste */
  Set *objects;
  Id id_character;
  char gdesc[GDESC_LINES][9+1]; /* Descripcion grafica del espacio */
};

 /** space_create reserva memoria para un nuevo espacio
  *  e inicializa sus miembros
  */
Space* space_create(Id id) {
  Space* newSpace = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newSpace = (Space*)malloc(sizeof(Space));
  if (newSpace == NULL) {
    return NULL;
  }

   /* Inicializacion de un espacio vacio */
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->objects = set_create();
  newSpace->id_character=NO_ID;

  for (int i = 0; i < GDESC_LINES; i++) {
    strcpy(newSpace->gdesc[i], "         ");
  }

  return newSpace;
}

Status space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  set_destroy(space->objects);
  free(space);
  space = NULL;
  return OK;
}
/*-----------------------------------------------------------------------------------------------------*/

Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}
/*-----------------------------------------------------------------------------------------------------*/

Status space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}
/*-----------------------------------------------------------------------------------------------------*/

Status space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

Status space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

Status space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

Status space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}
/*-----------------------------------------------------------------------------------------------------*/
/*NUEVAS*/
Bool space_has_object(Space *space, Id id){
  
  if(set_has(space->objects,id) == TRUE)
    return TRUE;
    
  return FALSE;

}
/*--------------------------------------------------------------------------------------------------------*/

Status space_add_object(Space *space, Id id){
  if(!space || id== NO_ID){
    return ERROR;
  }

  if(set_add(space->objects, id) == ERROR)
    return ERROR;

  return OK;
}

Status space_del_object(Space *space, Id id){
  if(!space || id== NO_ID){
    return ERROR;
  }

  if(set_del(space->objects, id) == ERROR)
    return ERROR;

  return OK;
}

Set *space_get_set(Space *space){
  if(!space)
    return NULL;

  return space->objects;
}

/*-----------------------------------------------------------------------------------------------------*/
Status space_set_character_id(Space *space, Id id){
  if(!space||id==NO_ID){
    return ERROR;
  }

  space->id_character=id;
  return OK;
}

Id space_get_character_id(Space *space){
  if(!space){
    return ERROR;
  }

  return space->id_character;
}

/*--------------------------------------------------------------------------------------------------------*/
Status space_set_gdesc(Space* space, char **gdesc){
  int i;

  if(!space||!*gdesc){
    return ERROR;
  }

  for(i=0 ; i<GDESC_LINES; i++){
    if(!strcpy(space->gdesc[i],gdesc[i])){
      return ERROR;
    }
  }
  return OK;
}

const char* space_get_gdesc(Space* space, int line){
  if(!space){
    return NULL;
  }

  return space->gdesc[line];
}

/*--------------------------------------------------------------------------------------------------------*/

Status space_print(Space* space) {
  Id idaux = NO_ID;
  int i;

  /* Error Control */
  if (!space) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s; Objects(set): ", space->id, space->name);
  for(i=0; i<set_get_n_ids(space->objects); i++){/*Modifiqué esto*/
    set_print(space->objects);
  }
  fprintf(stdout, "\n");


  /* 2. For each direction, print its link */
  idaux = space_get_north(space);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = space_get_east(space);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

    /* Imprimir la descripcion grafica */
    for (int i = 0; i < GDESC_LINES; i++) {
      fprintf(stdout, "%s\n", space->gdesc[i]);
    }
  
  return OK;
}
