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
   * @brief Verifica si un espacio contiene un objeto específico
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param space un puntero al espacio
   * @param id el id del objeto a verificar
   * @return TRUE si el objeto está presente, FALSE en caso contrario
   */
 Bool space_has_object(Space *space, Id id);

 /**
 * @brief Añade un objeto al espacio
 * @author Xinyi Huang y Lucio Ordovas
 *
 * @param space un puntero a espacio
 * @param id variable tipo Id, identificador del objeto
 * @return OK, si todo fue bien o ERROR si hubo algún problema
 */
Status space_add_object(Space *space, Id id);       

/**
 * @brief Elimina un objeto específico del espacio
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param space un puntero al espacio
 * @param id el id del objeto a eliminar
 * @return OK, si todo sale bien, o ERROR si hubo algun problema
 */
Status space_del_object(Space *space, Id id);

/**
 * @brief Consigue el set del espacio
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param space un puntero a espacio
 * @return Devuleve un puntero a set del espacio pasado
 */
Set *space_get_set(Space *space);

 /**
 * @brief Establece el id del personaje que hay en el espacio
 * 
 * @author Xinyi Huang y Lucia Ordovas
 * 
 * @param space un puntero al espacio
 * @param id el id del personaje
 * @return OK, si todo sale bien, o ERROR si hubo algun problema
 */
Status space_set_character_id(Space *space, Id id);

 /**
 * @brief Obtiene el id del personaje que hay en el espacio
 * @author Xinyi Huang y Lucia Ordovas
 * 
 * @param space un puntero al espacio
 * @return el id del personaje en el espacio, NO_ID si no se encuentra
 */
Id space_get_character_id(Space *space);

/**
 * @brief Establece la descripción gráfica del espacio
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param space un puntero al espacio
 * @param gdesc una matriz de cadenas de texto con la descripción gráfica
 * @return OK, si todo sale bien, o ERROR si hubo algun problema
 */
Status space_set_gdesc(Space* space, char *str, int pos);

/**
* @brief Obtiene la descripción gráfica del espacio
* @author Xinyi Huang y Lucia Ordovas
*
* @param space un puntero al espacio
* @param line la línea de la descripción gráfica a obtener
* @return una puntero a cadena de texto con la descripción gráfica de la línea especificada. Si va mal, retorna NULL
*/
char* space_get_gdesc(Space* space, int line);

 
 /**
 * @brief Imprime la informacion del espacio
 * @author Xinyi Huang y Lucia Ordovas
 * Esta funcion muestra el id y el nombre del espacio, los espacios que lo rodean y si tiene un objeto o no.
 * @param space un puntero al espacio
 * @return OK, si todo sale bien, o ERROR si hubo algun problema
 */
 Status space_print(Space* space);

/**
 * @brief Obtiene el id del objeto en el espacio en la posicion pos
 * @author Xinyi Huang y Lucia Ordovas
 * 
 * @param space un puntero al espacio
 * @param pos la posición del objeto que quiera
 * @return Id de ese objeto en caso de que lo encuentre. NO_ID si no lo hay
 */
 Id space_get_objetc_id_at(Space *space, int pos); 

#endif
