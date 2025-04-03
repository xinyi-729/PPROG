/**
 * @brief It defines the inventory module interface
 *
 * @file inventory.h
 * @author Lucía Ordovás
 * @version 1
 * @date 27-02-2025
 * @copyright GNU Public License
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"

/**
 * @brief Inventory
 * @author Lucía Ordovás
 * This struct stores all the information related to a inventory.
*/
typedef struct _Inventory Inventory;

/**
 * @brief It creates a new inventory
 * @author Lucía Ordovás
 * 
 * @return a new inventory initialized
 */
Inventory* inventory_create();

/**
 * @brief It destroys an inventory
 * @author Lucía Ordovás
 *
 * @param inventory a pointer to inventory
 * @return nothing
 */
void inventory_destroy(Inventory *inventory);

/**
 * @brief It adds an object id to the inventory
 * @author Lucía Ordovás
 *
 * @param inventory a pointer to inventory
 * @param obj_id the id of the object
 * @return OK or ERROR
 */
Status inventory_add(Inventory *inventory, Id obj_id);

/**
 * @brief It deletes an object id in the inventory
 * @author Lucía Ordovás
 *
 * @param inventory a pointer to inventory
 * @param obj_id the id of the object
 * @return OK or ERROR
 */
Status inventory_del(Inventory *inventory, int obj_id);

/**
 * @brief It gets the maximum number of objects
 * @author Lucía Ordovás
 *
 * @param inventory a pointer to inventory
 * 
 * @return the maximun number of objects, -1 in case of error
 */
int inventory_get_max_objs(Inventory *inventory);
Status inventory_set_max_objs(Inventory *inventory,int num);

// /**
//  * @brief It gets the set of objects of the inventory
//  * @author Lucía Ordovás
//  *
//  * @param inventory a pointer to inventory
//  * 
//  * @return the set of objects or NULL in case of error
//  */
// Set* inventory_get_objs(Inventory *inventory);


/**
 * @brief It checks if the inventory has an object or not
 * @author Alejandro Fernández
 *
 * @param inventory a pointer to inventory
 * @param id the id that we want to search
 * 
 * @return TRUE if the object is in the inventory or FALSE if not
 */
Bool inventory_has_object(Inventory *inventory, Id id);

/**
 * @brief It checks if the inventory is full
 * @author Alejandro Fernández
 *
 * @param inventory a pointer to inventory
 * 
 * @return TRUE if its full or FALSE if not
 */
Bool inventory_is_full(Inventory *inventory);

/**
 * @brief It checks if the inventory is empty
 * @author Alejandro Fernández
 *
 * @param inventory a pointer to inventory
 * 
 * @return TRUE if its empty or FALSE if not
 */
Bool inventory_is_empty(Inventory *inventory);

/**
 * @brief It prints an inventory
 * @author Lucía Ordovás
 *
 * @param inventory a pointer to inventory
 * @return OK or ERROR
 */
Status inventory_print(Inventory *inventory);

/**
 * @brief It gets the id of the object of the inventory
 * @author Lucía Ordovás
 *
 * @param inventory a pointer to inventory
 * @param pos the position of the object in the array 
 * @return id of the object in the given position
 */
Id inventory_get_obj_id(Inventory *inv, int pos);

/**
 * @brief It gets the number of objects of the inventory
 * @author Lucía Ordovás
 *
 * @param inventory a pointer to inventory
 * @return the number of objects of the inventory
 */
int inventory_get_n_obj(Inventory *inv);

#endif