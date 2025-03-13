/**
 * @brief Define la interfaz del juego
 *
 * @file game.h
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h" 
#include "object.h"
#include "types.h"
#include "player.h"

#define MAX_SPACES 100
#define ID_PLAYER 729


/*-----------------------------------------------------------------------------------------------------*/
typedef struct _Game Game;
/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Crea e inicializa un juego
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param 
 * @return Puntero a la estructura de game creada e inicializada
 */
Game* game_create();

/**
 * @brief Libera la memoria y destruye un juego
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego a destruir
 * @return OK si la creación fue exitosa, ERROR en caso contrario
 */
Status game_destroy(Game *game);

/**
 * @brief Obtiene un espacio del juego a partir de su ID
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @param id Identificador del espacio
 * @return Puntero al espacio encontrado o NULL si no existe
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief Obtiene la ubicación del jugador
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @return ID del espacio donde se encuentra el jugador o NO_ID en caso de error
 */
Id game_get_player_location(Game *game);

/**
 * @brief Establece la ubicación del jugador
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @param id Identificador del nuevo espacio
 * @return OK si se estableció correctamente, ERROR en caso contrario
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief Obtiene el último comando ejecutado en el juego
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @return Puntero al último comando ejecutado
 */
Command* game_get_last_command(Game *game);

/**
 * @brief Establece el último comando ejecutado en el juego
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @param command Puntero al nuevo comando
 * @return OK si se estableció correctamente, ERROR en caso contrario
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief Indica si el juego ha finalizado
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @return TRUE si el juego ha finalizado, FALSE en caso contrario
 */
Bool game_get_finished(Game *game);

/**
 * @brief Establece el estado de finalización del juego
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 * @param finished Estado de finalización
 * @return OK si se estableció correctamente, ERROR en caso contrario
 */
Status game_set_finished(Game *game, Bool finished);

// Id game_get_object_location(Game *game, Id obj_id);
// Status game_set_object_location(Game *game, Id id_space);

/**
 * @brief Imprime el estado actual del juego 
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param game Puntero al juego
 */
void game_print(Game *game);


// Id game_get_object_location(Game *game,Id id_obj);
/*-----------------------------------------------------------------------------------------------------*/
Id game_get_space_id_at(Game *game, int position);
Status game_add_space(Game *game, Space *space);

Player *game_get_player(Game *game);

Id game_get_object_id(Game *game, char *obj_name);
int game_get_n_obj(Game *game);
Object *game_get_object(Game *game, Id id);
Status game_add_object(Game *game, Object *obj);

Id game_get_object_id_at(Game *game, int position) ;

#endif
