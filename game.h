/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 1
 * @date 7-03-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "object.h"
#include "player.h"
#include "character.h"
#include "link.h"

#define MAX_SPACES 100
#define MAX_CHARACTERS 10
#define MAX_LINKS 400
#define MAX_PLAYERS 10

#define PLAYER_ID 729
#define IN_PLAYER 407

/**
 * @brief Game
 *
 * This struct stores all the information of a game.
 */
typedef struct _Game Game;

/**
 * @brief It creates a game initializating everything
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return It always returns OK.
 */
Game *game_create();

/**
 * @brief It receives a pointer to the game that must be destroyed and frees his allocated memory
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_destroy(Game *game);

/**
 * @brief It searches for the space that correspond to the id
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param id an Id
 * @return the space of the id given
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief It searches the position of the player
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @return the Id of the player position
 */
Id game_get_player_location(Game *game);

/**
 * @brief It sets the position of the player
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @param id the id that we want to set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief It gets the name from an object
 * @author David Buendía
 *
 * @param game a pointer to the game
 * @param id the id of the object
 * @return the characters name in a string
 */
char *game_get_object_name(Game *game, Id id);

/**
 * @brief It sets the position of the object
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @param object a pointer to the new object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_object(Game *game, Object *object);

/**
 * @brief It generates a new space
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param space a pointer to the new space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief It searches the last command used
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return the last command given by the user
 */
Command *game_get_last_command(Game *game);

/**
 * @brief It sets the last command used
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param command the command that we want to set
 * @return It always return OK
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief It checks if the game has finished or not
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return the state of the game (FALSE if it hasn't finished or TRUE if it has finished)
 */
Bool game_get_finished(Game *game);

/**
 * @brief It sets the game as finished
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param finished a boolean variable
 * @return it always return OK.
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief It checks if the game has a character in player space
 * @author David Buendia
 *
 * @param game a pointer to the game
 * @return character pointer
 */
Character *game_get_character(Game *game, Id id);

/**
 * @brief It prints the game information
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @return nothing
 */
void game_print(Game *game);

/**
 * @brief It gets the player of the game
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @return a pointer to the player or NULL
 */
Player *game_get_player(Game *game);

/**
 * @brief It gets the objects of the game
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @return a pointer to the set of objects
 */
Set *game_get_objects(Game *game);
/**
 * @brief It gets the number of spaces in the game
 * @author David Buendía
 *
 * @param game a point er to the game
 * @return the number of spaces in the game
 */
int game_get_numspaces(Game *game);

/**
 * @brief It gets the Id of the actual space
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param position the position
 * @return the Id of the actual space
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief It adds a character to the game
 * @author David Buendía
 *
 * @param game a pointer to the game
 * @param character a pointer to the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_character(Game *game, Character *character);

/********************************************************************************+TRADUCIR------------------- */
/**
 * @brief Gets the ID of an object based on its name
 * @author Xinyi Huang and Lucia Ordovas
 *
 * @param game Pointer to the game
 * @param obj_name Name of the object
 * @return Id of the object or NO_ID if not found
 */
Id game_get_object_id(Game *game, char *obj_name);

/**
 * @brief Gets the number of objects in the game
 * @author Xinyi Huang and Lucia Ordovas
 *
 * @param game Pointer to the game
 * @return The number of objects in the game
 */
int game_get_numobj(Game *game);

/**
 * @brief Gets the ID of the object at the given position
 * @author Alejandro Fernández
 *
 * @param game A pointer to the game
 * @param position The position in the array
 * @return The ID of the object or NO_ID
 */
Id game_get_object_id_at(Game *game, int position);
/**
 * @brief It gets the space the position given
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @param position the position in the array
 * @return a pointer to the space or NULL
 */
Space *game_get_space_at(Game *game, int position);

/**
 * @brief Gets an object by its ID
 * @author Xinyi Huang
 * 
 * @param game Pointer to the game
 * @param id ID of the object
 * @return Pointer to the object or NULL if somethings going bad
 */
Object *game_get_object(Game *game, Id id);

/**
 * @brief Gets the character in a specific space
 * @author Xinyi Huang and Lucia Ordovas
 *
 * @param game Pointer to the game
 * @param space_id ID of the space
 * @return Pointer to the character in the space, NULL if no character or if there's an error
 */
Character *game_get_character_in_space(Game *game, Id space_id);

/**
 * @brief Gets the character's message in the space
 * @author Xinyi Huang and Lucia Ordovas
 *
 * @param game Pointer to the game
 * @return Character's message
 */
char *game_get_message(Game *game);

/**
 * @brief Gets the inventory of the player
 * @author Lucia Ordovas
 *
 * @param game Pointer to the game
 * @return pointer to inventory
 */
Inventory *game_get_inventory(Game *game);

/**
 * @brief Gets the description of a specific object from its name
 * @author Lucia Ordovas
 *
 * @param game Pointer to the game
 * @param obj_name Name of the object
 * @return Object's description
 */
char *game_get_object_description_from_name(Game *game, char *obj_name);

/**
 * @brief Checks if the inventory of the player has the object 
 * @author Lucia Ordovas
 *
 * @param game Pointer to the game
 * @param obj_name Name of the object
 * @return TRUE or FALSE
 */
Bool game_inventory_has_object(Game *game, char *obj_name);

/**
 * @brief Gets the ID of the space in the given direction
 * @author Xinyi Huang
 *
 * @param game A pointer to the game
 * @param space_act ID of current space
 * @param dir Direction the player wants to move
 * @return ID of the space the player wants to move to
 */
Id game_get_connection(Game *game, Id space_act, Direction dir);

/**
 * @brief Verify if the space the player wants to move is open or not
 * @author Xinyi Huang
 *
 * @param game A pointer to the game
 * @param space_act ID of current space
 * @param dir Direction the player wants to move
 * @return True if is able to move, False in the opposite case
 */
Bool game_connection_is_open(Game *game, Id space_act, Direction dir );

/**
 * @brief Gets a Link by its ID
 * @author Xinyi Huang
 * 
 * @param game Pointer to the game
 * @param id ID of the link
 * @return Pointer to the link or NULL if somethings going bad
 */
link *game_get_link(Game *game, Id id_link);

/**
 * @brief Adds a link to the game
 * @author Xinyi Huang
 * 
 * @param game a pointer to the game
 * @param link a pointer to link
 * @return Return OK if successful. ERROR if an error occurs
 */
Status game_add_link(Game *game, link *link);

Id game_get_character_id_at(Game *game, int position);
int game_get_numcharacter(Game *game);

/*--------------------------------------------------------------*/
/* Funciones adicionales (F11) */
/**
 * @brief Adds a player to the game
 * @author Lucia Ordovas
 * 
 * @param game a pointer to the game
 * @param player a pointer to player
 * @return Return OK if successful. ERROR if an error occurs
 */
Status game_add_player(Game *game, Player *player);

/**
 * @brief updates the turn to the next player
 * @author Lucia Ordovas
 * 
 * @param game a pointer to the game
 * @return Return OK if successful. ERROR if an error occurs
 */
Status game_next_turn(Game *game);

#endif