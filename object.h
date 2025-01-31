/**
 * @brief Define la interfaz del modulo del objeto
 *
 * @file object.h
 * @author XINYI HUANG
 * @version 0
 * @date 31-01-2025
 * @copyright GNU Public License
 */


#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

/**
 * @brief Crea un objeto con el id dado
 * @author XINYI HUANG
 *
 * @param id identificación del objeto
 * @return un objeto con sus valores de inicio
 */
Object* object_create(Id id);

/**
 * @brief Destruye el objeto liberando la memoria
 * @author XINYI HUANG
 *
 * @param obj puntero a Object, el objeto que queremos destruir
 * @return OK en caso de éxito y ERROR si algo salió mal
 */
Status object_destroy(Object *obj);

/**
 * @brief Consigue el identificador del objeto
 * @author XINYI HUANG
 *
 * @param obj puntero a Object, que queremos saber su identificador
 * @return En caso de éxito devuelve el id de este objeto, en otros casos devuelve NO_ID
 */
Id object_get_id(Object *obj);

/**
 * @brief Asignar al oobjeto el nombre dado como argumento
 * @author XINYI HUANG
 *
 * @param obj puntero a Object, que queremos ponerle el nombre
 * @param name puntero a un string, el nombre que queremos asignar al objeto
 * @return OK en caso de éxito y ERROR si algo salió mal
 */
Status object_set_name(Object *obj, char *name);

/**
 * @brief Printea el objeto en el juego (su estructura, nombre, id, etc)
 * @author XINYI HUANG
 *
 * @param obj puntero a Object
 * @return OK en caso de éxito y ERROR si algo salió mal
 */
Status object_print(Object* obj);


#endif