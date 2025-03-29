/**
 * @brief Define el interfaz del conjunto
 *
 * @file set.h
 * @author XINYI HUANG
 * @version 0
 * @date ACTUALIZADO 14-03-2025
 * @copyright GNU Public License
 */


 #ifndef SET_H
 #define SET_H
 
 #include "types.h"
 
 #define MAX_OBJECTS 50
 
 typedef struct _Set Set;
 
 /**
  * @brief Crea un nuevo conjunto (set)
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @return Puntero al nuevo conjunto creado, NULL en caso de error
  */
 Set *set_create();
 
 /**
  * @brief Destruye un conjunto (set) y libera su memoria
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param set Puntero al conjunto a destruir
  * @return OK en caso de éxito y ERROR en caso sin éxito
  */ 
 Status set_destroy(Set *set);
 
 /**
  * @brief Busca y obtiene el ID específico de un posicion dado dentro del conjunto (set)
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param set Puntero al conjunto
  * @param pos posicion a buscar en el conjunto
  * @return ID del objeto, NO_ID en caso de error o si no se encuentra
  */
 Id set_get_id(Set *set, int pos);
 
 /**
  * @brief Obtiene el número de IDs en el conjunto (set)
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param set Puntero al conjunto
  * @return Número de IDs en el conjunto, -1 en caso de error
  */
 int set_get_n_ids(Set *set);
 
 /**
  * @brief Añade un ID al conjunto (set)
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param set Puntero al conjunto
  * @param id ID a añadir al conjunto
  * @return OK si se añadió correctamente, ERROR en caso contrario
  */
 Status set_add(Set *set, Id id);
 
 /**
  * @brief Elimina un ID específico del conjunto (set)
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param set Puntero al conjunto
  * @param id ID a eliminar del conjunto
  * @return OK si se eliminó correctamente, ERROR en caso contrario
  */
 Status set_del(Set *set, Id id);
 
 /**
  * @brief Verifica si un ID está presente en el conjunto (set)
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param set Puntero al conjunto
  * @param id ID a verificar en el conjunto
  * @return TRUE si el ID está presente, FALSE en caso contrario
  */
 Bool set_has(Set *set, Id id);
 
 /**
  * @brief Imprime el contenido del conjunto (set)
  * @author Xinyi Huang y Lucia Ordovas
  *
  * @param set Puntero al conjunto
  * @return OK si se imprimió correctamente, ERROR en caso contrario
  */
 Status set_print(Set *set);
 
 
 #endif