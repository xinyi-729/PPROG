/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1
 * @date 12-02-2025
 * @copyright GNU Public License
 */

#include "space.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space
{
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Set *objects;             /*!< Whether the space has an object or not */
  Id character;             /*!< Id of the character in the space or NO_ID if theres no character */
  char gdesc[GDESC_ROWS][GDESC_COLS]; /*!< The graphic description of the space */
};

/** space_create allocates memory for a new space
 *  and initializes its members
 */
Space *space_create(Id id)
{
  Space *newSpace = NULL;
  int i;

  /* Error control */
  if (id == NO_ID)
    return NULL;

  newSpace = (Space *)malloc(sizeof(Space));
  if (newSpace == NULL)
  {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->objects = set_create();

  for (i = 0; i < GDESC_ROWS; i++)
  {
    strcpy(newSpace->gdesc[i], "         ");
  }

  newSpace->character = NO_ID;
  return newSpace;
}

Status space_destroy(Space *space)
{
  if (!space)
  {
    return ERROR;
  }

  set_destroy(space->objects);
  free(space);
  space = NULL;
  return OK;
}

Id space_get_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }
  return space->id;
}

Status space_set_name(Space *space, char *name)
{
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }
  return OK;
}

const char *space_get_name(Space *space)
{
  if (!space)
  {
    return NULL;
  }
  return space->name;
}


/*set_object ahora se llama add_obj*/
Status space_add_object(Space *space, Id id)
{
  if (!space)
  {
    return ERROR;
  }

  if (set_add(space->objects, id) == ERROR)
  {
    return ERROR;
  };

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

Set *space_get_object(Space *space)
{
  if (!space)
  {
    return NULL;
  }

  return space->objects;
}

Id space_get_character_id(Space *space)
{
  if (!space)
  {
    return NO_ID;
  }

  return space->character;
}

Status space_set_character_id(Space *space, Id id)
{
  if (!space)
  {
    return ERROR;
  }

  space->character = id;

  return OK;
}

char *space_get_gdesc(Space *space, int row)
{
  if (space == NULL || row < 0)
  {
    return NULL;
  }

  return space->gdesc[row];
}

Status space_set_gdesc(Space *space, char *gdesc, int row)
{
  if (space == NULL || gdesc == NULL)
  {
    return ERROR;
  }

  strcpy(space->gdesc[row], gdesc);
  return OK;
}

Status space_print(Space *space)
{
  Id idaux = NO_ID;
  int i;

  /* Error Control */
  if (!space)
  {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  // /* 2. For each direction, print its link */
  // idaux = space_get_north(space);
  // if (idaux != NO_ID)
  // {
  //   fprintf(stdout, "---> North link: %ld.\n", idaux);
  // }
  // else
  // {
  //   fprintf(stdout, "---> No north link.\n");
  // }
  // idaux = space_get_south(space);
  // if (idaux != NO_ID)
  // {
  //   fprintf(stdout, "---> South link: %ld.\n", idaux);
  // }
  // else
  // {
  //   fprintf(stdout, "---> No south link.\n");
  // }
  // idaux = space_get_east(space);
  // if (idaux != NO_ID)
  // {
  //   fprintf(stdout, "---> East link: %ld.\n", idaux);
  // }
  // else
  // {
  //   fprintf(stdout, "---> No east link.\n");
  // }
  // idaux = space_get_west(space);
  // if (idaux != NO_ID)
  // {
  //   fprintf(stdout, "---> West link: %ld.\n", idaux);
  // }
  // else
  // {
  //   fprintf(stdout, "---> No west link.\n");
  // }

  /* 3. Print if there is an object in the space or not */
  if (space_get_object(space))
  {

    fprintf(stdout, "---> Objects in the space: \n");
    set_print(space->objects);
  }
  else
  {
    fprintf(stdout, "---> No objects in the space.\n");
  }

  fprintf(stdout, "--> Description:\n");
  for (i = 0; i < GDESC_ROWS; i++)
  {
    if (space_get_gdesc(space, i) != NULL)
    {
      fprintf(stdout, "%s\n", space->gdesc[i]);
    }
    else
    {
      fprintf(stdout, "         ");
    }
  }

  return OK;
}

Id space_get_objetc_id_at(Space *space, int pos){
  Set *set=NULL;

  if(!space || pos<0){
    return NO_ID;
  }

  set = space_get_object(space);
  if(!set)
    return NO_ID;

  if(pos >= set_get_n_ids(set))
    return NO_ID;


  return set_get_id(set, pos);
}

Bool space_has_object(Space *space, Id id){
  
  if(set_has(space->objects,id) == TRUE)
    return TRUE;
    
  return FALSE;

}

