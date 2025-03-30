/**
 * @brief It implements the inventory module interface
 *
 * @file inventory.c
 * @author Lucía Ordovás
 * @version 1
 * @date 27-02-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "set.h"


#define MAX_BACKPACK 10

struct _Inventory
{
    Set *objs;
    int max_objs;
};

/*--------------------------------------------------------------------*/
Inventory *inventory_create()
{
    Inventory *inventory = (Inventory *)malloc(sizeof(Inventory));
    if (inventory == NULL)
        return NULL;

    inventory->objs = set_create();
    if (inventory->objs == NULL)
    {
        free(inventory);
        return NULL;
    }

    inventory->max_objs = MAX_BACKPACK;

    return inventory;
}

void inventory_destroy(Inventory *inventory)
{

    set_destroy(inventory->objs);
    free(inventory);
}

/*----------------------------------------------------------------*/
Status inventory_add(Inventory *inventory, Id obj_id)
{
    if (inventory == NULL)
        return ERROR;

    if (set_add(inventory->objs, obj_id) == ERROR)
        return ERROR;

    return OK;
}

Status inventory_del(Inventory *inventory, int obj_id)
{
    if (inventory == NULL)
        return ERROR;

    if (set_del(inventory->objs, obj_id) == ERROR)
        return ERROR;

    return OK;
}

/*-------------------------------------------------------------*/
int inventory_get_max_objs(Inventory *inventory)
{
    if (inventory == NULL)
        return -1;

    return inventory->max_objs;
}

/*DIJO LA PROFE QUE NO SE PUEDE USAR ESTO*/
// Set *inventory_get_objs(Inventory *inventory)
// {
//     if (inventory == NULL)
//         return NULL;

//     return inventory->objs;
// }

Id inventory_get_obj_id(Inventory *inv, int pos){
    Id obj;
    if(!inv || pos<0 || pos>= MAX_BACKPACK)
        return NO_ID;
    
    obj = set_get_id(inv->objs, pos);
    return obj;
}

/*---------------------------------------------------------------*/

Bool inventory_has_object(Inventory *inventory, Id id)
{
    return set_has(inventory->objs, id);
}

Bool inventory_is_full(Inventory *inventory)
{
    if (inventory == NULL)
    {
        return TRUE;
    }

    if (set_get_n_ids(inventory->objs) >= inventory->max_objs)
    {
        return TRUE;
    }

    return FALSE;
}

Bool inventory_is_empty(Inventory *inventory)
{
    if (inventory == NULL)
    {
        return TRUE;
    }

    if (set_get_n_ids(inventory->objs) == 0)
    {
        return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------*/

Status inventory_print(Inventory *inventory)
{
    if (inventory == NULL)
        return ERROR;

    fprintf(stdout, "Inventory: \n");
    fprintf(stdout, "--> Inventory (max_objs: %d):\n", inventory->max_objs);
    if (set_print(inventory->objs) == ERROR)
    {
        return ERROR;
    }

    return OK;
}

int inventory_get_n_obj(Inventory *inv){
    if(!inv)
        return -1;
    
    if(inventory_is_empty(inv) == TRUE)
        return 0;
    

    return set_get_n_ids(inv->objs);
}
