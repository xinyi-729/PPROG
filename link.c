/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author David Buendía
 * @version 1
 * @date 20-03-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"
#include "types.h"

struct _link
{
    Id id;
    Id origin;
    Id dest;
    Direction direction;
    char name[WORD_SIZE + 1];
    Bool open;  /*TRUE-> abierto  FALSE->cerrado*/
};

link *link_create(Id id)
{

    link *newlink = NULL;

    if (id == NO_ID)
    {
        return NULL;
    }

    newlink = (link *)malloc(sizeof(link));
    if (newlink == NULL)
    {
        return NULL;
    }

    newlink->id = id;
    newlink->name[0] = '\0';
    newlink->direction = NOTKNOWN;
    newlink->origin = NO_ID; 
    newlink->dest = NO_ID; 
    newlink->open = FALSE;

    return newlink;
}

void link_destroy(link *link)
{
    free(link);
    link = NULL;
}

Id link_get_id(link *link)
{

    if (!link)
    {
        return NO_ID;
    }

    return link->id;
}

Status link_set_id(link *link, Id id)
{
    if (!link || id == NO_ID)
    {
        return ERROR;
    }

    link->id = id;

    return OK;
}

Id link_get_originID(link *link)
{

    if (link == NULL)
    {
        return NO_ID;
    }

    return link->origin;
}

Status link_set_originID(link *link, Id id)
{
    if (!link)
    {
        return ERROR;
    }

    link->origin = id;

    return OK;
}

Id link_get_destID(link *link)
{

    if (!link)
    {
        return NO_ID;
    }

    return link->dest;
}

Status link_set_destID(link *link, Id id)
{
    if (!link || id == NO_ID)
    {
        return ERROR;
    }

    link->dest = id;

    return OK;
}

char *link_get_name(link *link)
{

    if (!link)
    {
        return NULL;
    }

    return link->name;
}

Status link_set_name(link *link, char *name)
{
    if (!link || !name)
    {
        return ERROR;
    }

    if (!strcpy(link->name, name))
    {
        return ERROR;
    }
    return OK;
}

Bool link_is_open(link *link)
{
    if (link == NULL || link_get_id(link) == NO_ID)
    {
        return ERR;
    }

    return link->open;
}

Status link_set_open(link *link, Bool open)
{
    if (link == NULL || (open != 1 && open != 0))
    {
        return ERROR;
    }

    link->open = open;
    return OK;
}

Direction link_get_direction(link *link)
{
    if (link == NULL || link_get_id(link) == NO_ID)
    {
        return NOTKNOWN;
    }

    return link->direction;
}

Status link_set_direction(link *link, Direction direction)
{
    if (link == NULL || (direction != 0 && direction != 1 && direction != 2 && direction != 3 && direction != 4))
    {
        return ERROR;
    }

    link->direction = direction;
    return OK;
}

Status link_print(const link *link)
{
    char open[9];
    char direction[9];

    if (!link)
        return ERROR;

    if (link->open == TRUE)
    {
        strcpy(open, "YES");
    }
    else
    {
        strcpy(open, "NO");
    }

    switch (link->direction)
    {
    case NOTKNOWN:
        strcpy(direction, "NOTKNOWN");
        break;

    case N:
        strcpy(direction, "north");
        break;

    case S:
        strcpy(direction, "south");
        break;

    case E:
        strcpy(direction, "east");
        break;

    case W:
        strcpy(direction, "west");
        break;

    default:
        break;
    }

    printf("link ID: %ld, Name: %s, Opened?: %s, Origin: %ld, Destination: %ld, Direction: %s\n", link->id, link->name, open, link->origin, link->dest, direction);
    return OK;
}