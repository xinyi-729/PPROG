/**
 * @brief It defines the character module interface
 *
 * @file character.h
 * @author David Buendía
 * @version 1
 * @date 20-02-2025
 * @copyright GNU Public License
*/

#ifndef character_H  
#define character_H

#define GDESC_SIZE 6

#include "types.h"


/**
 * @brief character
 *
 * This struct stores all the information of a character.
 */
typedef struct _Character Character;

/**
 * @brief It creates a new character
 * @author David Buendía
 *
 * @param id the id number of the new character
 * @return a new character initialized
 */
Character* character_create (Id id);


/**
 * @brief It destroys a character, freeing the allocated memory
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @return nothing
 */
void character_destroy (Character* character);


/**
 * @brief It gets the id from a character
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @return the character id
 */
Id character_get_id(Character* character);

/*Se quita*/
// /**
//  * @brief It sets a character an id
//  * @author David Buendía
//  *
//  * @param character a pointer to the character
//  * @param id the id number of the new character
//  * @return OK, if everything goes well or ERROR if there was some mistake
//  */
// Status character_set_id(character* character, Id id);


/**
 * @brief It gets the name from a character
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @return the characters name in a string
 */
char* character_get_name(Character* character);


/**
 * @brief It sets the name to a character
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @param name the new characters name
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_name(Character* character, char* name);


/**
 * @brief It gets the graphic description from a character
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @return the characters graphic description
 */
char* character_get_graphic_description(Character* character);


/**
 * @brief It sets a character a graphic description
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @param gdesc graphic description of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_graphic_description(Character* character, char* gdesc);


/**
 * @brief It gets the health from a character
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @return the characters health
 */
int character_get_health(Character *character);


/**
 * @brief It sets a character health
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @param hp the health of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_health(Character* character, int hp);


/**
 * @brief It gets the friend status of a character
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @return the characters friend status
 */
Bool character_get_friend(Character *character);


/**
 * @brief It sets a character friend status
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @param typ the friend of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_friend(Character* character, Bool type);


/**
 * @brief It gets the message from a character
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @return the characters message
 */
char* character_get_message(Character* character);


/**
 * @brief It sets a character a message
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @param msg message of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_set_message(Character* character, char* msg);


/**
 * @brief It prints the information of a character
 * @author David Buendía
 *
 * @param character a pointer to the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_print(const Character* character);

#endif