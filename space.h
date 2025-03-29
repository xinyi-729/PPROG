/**
 * @brief It defines the space module interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1
 * @date 12-02-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

#define GDESC_ROWS 5  /*The max size of rows in the graphic description*/
#define GDESC_COLS 10  /*The max size of columns in the graphic description*/

typedef struct _Space Space;

/**
 * @brief It creates a new space, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space* space_create(Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_destroy(Space* space);

/**
 * @brief It gets the id of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(Space* space);

/**
 * @brief It sets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_name(Space* space, char* name);

/**
 * @brief It gets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char* space_get_name(Space* space);






/**
 * @brief It sets whether the space has an object or not
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the object id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_add_object(Space* space, Id id);

/**
 * @brief It delete a object of the space
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param space a pointer to the space
 * @param id the object id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_del_object(Space *space, Id id);

/**
 * @brief It gets whether the space has an object or not
 * @author Alejandro Fernández
 *
 * @param space a pointer to the space
 * @return a pointer to Set, specifying the objects in the space.
 */
Set *space_get_object(Space* space);


/**
 * @brief It gets whether the space has a character or not
 * @author David Buendía
 *
 * @param space a pointer to the space
 * @return a pointer to Id, specifying the character in the space.
 */
Id space_get_character_id(Space *space);


/**
 * @brief It sets whether the space has an character or not
 * @author David Buendía
 *
 * @param space a pointer to the space
 * @param id the character id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_character_id(Space *space, Id id);

/**
 * @brief It gets an especific row of the graphic description
 * @author Alejandro Fernández
 *
 * @param space a pointer to the space
 * @param row the row that we want to get
 * @return a pointer to the graphic description or NULL if there was some mistake
 */
char *space_get_gdesc(Space *space, int row);

/**
 * @brief It prints the space information
 * @author Profesores PPROG
 *
 * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_print(Space* space);

/**
 * @brief It sets an especific row of the graphic description
 * @author Alejandro Fernández
 *
 * @param space a pointer to the space
 * @param gdesc a pointer to the graphic description
 * @param row the row that we want to get
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_gdesc(Space *space, char *gdesc, int row);

/*--traducir--*/
/**
 * @brief Obtiene el id del objeto en el espacio en la posicion pos
 * @author Xinyi Huang y Lucia Ordovas
 * 
 * @param space un puntero al espacio
 * @param pos la posición del objeto que quiera
 * @return Id de ese objeto en caso de que lo encuentre. NO_ID si no lo hay
 */
Id space_get_objetc_id_at(Space *space, int pos); 

 /**
   * @brief It verify if space has the object or no
   * @author Xinyi Huang
   *
   * @param space un puntero al espacio
   * @param id el id del objeto a verificar
   * @return TRUE si el objeto está presente, FALSE en caso contrario
   */
  Bool space_has_object(Space *space, Id id);
#endif
