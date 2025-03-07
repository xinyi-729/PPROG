/**
 * @brief Define la interfaz del modulo del jugador
 *
 * @file player.h
 * @author Lucia Ordovas
 * @version 0
 * @date 31-01-2025
 * @copyright Licencia Publica GNU
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/**
 * @brief Crea un nuevo jugador, reservando memoria e inicializando sus miembros
 * @author Lucia Ordovas
 *
 * @param id el numero de identificacion para el nuevo jugador
 * @return un nuevo jugador inicializado
 */
Player* player_create(Id id);

/**
 * @brief Destruye un jugador, liberando la memoria reservada
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador que debe ser destruido
 * @return OK, si todo va bien o ERROR si hubo algun problema
 */
Status player_destroy(Player* player);

/**
 * @brief Obtiene el id de un jugador
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador
 * @return el id del jugador
 */
Id player_get_id(Player* player);

/**
 * @brief Establece el nombre de un jugador
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador
 * @param name una cadena con el nombre a almacenar
 * @return OK, si todo va bien o ERROR si hubo algun problema
 */
Status player_set_name(Player* player, char* name);

/**
 * @brief Obtiene el nombre de un jugador
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador
 * @return una cadena con el nombre del jugador
 */
const char* player_get_name(Player* player);

/**
 * @brief Establece la ubicacion de un jugador
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador
 * @param value el numero de identificacion de la ubicacion
 * @return OK, si todo va bien o ERROR si hubo algun problema
 */
Status player_set_location(Player* player, Id value);

/**
 * @brief Obtiene la ubicacion de un jugador
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador
 * @return el id de la ubicacion
 */
Id player_get_location(Player* player);

/**
 * @brief Establece el objeto que tiene el jugador
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador
 * @param value el numero de identificacion del objeto
 * @return OK, si todo va bien o ERROR si hubo algun problema
 */
Status player_set_object(Player* player, Id value);

/**
 * @brief Obtiene el objeto que tiene el jugador
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador
 * @return el id del objeto
 */
Id player_get_object(Player* player);

/**
 * @brief Decrece la salud en una unidad
 * @author Lucia Ordovas
 *
 * @param player un puntero al jugador
 * @return OK, ERROR
 */
Status player_decrease_health(Player *player);
/**
 * @brief Imprime la informacion del jugador
 * @author Lucia Ordovas
 *
 * Esta funcion muestra el id y el nombre del jugador, la localizacion y el objeto que porta.
 * @param player un puntero al jugador
 * @return OK, si todo va bien o ERROR si hubo algun problema
 */
Status player_print(Player* player);

#endif