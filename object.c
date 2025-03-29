/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Alejandro Fernández
 * @version 1
 * @date 13-02-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"
#include "types.h"

struct _Object
{
  Id id;
  char name[WORD_SIZE + 1];
  char description[WORD_SIZE+1];
};

Object *object_create(Id id)
{

  Object *newObject = NULL;

  if (id == NO_ID)
  {
    return NULL;
  }

  newObject = (Object *)malloc(sizeof(Object));

  if (newObject == NULL)
  {
    return NULL;
  }

  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->description[0] = '\0';

  return newObject;
}

void object_destroy(Object *object)
{
  free(object);
  object = NULL;
}

Id object_get_id(Object *object)
{

  if (!object)
  {
    return NO_ID;
  }

  return object->id;
}

char *object_get_name(Object *object)
{

  if (!object)
  {
    return NULL;
  }

  return object->name;
}

Status object_set_name(Object *object, char *name)
{
  if (!object || !name)
  {
    return ERROR;
  }

  if (!strcpy(object->name, name))
  {
    return ERROR;
  }
  return OK;
}

Status object_print(const Object *object)
{
  if (!object)
    return ERROR;
    
  printf("Object ID: %ld, Name: %s\n", object->id, object->name);
  return OK;
}

Status object_set_description(Object *obj, char *description){
  if(!obj ||!description){
    return ERROR;
  }

  if(strlen(description) > WORD_SIZE){
    return ERROR;
  }

  strcpy(obj->description, description);

  return OK;
}

char * object_get_description(Object *obj){
  if(!obj){
    return ERROR;
  }

  return obj->description;
}