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