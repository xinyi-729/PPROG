/**
 * @brief It defines the object module interface
 *
 * @file object.h
 * @author Alejandro Fernández
 * @version 1
 * @date 13-02-2025
 * @copyright GNU Public License
*/


#ifndef OBJECT_H  
#define OBJECT_H

/** @brief Object
 * This struct stores all the information related to a object.
*/

#include "types.h"


/**
 * @brief Object
 *
 * This struct stores all the information related to a object.
*/

typedef struct _Object Object;

/**
 * @brief It creates a new object
 * @author Alejandro Fernández
 *
 * @param id the id number of the new object
 * @return a new object initialized
 */
Object* object_create (Id id);

/**
 * @brief It destroys an object, freeing the allocated memory
 * @author Alejandro Fernández
 *
 * @param object a pointer to the object
 * @return nothing
 */
void object_destroy (Object* object);

/**
 * @brief It gets the id from a object
 * @author Alejandro Fernández
 *
 * @param object a pointer to the object
 * @return the object id
 */
Id object_get_id(Object* object);



/**
 * @brief It gets the name from an object
 * @author Alejandro Fernández
 *
 * @param object a pointer to the object
 * @return the object name in a string
 */
char* object_get_name(Object* object);


/**
 * @brief It sets the name to an object
 * @author Alejandro Fernández
 *
 * @param object a pointer to the object
 * @param  name the new object name
 * @return  OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_name(Object* object, char* name);

/**
 * @brief It prints the information of an object
 * @author Alejandro Fernández
 *
 * @param  object a pointer to the object
 * @return  OK, if everything goes well or ERROR if there was some mistake
 */
Status object_print(const Object* object);

/**
 * @brief It sets the description of the object
 * @author LUCÍA ORDOVÁS
 *
 * @param obj pointer to object
 * @param description the description of the object
 * @return OK in case of success of ERROR in case of error
 */
Status object_set_description(Object *obj, char *description);

/**
 * @brief It gets the description of the object
 * @author LUCÍA ORDOVÁS
 *
 * @param obj pointer to object
 * @return the description of the object
 */
char *object_get_description(Object *obj);

#endif