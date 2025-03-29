/**
 * @brief It implements the character module
 *
 * @file character.c
 * @author David Buendía
 * @version 1
 * @date 13-02-2025
 * @copyright GNU Public License
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include "character.h"

 #define GDESC_SIZE 6


struct _Character
{
  Id id;
  char name[WORD_SIZE + 1];
  char gdesc[GDESC_SIZE + 1];
  int health;
  Bool friend;
  char message[WORD_SIZE+1];
};

Character *character_create(Id id)
{

  Character *newcharacter = NULL;

  if (id == NO_ID)
  {
    return NULL;
  }

  newcharacter = (Character *)malloc(sizeof(Character));
  if (newcharacter == NULL) 
  {
    return NULL;
  }
  
  newcharacter->id = id;
  newcharacter->name[0] = '\0';
  newcharacter->gdesc[0] = '\0';
  newcharacter->health = 5;
  newcharacter->message[0] = '\0';
  newcharacter->friend = TRUE;

  return newcharacter;
}

void character_destroy(Character *character)
{
  if(!character)
    return;

  free(character);
  character = NULL;
}

Id character_get_id(Character *character)
{

  if (!character)
  {
    return NO_ID;
  }

  return character->id;
}

/*Esta funcion no se necesita porque el id es únido e inmodificable*/
// Status character_set_id(character *character, Id id)
// {
//   if (!character || id == NO_ID)
//   {
//     return ERROR;
//   }

//   character->id = id;

//   return OK;
// }

char *character_get_name(Character *character)
{

  if (!character)
  {
    return NULL;
  }

  return character->name;
}

Status character_set_name(Character *character, char *name)
{
  if (!character || !name)
  {
    return ERROR;
  }

  if (!strcpy(character->name, name))
  {
    return ERROR;
  }
  return OK;
}

char *character_get_graphic_description(Character *character)
{
  if (character == NULL)
  {
    return NULL;
  }

  return character->gdesc;
}

Status character_set_graphic_description(Character *character, char *gdesc)
{
  if (!character || !gdesc || strlen(gdesc) > 6)/*El mayor q 6?*/
  {
    return ERROR;
  }

  if (!strcpy(character->gdesc, gdesc))
  {
    return ERROR;
  }
  return OK;
}

int character_get_health(Character *character)
{
  if (character == NULL)
  {
    return -1;
  }

  return character->health;
}

Status character_set_health(Character *character, int hp)
{
  if (character == NULL || hp < 0)
  {
    return ERROR;
  }

  character->health = hp;
  return OK;
}

Bool character_get_friend(Character *character)
{
  if (character == NULL)
  {
    return ERR;
  }

  return character->friend;
}

Status character_set_friend(Character *character, Bool typ)
{
  if (character == NULL)
  {
    return ERROR;
  }

  character->friend = typ;
  return OK;
}

char *character_get_message(Character *character)
{
  if (character == NULL)
  {
    return NULL;
  }

  return character->message;
}

Status character_set_message(Character *character, char *msg)
{
  if (!character || !msg || strlen(msg) > WORD_SIZE)
  {
    return ERROR;
  }

  if (!strcpy(character->message, msg))
  {
    return ERROR;
  }
  return OK;
}

Status character_print(const Character *character)
{
  char friend[7];

  if (!character)
    return ERROR;

  if (character->friend == TRUE)
  {
    strcpy(friend, "Friend");
  }
  else
  {
    strcpy(friend, "Enemy");
  }

  printf("character ID: %ld, Name: %s, Graphic Description: %s, Health %d, friend: %s, Message: %s\n", character->id, character->name, character->gdesc, character->health, friend, character->message);
  return OK;
}