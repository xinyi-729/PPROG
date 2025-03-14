#include "set.h"

#include <stdio.h>
#include <stdlib.h>

struct _Set{
    Id *ids;
    int n_ids;
};
/********FUNCIONES PRIVADOS********************** */



Bool set_is_empty(Set *set);

Bool set_is_full(Set *set);
/******************************** */

/*Recibe un número de ids para iniciazar?*/
Set *set_create(){
    Set *s=NULL;

    s = (Set*) malloc(1*sizeof(Set));
    if(!s)
        return NULL;

    s->ids = (Id*) malloc(MAX_OBJECTS * sizeof(Id));
    if(!s->ids){
        free(s);
        return NULL;
    }
    
    s->n_ids = 0;
    return s;
}

Status set_destroy(Set *set){
    if(!set)
        return ERROR;

    if(set->ids)
        free(set->ids);

    free(set);
    return OK;
}

Id set_get_id(Set *set, int pos){
    if(!set)
        return NO_ID;

    return set->ids[pos];
}


int set_get_n_ids(Set *set){
    if(!set)
        return -1;
    
    return set->n_ids;
}


Status set_add(Set *set, Id id){

    if(!set)
        return ERROR;

    if(set_has(set, id) == TRUE)
        return OK;


    set->ids[set->n_ids] = id;
    set->n_ids += 1;
    return OK;
}

Status set_del(Set *set, Id id){
    int i;

    if(!set)
        return ERROR;

    if(set_is_empty(set) == TRUE)
        return ERROR;

    for (i=0; i<set->n_ids; i++){
        if(set->ids[i] == id){
            /*mover el ultimo al hueco*/
            set->ids[i] = set->ids[set->n_ids-1];
            set->n_ids -= 1;
            break;/*salir del bucle, no tiene sentido seguir buscando*/
        }
    }
        
    return OK;
}

Bool set_has(Set *set, Id id){
    int i;

    /*Buscar en el array si está este id*/
    for(i=0; i<set->n_ids; i++){
        if(set->ids[i] == id){
            return TRUE;
        }
    }

    return FALSE;
}

Bool set_is_empty(Set *set){
    if(set->n_ids == 0)
        return TRUE;

    return FALSE;
}

Bool set_is_full(Set *set){

    if(set->n_ids >= MAX_OBJECTS)
        return TRUE;

    return FALSE;
}

/*-------------------------------------------------------------*/
Status set_print(Set *set){
    int i;

    if(!set)
        return ERROR;

    fprintf(stdout, "--> Set (ids:[");
    for(i=0; i<set->n_ids;i++){
        fprintf(stdout, " %ld", set->ids[i]);
    }
    fprintf(stdout, "\n]; Num_ids: %d)\n", set->n_ids);

    return OK;
}