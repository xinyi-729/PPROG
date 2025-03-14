/**
 * @brief Define la interfaz del modulo space
 *
 * @file space.h
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

typedef struct _Space Space;

/**
  * @brief Crea un nuevo espacio, reservando memoria e inicializando sus miembros
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param id el numero de identificacion para el nuevo espacio
  * @return un nuevo espacio inicializado
  */
 Space* space_create(Id id);
 
 /**
  * @brief Destruye un espacio, liberando la memoria reservada
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio que debe ser destruido
  * @return OK, si todo sale bien, o ERROR si hubo algun problema
  */
 Status space_destroy(Space* space);
 
 /**
  * @brief Obtiene el id de un espacio
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @return el id del espacio
  */
 Id space_get_id(Space* space);
 
 /**
  * @brief Establece el nombre de un espacio
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @param name una cadena de texto con el nombre a almacenar
  * @return OK, si todo sale bien, o ERROR si hubo algun problema
  */
 Status space_set_name(Space* space, char* name);

/**
  * @brief Obtiene el nombre de un espacio
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @return una cadena de texto con el nombre del espacio
  */
 const char* space_get_name(Space* space);
 
 /**
  * @brief Establece el id del espacio ubicado al norte
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @param id el numero de id del espacio ubicado al norte
  * @return OK, si todo sale bien, o ERROR si hubo algun problema
  */
 Status space_set_north(Space* space, Id id);
 
 /**
  * @brief Obtiene el id del espacio ubicado al norte
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @return el numero de id del espacio ubicado al norte
  */
 Id space_get_north(Space* space);
 
 /**
  * @brief Establece el id del espacio ubicado al sur
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @param id el numero de id del espacio ubicado al sur
  * @return OK, si todo sale bien, o ERROR si hubo algun problema
  */
 Status space_set_south(Space* space, Id id);

/**
  * @brief Obtiene el id del espacio ubicado al sur
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @return el numero de id del espacio ubicado al sur
  */
 Id space_get_south(Space* space);
 
 /**
  * @brief Establece el id del espacio ubicado al este
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @param id el numero de id del espacio ubicado al este
  * @return OK, si todo sale bien, o ERROR si hubo algun problema
  */
 Status space_set_east(Space* space, Id id);
 
 /**
  * @brief Obtiene el id del espacio ubicado al este
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @return el numero de id del espacio ubicado al este
  */
 Id space_get_east(Space* space);
 
 /**
  * @brief Establece el id del espacio ubicado al oeste
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @param id el numero de id del espacio ubicado al oeste
  * @return OK, si todo sale bien, o ERROR si hubo algun problema
  */
 Status space_set_west(Space* space, Id id);
 

/**
  * @brief Obtiene el id del espacio ubicado al oeste
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param space un puntero al espacio
  * @return el numero de id del espacio ubicado al oeste
  */
 Id space_get_west(Space* space);

/**
  * @brief Comprueba si el espacio tiene un objeto o no
  * @author Xinyi Huang
  *
  * @param space un puntero al espacio
  * @param id el id del objeto
  * @return TRUE si el espacio tiene el objeto, FALSE en caso contrario
  */
 Bool space_has_object(Space *space, Id id);

 /**
 * @brief Añade un objeto al espacio
 * @author Xinyi Huang
 *
 * @param space un puntero a espacio
 * @param id variable tipo Id, identificador del objeto
 * @return OK, si todo fue bien o ERROR si hubo algún problema
 */
Status space_add_object(Space *space, Id id);       

/**
 * @brief Elimina un objeto del espacio.
 * @author Xinyi Huang
 *
 * @param space un puntero a espacio
 * @param id variable tipo Id, identificador del objeto
 * @return OK, si todo fue bien o ERROR si hubo algún problema
 */
Status space_del_object(Space *space, Id id);

/**
 * @brief Consigue el set del espacio
 * @author Xinyi Huang
 *
 * @param space un puntero a espacio
 * @return Devuleve un puntero a set del espacio pasado
 */
Set *space_get_set(Space *space);

/**
 * @brief Consigue el id del personaje 
 * @author Xinyi Huang
 *
 * @param space un puntero a espacio
 * @return Devuleve un puntero a set del espacio pasado
 */
Status space_set_character_id(Space *space, Id id);
Id space_get_character_id(Space *space);

Status space_set_gdesc(Space* space, char *str, int pos);
char* space_get_gdesc(Space* space, int line);

 
 /**
  * @brief Imprime la informacion del espacio
  * @author Xinyi Huang y Lucia Ordovas
  *
  * Esta funcion muestra el id y el nombre del espacio, los espacios que lo rodean y si tiene un objeto o no.
  * @param space un puntero al espacio
  * @return OK, si todo sale bien, o ERROR si hubo algun problema
  */
 Status space_print(Space* space);

 Id space_get_objetc_id_at(Space *space, int pos); 

#endif
