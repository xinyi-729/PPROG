/**
 * @brief It implements a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

 #include "graphic_engine.h"

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #include "command.h"
 #include "libscreen.h"
 #include "space.h"
 #include "types.h"
 
 #define WIDTH_MAP 67
 #define WIDTH_DES 40
 #define WIDTH_BAN 23
 #define HEIGHT_MAP 25
 #define HEIGHT_BAN 1
 #define HEIGHT_HLP 3
 #define HEIGHT_FDB 3
 
 #define NUM_COLUMN_SPACE 17
 #define NUM_ROW_SPACE 9
 
 struct _Graphic_engine
 {
   Area *map, *descript, *banner, *help, *feedback;
 };
 
 void graphic_eng_paint_space(Graphic_engine *ge, Game *game, Id id);
 void get_all_obj_name(Game *game, Space *space, char *all_obj);
 
 /*DEVUelve un str del id dado*/
 char *graphic_space_line(Game *game, Id id, int n_line);
 void graphic_eng_next_back(Graphic_engine *ge, Game *game, Id id);
 /*--------------------------------------------------------------------- */
 Graphic_engine *graphic_engine_create()
 {
   static Graphic_engine *ge = NULL;
 
   if (ge)
   {
     return ge;
   }
 
   screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 4, WIDTH_MAP + WIDTH_DES + 3);
   ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
   if (ge == NULL)
   {
     return NULL;
   }
 
   ge->map = screen_area_init(1, 1, WIDTH_MAP, HEIGHT_MAP);
   ge->descript = screen_area_init(WIDTH_MAP + 2, 1, WIDTH_DES, HEIGHT_MAP);
   ge->banner = screen_area_init((int)((WIDTH_MAP + WIDTH_DES + 1 - WIDTH_BAN) / 2), HEIGHT_MAP + 2, WIDTH_BAN, HEIGHT_BAN);
   ge->help = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + 2, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_HLP);
   ge->feedback = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 3, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_FDB);

   return ge;
 }
 
 void graphic_engine_destroy(Graphic_engine *ge)
 {
   if (!ge)
     return;
 
   screen_area_destroy(ge->map);
   screen_area_destroy(ge->descript);
   screen_area_destroy(ge->banner);
   screen_area_destroy(ge->help);
   screen_area_destroy(ge->feedback);
 
   screen_destroy();
   free(ge);
 }
 /*******************************************************************************************************************++ */
 void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
 {
   Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID;
   Space *space_act = NULL, *aux;
   char str[255], all_obj[128] = "";
   CommandCode last_cmd = UNKNOWN;
   extern char *cmd_to_str[N_CMD][N_CMDT];
   int i, j;
   Character *character = NULL;

   int k;
   /* Paint the in the map area */
   screen_area_clear(ge->map);
   if ((id_act = game_get_player_location(game)) != NO_ID)
   {
 
     space_act = game_get_space(game, id_act);
 
     id_back = game_get_connection(game, space_get_id(space_act), N);
     id_next = game_get_connection(game, space_get_id(space_act), S);
 
     if (id_back != NO_ID)
     {
       graphic_eng_next_back(ge, game, id_back);
       sprintf(str, "                         ^");
       screen_area_puts(ge->map, str);
     }

 
     if (id_act != NO_ID)
     {
       graphic_eng_paint_space(ge, game, id_act);
     }

     if (id_next != NO_ID)
     {
       sprintf(str, "                        v");
       screen_area_puts(ge->map, str);
       graphic_eng_next_back(ge, game, id_next);
     }
   }

   /* Paint in the description area */
   screen_area_clear(ge->descript);
   get_all_obj_name(game, space_act, all_obj);
 
   sprintf(str, "  Objects: ");
   screen_area_puts(ge->descript, str);

   for (i = 0; i < game_get_numobj(game); i++)
   {
     for (j = 0; j < game_get_numspaces(game); j++)
     {
      aux = game_get_space_at(game, j);
      if(aux == NULL)
        printf("es null\n");
       if(space_has_object(game_get_space_at(game, j), game_get_object_id_at(game, i)) == TRUE){
         sprintf(str, "    %s: %ld ", game_get_object_name(game, game_get_object_id_at(game, i)), game_get_space_id_at(game, j));
         printf("    %s: %ld \n",  game_get_object_name(game, game_get_object_id_at(game, i)), game_get_space_id_at(game, j));

         screen_area_puts(ge->descript, str);

       }

     }

   }
 
   sprintf(str, "           ");
   screen_area_puts(ge->descript, str);
   sprintf(str, "            ");
   screen_area_puts(ge->descript, str);
 
   sprintf(str, "  Characters: ");
   screen_area_puts(ge->descript, str);
 
   for (i = 0; i < game_get_numspaces(game); i++)
   {
     character = game_get_character(game, game_get_space_id_at(game, i));
     if (character_get_id(character) != NO_ID)
     {
       sprintf(str, "    %s: %ld (%d)", character_get_graphic_description(character), game_get_space_id_at(game, i), character_get_health(character));
     }
     
   }

   sprintf(str, "           ");
   screen_area_puts(ge->descript, str);
   sprintf(str, "           ");
   screen_area_puts(ge->descript, str);
 
   sprintf(str, "  Player: %ld (%d)", id_act, player_get_health(game_get_player(game)));
   screen_area_puts(ge->descript, str);
 
   /* Paint in the banner area */
   screen_area_puts(ge->banner, "    The anthill game ");
 
   /* Paint in the help area */
   screen_area_clear(ge->help);
   sprintf(str, " The commands you can use are:");
   screen_area_puts(ge->help, str);
   sprintf(str, "     next or n, back or b, exit or e, left or l, right or r, take or t, drop or d, attack or a, chat or c");
   screen_area_puts(ge->help, str);
 
   /* Paint in the feedback area */
   last_cmd = command_get_code(game_get_last_command(game));
   sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
   screen_area_puts(ge->feedback, str);
 
   /* Dump to the terminal */
   screen_paint();
   printf("prompt:> ");

 }
 
 void graphic_eng_paint_space(Graphic_engine *ge, Game *game, Id id)
 {
   Id id_act = NO_ID, id_east = NO_ID, id_west = NO_ID;
   char vacio[255] = "                  ";
   Space *space_act;
   int i;
   char *aux, *str = malloc(1), *cde;
 
   if (!str)
     return;
 
   str[0] = '\0';
   id_act = game_get_player_location(game);
   space_act = game_get_space(game, id_act);
 
   id_east = game_get_connection(game, space_get_id(space_act), E);
   id_west = game_get_connection(game, space_get_id(space_act), W);
 
   if (id_act != NO_ID)
   {
     /*concatena las lineas*/
     for (i = 0; i < NUM_ROW_SPACE; i++)
     {
       str[0] = '\0'; /*REINICIAR LA MEMORIA*/
 
       if (id_west != NO_ID)
       {
         aux = graphic_space_line(game, id_west, i);
         cde = realloc(str, strlen(str) + strlen(aux) + 1);
         if (!cde) {
           free(aux);
           free(str);
           return;
         }
         str = cde;
         strcat(str, aux);
         free(aux);
       }
       else
       {
        cde = realloc(str, strlen(str) + strlen(vacio) + 1);
        if (!cde){
          printf("Error: realloc falló\n");
          free(str);
          return;
        }
         str = cde;
         strcat(str, vacio);
       }
 
       if (id_act != NO_ID)
       {
 
         aux = graphic_space_line(game, id_act, i);
         cde = realloc(str, strlen(str) + strlen(aux) + 1);
         if (!cde) {
           free(aux);
           free(str);
           return;
         }
         str = cde;
         strcat(str, aux);
         free(aux);
       }
 
       if (id_east != NO_ID)
       {
         aux = graphic_space_line(game, id_east, i);
         cde = realloc(str, strlen(str) + strlen(aux) + 1);
         if (!cde) {
           printf("Error: realloc falló\n");
           free(aux);
           free(str);
           return;
         }
         str = cde;
         strcat(str, aux);
         free(aux);
       }
       else
       {
         cde = realloc(str, strlen(str) + strlen(vacio) + 1);
         if (!cde){
           printf("Error: realloc falló\n");
           free(str);
           return;
         }
         str = cde;
         strcat(str, vacio);
       }
 
       screen_area_puts(ge->map, str);
     }
   }
 
   if (str != NULL)
     free(str);
 }
 
 char *graphic_space_line(Game *game, Id id, int n_line)
 {
   Id id_player;
   int n_obj;
   Space *space = NULL;
   char *str = malloc(128), all_obj[64] = "";
 
   if (!str)
     return NULL;
 
   if (!game || id == NO_ID)
   {
     free(str);
     return NULL;
   }
 
   id_player = game_get_player_location(game);
 
   space = game_get_space(game, id);
   if (!space)
   {
     free(str);
     return NULL;
   }
 
   if (n_line == 0 || n_line == 8)
   {
     sprintf(str, "+---------------+  ");
   }
   else if (n_line == 1)
   {
     if (id_player == id)
     {
       sprintf(str, "| m0^        %3d|  ", (int)id);
     }
     else
     {
       sprintf(str, "|            %3d|  ", (int)id);
     }
   }
   else if (n_line >= 2 && n_line <= 6)
   { /*La parte de descr, las lineas 2,3,4,5,6*/
     sprintf(str, "|%s      |  ", space_get_gdesc(space, n_line - 2));
   }
   else if (n_line == 7)
   {
     n_obj = set_get_n_ids(space_get_object(space));
     if (n_obj > 0)
     {
       get_all_obj_name(game, space, all_obj);
       /*Imprime todos los objetos que haya*/
       sprintf(str, "|%-*s|  ", NUM_COLUMN_SPACE - 2, all_obj);
     }
     else
     {
       sprintf(str, "|               |  ");
     }
   }
   else
   {
     free(str);
     return NULL;
   }
   return str;
 }
 
 void get_all_obj_name(Game *game, Space *space, char *all_obj)
 {
   int n_objs, i;
   char *aux_obname = NULL;
   Id obj_id_i = NO_ID;
   Object *ob = NULL;
 
   if (!game || !space)
     return;
 
   n_objs = set_get_n_ids(space_get_object(space));
   if (n_objs < 0)
   {
     return;
   }
 
   all_obj[0] = '\0';
 
   /*Guardo el nombre de los objetos obtenidos en all_obj usando strcat, que concadena */
   for (i = 0; i < n_objs; i++)
   {
     /*Obtengo el id del objeto en la posicion 0,1,2,3,...*/
     obj_id_i = space_get_objetc_id_at(space, i);
 
     /*Con el id obtengo el objeto * */
     ob = game_get_object(game, obj_id_i);
     aux_obname = object_get_name(ob);
 
     strcat(all_obj, aux_obname);
     strcat(all_obj, " ");
   }
 
   if (strlen(all_obj) > 0)
   {
     all_obj[strlen(all_obj) - 1] = '\0';
   }
 
   return;
 }
 
 void graphic_eng_next_back(Graphic_engine *ge, Game *game, Id id)
 {
   Id id_act = NO_ID;
   char all_obj[128] = "", str[255];
   Space *space_act;
   int n_obj, i;
   char *aux_gdesc = NULL;
   char str_space[GDESC_ROWS][GDESC_COLS];
 
   id_act = game_get_player_location(game);
 
   if (id_act != NO_ID)
   {
 
     space_act = game_get_space(game, id);
 
     /*conseguir las 5 lineas del espacio*/
     for (i = 0; i < GDESC_ROWS; i++)
     {
       aux_gdesc = space_get_gdesc(space_act, i);
       strcpy(str_space[i], aux_gdesc);
     }
 
     /*En all_obj está guardado todos los nombres de objetos
       En str_space las 5 lineas de descripciones*/
 
     sprintf(str, "                  +---------------+  ");
     screen_area_puts(ge->map, str);
 
     if (id == id_act)
     {
       sprintf(str, "                  | m0^        %3d|  ", (int)id);
       screen_area_puts(ge->map, str);
     }
     else
     {
       sprintf(str, "                  |            %3d|  ", (int)id);
       screen_area_puts(ge->map, str);
     }
 
     for (i = 0; i < GDESC_ROWS; i++)
     {
       sprintf(str, "                  |%s      |  ", str_space[i]);
       screen_area_puts(ge->map, str);
     }
 
     /*printear objetos*/
     n_obj = set_get_n_ids(space_get_object(space_act));
     if (n_obj > 0)
     {
       get_all_obj_name(game, space_act, all_obj);
       if (all_obj[0] == '\0')
       {
         printf("error en all_obj\n");
       }
       /*Imprime todos los objetos que haya*/
       sprintf(str, "                  |%-*s|  ", NUM_COLUMN_SPACE - 2, all_obj); /*ya veré si da tiempo de hacerla bonita */
       screen_area_puts(ge->map, str);
       sprintf(str, "                  +---------------+  ");
       screen_area_puts(ge->map, str);
     }
     else
     {
       sprintf(str, "                  |               |  ");
       screen_area_puts(ge->map, str);
       sprintf(str, "                  +---------------+  ");
       screen_area_puts(ge->map, str);
     }
   }
 }