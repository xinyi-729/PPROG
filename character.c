/**
 * @brief Implementa el modulo del caracter
 *
 * @file character.c
 * @author Lucia Ordovas
 * @version 0
 * @date 31-01-2025
 * @copyright Licencia Publica GNU
 */

 #include "character.h"

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define GDESC_SIZE 6
  
 /*-----------------------------------------------------------------------------------------------------*/
 /**
   * @brief Caracter
   *
   * Esta estructura almacena toda la informacion sobre el caracter
 */
 struct _Character {
     Id id;                    /* ID del caracter, unico */
     char name[WORD_SIZE + 1]; /* Nombre del caracter */
     char gdesc[GDESC_SIZE + 1]; /* Descripcion grafica del caracter */
     long health; /* Numero de puntos de vida */
     Bool friendly; /* TRUE si es amigo */
     char message[WORD_SIZE +1]; /* Almacena un mensaje */
 };
 
 /*-----------------------------------------------------------------------------------------------------*/
 /* Funciones implementadas*/
 
 /* Creacion e inicializacion de un caracter */
 Character* character_create(Id id) {
     Character* newCharacter = NULL;
   
     /* Control de errores de los parametros */
     if (id == NO_ID) return NULL;
   
     /* Reserva de memoria dinamica */
     newCharacter = (Character*)malloc(sizeof(Character));
     if (newCharacter == NULL) {
       return NULL;
     }
   
     /* Inicializacion */
     newCharacter->id = id;
     newCharacter->name[0] = '\0';
     newCharacter->gdesc[0] = '\0';
     newCharacter->health=0;
     newCharacter->friendly=TRUE;
     newCharacter->message[0]= '\0';
   
     return newCharacter;
   }
   
   Status character_destroy(Character* character) {
     /*Control de errores*/
     if (!character) {
       return ERROR;
     }
   
     free(character);
     character = NULL;
     return OK;
 }
   
   /*-----------------------------------------------------------------------------------------------------*/
   Id character_get_id(Character* character) {
     /* Control de errores */
     if (!character) {
       return NO_ID;
     }
     return character->id;
   }
   
   /*-----------------------------------------------------------------------------------------------------*/
   Status character_set_name(Character* character, char* name) {
     /*Cde*/
     if (!character || !name) {
       return ERROR;
     }
   
     if (!strcpy(character->name, name)) {
       return ERROR;
     }
     return OK;
   }
   
   const char* character_get_name(Character* character) {
     /* Control de errores */
     if (!character) {
       return NULL;
     }
     return character->name;
   }
   /*-----------------------------------------------------------------------------------------------------*/
   Status character_set_description(Character* character, char* gdesc) {
     /*Cde*/
     if (!character || !gdesc) {
       return ERROR;
     }
   
     if (!strcpy(character->gdesc, gdesc)) {
       return ERROR;
     }
 
     return OK;
   }
 
   const char* character_get_description(Character* character) {
     /* Control de errores */
     if (!character) {
       return NULL;
     }
 
     return character->gdesc;
   }
 
   /*-----------------------------------------------------------------------------------------------------*/
   Status character_set_health(Character *character, long value){
     /* Cde */
     if(!character||value<0){
       return ERROR;
     }
 
     character->health=value;
 
     return OK;
   }
 
   long character_get_health(Character *character){
     /* Cde */
     if(!character||character->health<0){
       return -1;
     }
 
     return character->health;
   }
 
   /*-----------------------------------------------------------------------------------------------------*/
   Status character_set_is_friendly(Character *character, Bool value){
     if(!character){
       return ERROR;
     }
 
     character->friendly=value;
 
     return OK;
   }
 
   Bool character_get_is_friendly(Character *character){
     if(!character){
       return FALSE;
     }
 
     return character->friendly;
   }
 
   /*-----------------------------------------------------------------------------------------------------*/
   Status character_set_message(Character *character, char *message){
     if(!character||!message){
       return ERROR;
     }
 
     if(!strcpy(character->message,message)){
       return ERROR;
     }
 
     return OK;
   }
 
   char * character_get_message(Character *character){
     if(!character){
       return NULL;
     }
 
     return character->message;
   }
 
 
   /*-----------------------------------------------------------------------------------------------------*/
   Status character_player_print(Character *character) {
     /* Control de errores */
     if (!character||!character->message) {
       return ERROR;
     }
   
     /* Mostramos el id, nombre, descripcion, salud, si es amigo y mensaje */
     fprintf(stdout, "--> Character (Id: %ld; Name: %s; Graphic description:%s; Health: %ld; ", character->id, character->name, character->gdesc, character->health);
     
     if(character_get_is_friendly(character)==TRUE){
       fprintf(stdout, "Friendly:yes; ");
     }
     else{
       fprintf(stdout, "Friendly:no; ");
     }
     
     fprintf(stdout, "Message:%s \n",character->message);
   
     return OK;
   }