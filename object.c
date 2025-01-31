#include "object.h"


#include <stdio.h>
#include <stdlib.h>

struct _Object
{
    Id id;
    char name[WORD_SIZE+1];
};


/*********PREGUNTA: ¿El object tmb se inicializa recibiendo un id? */
Object *object_create(Id id){
    Object *obj=NULL;

    /*Cde*/
    if(id == NULL)
        return NULL;

    /*Reserva de memoria*/
    obj = (Object*) malloc(sizeof(Object));
    if(!obj)
        return NULL;

    /*Inicializar valores vacías*/
    obj->id = id;
    obj->name[0]='\0'; 

    return obj;
}

Status object_destroy(Object* obj){
    if(obj == NULL)
        return ERROR;

    free(obj);
    obj = NULL;
    return OK;
}

Id object_get_id(Object *obj){

    if(!obj)
        return NO_ID;
    
    return obj->id;
}

Status object_set_name(Object *obj, char *name){
    int c;
    if(!obj || !name)
        return ERROR;

    if(!strcpy(obj->name, name))
        return ERROR;

    return OK;
}
/************NO ESTOY SEGURO DE QUE ESTO SE ACABA ASÍ */

Status object_print(Object *obj){
    Id aux=NO_ID;

    if(!obj)
        return ERROR;

    fprintf(stdout, "---> Object (Id: %ld; Name: %s)\n", obj->id, obj->name);

    return OK;
}



