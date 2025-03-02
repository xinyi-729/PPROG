#ifndef SET_H
#define SET_H

#include "types.h"
#include "object.h"

#define MAX_OBJECTS 50

typedef struct _Set Set;

Set *set_create();

Status set_destroy(Set *set);


Id set_get_id(Set *set, Id id);

int set_get_n_ids(Set *set);

/*Este add sustituye al set_id*/
Status set_add(Set *set, Id id);

Status set_del(Set *set, Id id);
Bool set_has(Set *set, Id id);

Status print(Set *set);


#endif