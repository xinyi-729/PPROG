/**
 * @brief Tests para el modulo Inventory
 * 
 * @file inventory_test.c
 * @version 0.0 
 * @date 17-02-2025
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "inventory.h"
 #include "test.h"
 #include "inventory_test.h"

 #define MAX_TESTS 10

  /** 
  * @brief Main function for inventory unit tests. 
  * 
  * You may execute ALL or a SINGLE test
  *   1.- No parameter -> ALL test are executed 
  *   2.- A number means a particular test (the one identified by that number) 
  *       is executed
  *  
  */

  int main(int argc, char** argv) {
    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Character:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 || test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1) test1_inventory_create();
    if (all || test == 2) test2_inventory_create();

    if (all || test == 3) test1_inventory_add();
    if (all || test == 4) test2_inventory_add();

    if (all || test == 5) test1_inventory_del();
    if (all || test == 6) test2_inventory_del();

    if (all || test == 6) test1_inventory_get_max_objs();
    if (all || test == 7) test2_inventory_get_max_objs();

    if (all || test == 8) test1_inventory_get_objs();
    if (all || test == 9) test2_inventory_get_objs();

    if (all || test == 10) test1_inventory_print();
    if (all || test == 11) test2_inventory_print();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/* Funciones del test */

void test1_inventory_create(){
    int result;
    Inventory *i = inventory_create(5);
    result = i != NULL;
    PRINT_TEST_RESULT(result);

    inventory_destroy(i);
}

void test2_inventory_create(){
    Inventory *i = inventory_create(4);
    PRINT_TEST_RESULT(inventory_get_max_objs(i) == 4);
    
    inventory_destroy(i);
}

void test1_inventory_add(){
    Inventory *i = inventory_create(5);

    PRINT_TEST_RESULT(inventory_add(i, 1) == OK);
    inventory_destroy(i);
}

void test2_inventory_add(){
    Inventory *i = NULL;

    PRINT_TEST_RESULT(inventory_add(i,1) == ERROR);
}

void test1_inventory_del(){
    Inventory *i = inventory_create(5);

    inventory_add(i, 1);
    PRINT_TEST_RESULT(inventory_del(i, 1) == OK);
    inventory_destroy(i);
}

void test2_inventory_del(){
    Inventory *i = inventory_create(5);

    PRINT_TEST_RESULT(inventory_del(i, 1) == ERROR);
}

void test1_inventory_get_max_objs(){
    Inventory *i = inventory_create(4);

    PRINT_TEST_RESULT(inventory_get_max_objs(i) == 4);
}

void test2_inventory_get_max_objs(){
    Inventory *i = NULL;

    PRINT_TEST_RESULT(inventory_get_max_objs(i) == -1);
}

void test1_inventory_get_objs(){
    Inventory *i = inventory_create(5);

    inventory_add(i,1);
    inventory_add(i,2);
    inventory_add(i,3);
    inventory_add(i,4);

    PRINT_TEST_RESULT(inventory_get_objs(i) != NULL);
    
    inventory_destroy(i);
}

void test2_inventory_get_objs(){
    Inventory *i = NULL;

    PRINT_TEST_RESULT(inventory_get_objs(i) == NULL);
}

void test1_inventory_print(){
    Inventory *i = inventory_create(4);

    inventory_add(i,1);
    inventory_add(i,2);
    inventory_add(i,3);

    PRINT_TEST_RESULT(inventory_print(i) == OK);

    inventory_destroy(i);
}

void test2_inventory_print(){
    Inventory *i = NULL;

    PRINT_TEST_RESULT(inventory_print(i) == ERROR);
}