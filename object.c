/**
 * @brief Implementa el módulo de objetos
 *
 * @file object.c
 * @author XINYI HUANG
 * @version 0
 * @date 31-01-2025
 * @copyright GNU Public License
 */

#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------------------------------------*/
/**
 * @brief Object
 *
 * Esta estructura guarda toda la información de un objeto
 */
struct _Object
{
    Id id;                          /*!< Identificador del objeto*/
    char name[WORD_SIZE+1];         /*!< Nombre del objeto*/
    Id location;
};
/*-----------------------------------------------------------------------------------------------------*/

Object *object_create(Id id){
    Object *obj=NULL;

    /*Cde*/
    if(id == NO_ID)
        return NULL;

    /*Reserva de memoria*/
    obj = (Object*) malloc(sizeof(Object));
    if(!obj)
        return NULL;

    /*Inicializar valores vacías*/
    obj->id = id;
    obj->name[0]='\0';
    obj->location = NO_ID;

    return obj;
}

Status object_destroy(Object* obj){
    /*Cde*/
    if(!obj)
        return ERROR;

    free(obj);
    obj = NULL;
    return OK;
}
/*-----------------------------------------------------------------------------------------------------*/

Id object_get_id(Object *obj){

    if(!obj)
        return NO_ID;
    
    return obj->id;
}
/*-----------------------------------------------------------------------------------------------------*/

Status object_set_name(Object *obj, char *name){
    /*Cde*/
    if(!obj || !name)
        return ERROR;

    /*Copiar el nombre*/
    if(!strcpy(obj->name, name))
        return ERROR;

    return OK;
}

char* object_get_name(Object* obj){
    if(!obj)
        return NULL;

    return obj->name;
}

/*-----------------------------------------------------------------------------------------------------*/
Status object_print(Object *obj){

    if(!obj)
        return ERROR;

    fprintf(stdout, "---> Object (Id: %ld; Name: %s)\n", obj->id, obj->name);

    return OK;
}

Status object_set_location(Object *obj, Id location){
    if(!obj)
        return ERROR;

    obj->location = location;

    return OK;
}
Id object_get_location(Object *obj){
    if(!obj)
        return NO_ID;

    return obj->location;
}




