/**
 * @brief It defines the game reader module interface
 *
 * @file game_reader.h
 * @author Alejandro Fernández
 * @version 1
 * @date 03-02-2025
 * @copyright GNU Public License
*/

#ifndef GAME_READER_H  
#define GAME_READER_H

#include "types.h"
#include "game.h"
#include "link.h"

/*FALTARIA CAMBIARLO A INGLES*/
/**
 * @brief La función lee el fichero .dat y crea el juego con los espacios, objetos y el jugador describido en el fichero.dat
 * @author XINYI HUANG y Lucia Ordovas
 *
 * @param game un puntero al Game
 * @param filename un puntero al string que debe recibir la función
 * @return OK en caso de éxito y ERROR en caso de errores
 */
Status game_create_from_file(Game *game, char *filename);

#endif