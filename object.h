
#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

Object* object_create(Id id);

Status object_destroy(Object *obj);

Id object_get_id(Object *obj);

Status object_set_name(Object *obj, char *name);

Status object_print(Object* obj);


#endif