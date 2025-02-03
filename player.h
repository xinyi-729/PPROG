/**
 * @brief It defines the player module interface
 *
 * @file player.h
 * @author Xinyi Huang and Lucía Ordovás
 * @version 0
 * @date 31-01-2025
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/**
 * @brief It creates a new player, allocating memory and initializing its members
 * @author Xinyi Huang and Lucía Ordovás
 *
 * @param id the identification number for the new player
 * @return a new player, initialized
 */
Player* player_create(Id id);

/**
 * @brief It destroys a player, freeing the allocated memory
 * @author Xinyi Huang and Lucía Ordovás
 *
 * @param player a pointer to the player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_destroy(Player* player);

/**
 * @brief It gets the id of a player
 * @author Xinyi Huang and Lucía Ordovás
 *
 * @param player a pointer to the player
 * @return the id of player
 */
Id player_get_id(Player* player);

/**
 * @brief It sets the name of a player
 * @author Xinyi Huang and Lucía Ordovás
 *
 * @param player a pointer to the player
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name(Player* player, char* name);

/**
 * @brief It gets the name of a player
 * @author Xinyi Huang and Lucía Ordovás
 *
 * @param player a pointer to the player
 * @return  a string with the name of the player
 */
const char* player_get_name(Player* player);


/**
 * @brief It sets whether the player has an object or not
 * @author Xinyi Huang and Lucía Ordovás
 *
 * @param player a pointer to the player
 * @param value a boolean, specifying if the player has an object (TRUE) or not (FALSE)
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_object(Player* player, Bool value);

/**
 * @brief It gets whether the player has an object or not
 * @author Xinyi Huang and Lucía Ordovás
 *
 * @param player a pointer to the player
 * @return a boolean, specifying if the player has an object (TRUE) or not (FALSE)
 */
Bool player_get_object(Player* player);

/**
 * @brief It prints the player information
 * @author Xinyi Huang and Lucía Ordovás
 *
 * This function shows the id and name of the player, the players that surround it and whether it has an object or not.
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(Player* player);

#endif