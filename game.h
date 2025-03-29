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
 * @param game a pointer to the game
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

/********TRADUCIR------------------- */
/**
 * @brief Obtiene el ID de un objeto a partir de su nombre
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @param obj_name Nombre del objeto
 * @return ID del objeto o NO_ID si no se encuentra
 */
Id game_get_object_id(Game *game, char *obj_name);

/**
 * @brief Obtiene el número de objetos que hay en el juego
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game puntero al juego
 * @return devuelve el número de objetos que hay en el juego
 */
int game_get_numobj(Game *game);

/**
 * @brief It gets the Id of the object in the position given
 * @author Alejandro Fernández
 *
 * @param game a pointer to the game
 * @param position the position in the array
 * @return the id of the object or NO_ID
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

Object *game_get_object(Game *game, Id id);

/**
 * @brief Obtiene el personaje en un espacio específico
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @param space_id ID del espacio
 * @return Puntero al personaje en el espacio, NULL si no hay personaje o si hay un error
 */
Character *game_get_character_in_space(Game *game, Id space_id);

/**
 * @brief Obtiene el mensaje del character en el espacio
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @return Mensaje del character
 */
char *game_get_message(Game *game);

/**
 * @brief Obtiene la descripcion de un objeto especifico
 * @author Lucia Ordovas
 *
 * @param game Puntero al juego
 * @param obj_name nombre del objeto
 * @return Descripcion del objeto
 */
char *game_get_object_description(Game *game, char *obj_name);


Id game_get_connection(Game *game, Id space_act, Direction dir);
Bool game_connection_is_open(Game *game, Id space_act, Direction dir );
link *game_get_link(Game *game, Id id_link);
Status game_add_link(Game *game, link *link);

#endif