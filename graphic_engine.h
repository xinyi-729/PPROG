/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 1
 * @date 17-02-2025
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"
#include <stdio.h>

/**
 * @brief Object
 *
 * This struct stores all the information related to a graphic engine.
*/
typedef struct _Graphic_engine Graphic_engine;


/**
 * @brief It creates a new graphic engine
 * @author Profesores PPROG
 *
 * @return a new graphic engine initialized
 */
Graphic_engine *graphic_engine_create();


/**
 * @brief It destroy a graphic engine, freeing its allocated memory
 * @author Profesores PPROG
 *
 * @param ge a pointer to the graphic engine that must be destroyed
 * @return nothing
 */
void graphic_engine_destroy(Graphic_engine *ge);


/**
 * @brief It displays the game in the screen
 * @author Profesores PPROG
 *
 * @param ge a pointer to the graphic engine for reference
 * @param game a pointer to game struct for painting the parameters
 * @return nothing
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
