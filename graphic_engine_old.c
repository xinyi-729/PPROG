/**
 * @brief Implementa un motor grafico textual
 *
 * @file graphic_engine.c
 * @author Xinyi Huang y Lucia Ordovas
 * @version 0
 * @date 30-01-2025
 * @copyright GNU Public License
 */

 /*------------------------------------------------------------*/
#include "graphic_engine.h"
#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#include "game_actions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define WIDTH_MAP 48
#define WIDTH_DES 29
#define WIDTH_BAN 23
#define HEIGHT_MAP 13
#define HEIGHT_BAN 1
#define HEIGHT_HLP 2
#define HEIGHT_FDB 3
/*------------------------------------------------------------*/
/**
 * @brief Estructura de datos que representa el motor gráfico
 * @author Xinyi Huang y Lucia Ordovas
 */
struct _Graphic_engine {
  Area *map, *descript, *banner, *help, *feedback;
};

/*Funcion privada*/

/**FUNCION Q TE DIGA SI EL NOMBRE DEL OBJETO SE PASA DEL RANGO */
Bool length_in_range(char *obj_name, int length);

/*------------------------------------------------------------*/
Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge) {
    return ge;
  }

  screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 4, WIDTH_MAP + WIDTH_DES + 3);
  ge = (Graphic_engine *)malloc(sizeof(Graphic_engine));
  if (ge == NULL) {
    return NULL;
  }

  ge->map = screen_area_init(1, 1, WIDTH_MAP, HEIGHT_MAP);
  ge->descript = screen_area_init(WIDTH_MAP + 2, 1, WIDTH_DES, HEIGHT_MAP);
  ge->banner = screen_area_init((int)((WIDTH_MAP + WIDTH_DES + 1 - WIDTH_BAN) / 2), HEIGHT_MAP + 2, WIDTH_BAN, HEIGHT_BAN);
  ge->help = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + 2, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_HLP);
  ge->feedback = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 3, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_FDB);

  return ge;
}

/*------------------------------------------------------------*/
void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge) return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

/*------------------------------------------------------------*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_west=NO_ID, id_east =NO_ID, obj_loc = NO_ID, obj_id=NO_ID;
  Space *space_act = NULL;
  char aux[128] = "", all_name[128] = "";
  char str[255];
  CommandCode last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  Command *cmd=NULL;
  char *cmd_argument, *aux_str;
  Player *player= NULL;
  Id *objects_set=NULL;
  Set *set_space=NULL;
  int n_obj, k, i;
  char string[5][64],aux_s[5][10]; 
  char form_character[11];

  // char character_message[]=game_actions_chat(game);

  player = game_get_player(game);


  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = player_get_location(player)) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_west = space_get_west(space_act);
    id_east = space_get_east(space_act);

    objects_set = set_get_ids(set_space);

    // if (game_get_object_location(game, obj_id) == id_back)
    //   obj = '*';
    // else
    //   obj = ' ';

    if (id_back != NO_ID) {
      sprintf(str, "               |               %3d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "               +------------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                       ^    (%d)",(int)id_back);
      screen_area_puts(ge->map, str);
      // sprintf(str, "        ^");
      // screen_area_puts(ge->map, str);
    }
    else{
      sprintf(str, "      hola       ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                 ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                 ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                 ");
      screen_area_puts(ge->map, str);
    }

    /*Si en el espacio actual existe el conjunto, conseguimos el numero de objectos q hay*/
    if((set_space = space_get_set(game_get_space(game, id_act))) != NULL){
      n_obj = set_get_n_ids(set_space);
    }
    else
      n_obj = 0;

    //Falta la  condicion para caracter

    k = set_get_n_ids(set_space);
    objects_set = set_get_ids(space_get_set(space_act));
    /**???????? así ???? no seguro, falta investigar */
    for(i=0; i<k; i++){
      sprintf(aux, "%s ", object_get_name(game_get_object(game, objects_set[i])));
      strcat(all_name, aux);

    }

    // num = abs(lenth - strlen(all_name));

    // str_lenth = strlen(all_name);
    //   for(i = 0 ;i<num;i++)
    //     strcat(all_name," ");
      
    // all_name[str_lenth+num] = '\0';

    if (id_act != NO_ID){
      sprintf(string[0],"               +------------------+");
      sprintf(string[1], "               |m0^ %s     %3d|", form_character, (int)id_act); 

      // for(i=0; i<5; i++){
      //   aux_str = space_get_string_at(space_act,i);
      //   strcpy(aux_s[i],aux_str);
      // }

      sprintf(str, "               |%s|",all_name);/*cadena para objetos*/ /*NO TOCAR!!!!!*/
      sprintf(string[4], "               +------------------+");

      if(id_west != NO_ID){
        memcpy(string[0]+9,"  --+",strlen("  --+"));
        memcpy(string[1]+9,"   <|",strlen("   <|"));
        memcpy(str+9,"    |",strlen("    |"));
        memcpy(string[2]+9,"    |",strlen("    |"));
        memcpy(string[3]+9,"    |",strlen("    |"));
        memcpy(string[4]+9,"  --+",strlen("  --+"));

      }

      if(id_east != NO_ID){
        memcpy(string[0]+35,"  +--",strlen("         +--"));
        memcpy(string[1]+35," >| ",strlen("         >| "));  
        memcpy(str+35,"  | ",strlen("          | "));
        memcpy(string[3]+35,"  | ",strlen("          | "));
        memcpy(string[4]+35,"  +--",strlen("         +--"));

      }

      // screen_area_puts(ge->map, string[0]);
      // screen_area_puts(ge->map, string[1]);
      // for(i=0;i<5;i++) {
      //   sprintf(description,"               |%s         |",aux_s[i]);
      //   screen_area_puts(ge->map,description);
      // }
      // screen_area_puts(ge->map, str);
      // /*screen_area_puts(ge->map,str3);*/
      // screen_area_puts(ge->map, string[4]);
    }
    if (id_next != NO_ID) {
      sprintf(str, "                       v    (%d)",(int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "               +------------------+");
      screen_area_puts(ge->map, str);
    }

  }
  
   /* Pintar en el area de descripcion */
  screen_area_clear(ge->descript);
  if ((obj_loc = game_get_object_location(game, obj_id)) != NO_ID) {
    sprintf(str, "  Object location:%d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }
  else{
    sprintf(str, "The player has the object");
    screen_area_puts(ge->descript, str);
  }



   /* Pintar en el area de banner */
  screen_area_puts(ge->banner, "    The anthill game ");

   /* Pintar en el area de ayuda */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, exit or e, take or t, drop or d");
  screen_area_puts(ge->help, str);

   /* Pintar en el area de retroalimentacion */
  last_cmd = command_get_code(cmd);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

   /* Mostrar en la terminal */
  screen_paint();
  printf("prompt:> ");
}

Bool length_in_range(char *obj_name, int length);