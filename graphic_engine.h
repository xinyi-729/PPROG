/**
 * @brief Define la interfaz del motor grafico textual
 *
 * @file graphic_engine.h
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief Crea e inicializa un motor gráfico
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @return Puntero a la estructura Graphic_engine creada o NULL en caso de error
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief Libera la memoria y destruye el motor gráfico
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param ge Puntero al motor gráfico a destruir
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief Muestra el mapa, la ubicación de los objetos y el jugador, e informacion adicional
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @param ge Puntero al motor gráfico
 * @param game Puntero a la estructura del juego
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);


#endif
