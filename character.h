#ifndef CHARACTER_H
#define CHARACTER_H

/**
 * @brief Define la interfaz del modulo del caracter
 *
 * @file caracter.h
 * @author Lucia Ordovas
 * @version 0
 * @date 31-01-2025
 * @copyright Licencia Publica GNU
*/
 
#include "types.h"
 
typedef struct _Character Character;
 
/**
  * @brief Crea un nuevo caracter, reservando memoria e inicializando sus miembros
  * @author Lucia Ordovas
  *
  * @param id el numero de identificacion para el nuevo caracter
  * @return un nuevo caracter inicializado
*/
Character* character_create(Id id);

Status character_destroy(Character* character);

Id character_get_id(Character* character) ;

Status character_set_name(Character* character, char* name) ;

char* character_get_name(Character* character) ;

Status character_set_description(Character* character, char* gdesc);

const char* character_get_description(Character* character) ;
Status character_set_health(Character *character, long value);
long character_get_health(Character *character);
Status character_set_is_friendly(Character *character, Bool value);
Bool character_get_is_friendly(Character *character);
Status character_set_message(Character *character, char *message);
char * character_get_message(Character *character);
Status character_print(Character *character);



#endif