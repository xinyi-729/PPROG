/**
 * @brief Define la interfaz del modulo game_reader
 *
 * @file game_reader.h
 * @author XINYI HUANG
 * @version 0
 * @date 31-01-2025
 * @copyright GNU Public License
 */
#ifndef GAME_READER_H
#define GAME_READER_H

#include "types.h"
#include "game.h"

/**
 * @brief La función lee el fichero .dat y crea el juego con los espacios, objetos y el jugador describido en el fichero.dat
 * @author XINYI HUANG
 *
 * @param game un puntero al Game
 * @param filename un puntero al string que debe recibir la función
 * @return OK en caso de déxito y ERROR en caso de errores
 */
Status game_create_from_file(Game *game, char *filename);

/**
 * @brief La función lee el fichero .dat y crea el juego con los espacios (el numero de espacio, longitud, anchura, etc) según puesto en el fichero.dat
 * @author XINYI HUANG
 *
 * @param game un puntero al Game
 * @param filename un puntero al string que debe recibir la función
 * @return OK en caso de déxito y ERROR en caso de errores
 */
Status game_load_spaces(Game *game, char *filename);




#endif