/**
 * @brief It defines the player module interface
 *
 * @file player.h
 * @author David Buendía
 * @version 1
 * @date 13-02-2025
 * @copyright GNU Public License
*/

#ifndef PLAYER_H  
#define PLAYER_H

#include "types.h"
#include "inventory.h"

/**
 * @brief Player
 *
 * This struct stores all the information of a player.
 */
typedef struct _Player Player;

/**
 * @brief It creates a new player
 * @author David Buendía
 *
 * @param id the id number of the new player
 * @return a new player initialized
 */
Player* player_create (Id id);


/**
 * @brief It destroys a player, freeing the allocated memory
 * @author David Buendía
 *
 * @param player a pointer to the player
 * @return nothing
 */
void player_destroy (Player* player);


/**
 * @brief It gets the id from a player
 * @author David Buendía
 *
 * @param player a pointer to the player
 * @return the player id
 */
Id player_get_id(Player* player);


/**
 * @brief It gets the name from a player
 * @author David Buendía
 *
 * @param player a pointer to the player
 * @return the players name in a string
 */
char* player_get_name(Player* player);


/**
 * @brief It sets the name to a player
 * @author David Buendía
 *
 * @param player a pointer to the player
 * @param name the new players name
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name(Player* player, char* name);


/**
 * @brief It gets the location from a player
 * @author David Buendía
 *
 * @param player a pointer to the player
 * @return the players location
 */
Id player_get_location(Player* player);


/**
 * @brief It sets a player a location
 * @author David Buendía
 *
 * @param player a pointer to the player
 * @param id the id number of the new player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_location(Player* player, Id id);


/**
 * @brief It gets the health from a player
 * @author David Buendía
 *
 * @param player a pointer to the player
 * @return the players health
 */
int player_get_health(Player *player);


/**
 * @brief It sets a player health
 * @author David Buendía
 *
 * @param player a pointer to the player
 * @param hp the health of the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_health(Player* player, int hp);


/**
 * @brief It gets the object from a player
 * @author Alejandro Fernández
 *
 * @param player a pointer to the player
 * @return a pointer to the backpack or NULL
 */
Inventory *player_get_backpack(Player *player);


/**
 * @brief It sets an object in the backpack
 * @author Alejandro Fernández
 *
 * @param player a pointer to the player
 * @param id the id number of object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_add_object(Player* player, Id id);


/**
 * @brief It deletes a object of the backpack
 * @author Alejandro Fernández
 *
 * @param player a pointer to the player
 * @param id the id number of the  object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_del_object(Player *player, Id id);


/**
 * @brief It checks if the backpack has an object or not
 * @author Alejandro Fernández
 *
 * @param player a pointer to the player
 * @param id the id number of the new player
 * @return TRUE or FALSE
 */
Bool player_has_object(Player *player, Id id);

/**
 * @brief It checks if the backpack is full or not
 * @author Alejandro Fernández
 *
 * @param player a pointer to the player
 * @return TRUE if its full or FALSE if not
 */
Bool player_backpack_is_full(Player *player);

/**
 * @brief It checks if the backpack is empty or not
 * @author Alejandro Fernández
 *
 * @param player a pointer to the player
 * @return TRUE if its empty or FALSE if not
 */
Bool player_backpack_is_empty(Player *player);
/**
 * @brief It gets the graphic description from a player
 * @author Ana Maldonado
 *
 * @param player a pointer to the player
 * @return the player graphic description
 */
char *player_get_graphic_description(Player *player);

/**
 * @brief It sets a character a graphic description
 * @author Ana Maldonado
 *
 * @param character a pointer to the player
 * @param gdesc graphic description of the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_graphic_description(Player *player, char *gdesc);

/**
 * @brief It prints the information of a player
 * @author Alejandro Fernández
 *
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(const Player* player);


#endif