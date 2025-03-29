/**
 * @brief It defines the link module interface
 *
 * @file link.h
 * @author David Buendía
 * @version 1
 * @date 20-03-2025
 * @copyright GNU Public License
*/

#ifndef link_H  
#define link_H

#include "types.h"


/**
 * @brief link
 *
 * This struct stores all the information of a link.
 */
typedef struct _link link;


/**
 * @brief It creates a new link
 * @author David Buendía
 *
 * @param id the id number of the new link
 * @return a new link initialized
 */
link* link_create (Id id);


/**
 * @brief It destroys a link, freeing the allocated memory
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @return nothing
 */
void link_destroy (link* link);


/**
 * @brief It gets the id from a link
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @return the link id
 */
Id link_get_id(link* link);


/**
 * @brief It sets a link an id
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @param id the id number of the new link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_id(link* link, Id id);

/**
 * @brief It gets the origin id from a link 
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @return the link origin id
 */
Id link_get_originID(link* link);


/**
 * @brief It sets a link an origin id
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @param id the id number of the new link origin
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_originID(link* link, Id id);

/**
 * @brief It gets the destination id from a link 
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @return the link destination id
 */
Id link_get_destID(link* link);


/**
 * @brief It sets a link a destination id
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @param id the id number of the new link destination
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_destID(link* link, Id id);


/**
 * @brief It gets the name from a link
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @return the links name in a string
 */
char* link_get_name(link* link);


/**
 * @brief It sets the name to a link
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @param name the new links name
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_name(link* link, char* name);


/**
 * @brief It gets the open status of a link
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @return the links open status
 */
Bool link_is_open(link *link);


/**
 * @brief It sets a link open status
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @param open the state of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_open(link* link, Bool open);


/**
 * @brief It gets the direction of a link
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @return the links direction
 */
Direction link_get_direction(link *link);


/**
 * @brief It sets a link a direction
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @param direction the direction of the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_direction(link *link, Direction direction);


/**
 * @brief It prints the information of a link
 * @author David Buendía
 *
 * @param link a pointer to the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_print(const link* link);



#endif