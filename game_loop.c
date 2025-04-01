/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "command.h"
#include "game.h"
#include "game_actions.h"
#include "graphic_engine.h"
#include "game_reader.h"

/**
 * @brief It initializates the game
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param ggengine a pointer to a pointer of graphic engine
 * @param file_name the name of the file
 * @return 0 if everything goes well or 1 if there was some mistake
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

/**
 * @brief It updates the graphics of the game with the last command given by the user
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param ggengine a pointer to a pointer of graphic engine
 * @param file_name the name of the file
 * @return void
 */
void game_loop_run(Game *game, Graphic_engine *gengine,FILE *file);

/**
 * @brief It destroy the game and the graphic engine cleaning it
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param ggengine a pointer to a pointer of graphic engine
 * @return void
 */
void game_loop_cleanup(Game *game, Graphic_engine *gengine);

/**
 * @brief It cheks if there are more than 2 arguments, one for the exe that we want to get and another for the file name with the data that we need
 * @author Profesores PPROG
 *
 * @param argc number of arguments that receives the functions
 * @param argv pointer to this arguments
 * @return 0 if everything goes well or 1 if there was some mistake
 */

 int main(int argc, char *argv[])
 {
   Game *game = NULL;
   Graphic_engine *gengine;
   FILE *f=NULL;
   if (argc < 2)
   {
     fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
     return 1;
   }
   
   
   if(argc==4){
     f=fopen(argv[3],"w");
     if(f==NULL){
       return 1;
     }
   }
 
   game = game_create();
   if (game == NULL)
   { 
     fclose(f);
     return 1;
   }
   if (!game_loop_init(game, &gengine, argv[1]))
   {
     game_loop_run(game, gengine,f);
     game_loop_cleanup(game, gengine);
   }
 
   return 0;
 }
 
 int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name)
 {
 
   srand(time(NULL));
 
   if (game_create_from_file(game, file_name) == ERROR)
   {
     fprintf(stderr, "Error while initializing game.\n");
     game_destroy(game);
     return 1;
   }
 
   if ((*gengine = graphic_engine_create()) == NULL)
   {
     fprintf(stderr, "Error while initializing graphic engine.\n");
     game_destroy(game);
     return 1;
   }
 
   return 0;
 }
 
 void game_loop_run(Game *game, Graphic_engine *gengine,FILE *log_file)
 {
   Command *last_cmd;
   Status st;
 
   if (!gengine)
   {
     return;
   }
 
   last_cmd = game_get_last_command(game);
 
   while ((command_get_code(last_cmd) != EXIT) && (game_get_finished(game) == FALSE))
   {
     graphic_engine_paint_game(gengine, game);
     command_get_user_input(last_cmd);
     game_actions_update(game, last_cmd);
     st=command_get_exit(last_cmd);
     if(log_file!=NULL){

        switch(command_get_code(last_cmd)) {
        case UNKNOWN:
            fprintf(log_file,"Unknown:");
            break;
        case EXIT:
            fprintf(log_file,"Exit:");
            break;
        case MOVE:
            fprintf(log_file,"Move %s:",command_get_argument(last_cmd));
            
            break;
        case TAKE:
            fprintf(log_file,"Take %s:",command_get_argument(last_cmd));
            break;
        case DROP:
            fprintf(log_file,"Drop %s:",command_get_argument(last_cmd));
            break;
        case ATTACK:
            fprintf(log_file,"Attack:");
            break;
        case CHAT:
            fprintf(log_file,"Chat:");
            break;
        default:
            fprintf(log_file,"Invalid command code:");
            break;
    }
       if(st==OK){
        fprintf(log_file,"OK\n");
       }
       else{
        fprintf(log_file,"ERROR\n"); 
       }
 
     }
   }
 }
 
 void game_loop_cleanup(Game *game, Graphic_engine *gengine)
 {
   game_destroy(game);
   graphic_engine_destroy(gengine);
 }