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

Graphic_engine *graphic_engine_create();

void graphic_engine_destroy(Graphic_engine *ge);

void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
