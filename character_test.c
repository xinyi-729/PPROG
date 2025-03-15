/**
 * @brief Tests para el modulo Character
 * 
 * @file character_test.c
 * @version 0.0 
 * @date 17-02-2025
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "character.h"
 #include "test.h"
 #include "character_test.h"
 
 #define MAX_TESTS 10
 
 /** 
  * @brief Main function for CHARACTER unit tests. 
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
 
     if (all || test == 1) test1_character_create();
     if (all || test == 2) test2_character_create();

     if (all || test == 2) test1_character_destroy();
     if (all || test == 3) test2_character_destroy();

     if (all || test == 4) test1_character_get_id();
     if (all || test == 5) test2_character_get_id();

     if (all || test == 6) test1_character_set_name();
     if (all || test == 7) test2_character_set_name();
     if (all || test == 8) test3_character_set_name();

     if (all || test == 9) test1_character_get_name();
     if (all || test == 10) test2_character_get_name();

     if (all || test == 11) test1_character_set_description();
     if (all || test == 12) test2_character_set_description();

     if (all || test == 13) test1_character_get_description();
     if (all || test == 14) test2_character_get_description();

     if (all || test == 15) test1_character_set_health();
     if (all || test == 16) test2_character_set_health();

     if (all || test == 17) test1_character_get_health();
     if (all || test == 18) test2_character_get_health();

     if (all || test == 19) test1_character_decrease_health();
     if (all || test == 20) test2_character_decrease_health();

     if (all || test == 21) test1_character_set_is_friendly();
     if (all || test == 22) test2_character_set_is_friendly();

     if (all || test == 23) test1_character_get_is_friendly();
     if (all || test == 24) test2_character_get_is_friendly();

     if (all || test == 25) test1_character_set_message();
     if (all || test == 26) test2_character_set_message();

     if (all || test == 27) test1_character_get_message();
     if (all || test == 28) test2_character_get_message();

     PRINT_PASSED_PERCENTAGE;
 
     return 1;
 }

 /*----------------------------------------------------------------*/
 
 /* Test functions */
 
 void test1_character_create() {
     Character *c;
     c = character_create(11);
     PRINT_TEST_RESULT(c != NULL);
     character_destroy(c);
 }
 
 void test2_character_create() {
     Character *c;
     c = character_create(11);
     PRINT_TEST_RESULT(character_get_id(c) == 11);
     character_destroy(c);
 }

 /*-----------------------------------------------------------*/
 void test1_character_destroy() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_destroy(c) == ERROR);
}

void test2_character_destroy() {
    Character *c;
    c = character_create(11);
    PRINT_TEST_RESULT(character_destroy(c) == OK);
}
 
/*------------------------------------------------------------*/
 void test1_character_get_id() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_get_id(c) == NO_ID);
 }

 void test2_character_get_id() {
    Character *c;
    c = character_create(11);
    PRINT_TEST_RESULT(character_get_id(c) == 11);
    character_destroy(c);
 }

/*--------------------------------------------------------------*/
 void test1_character_set_name() {
     Character *c;
     c = character_create(1);
     PRINT_TEST_RESULT(character_set_name(c, "Ana") == OK);
     character_destroy(c);
 }
 
 void test2_character_set_name() {
     Character *c = NULL;
     PRINT_TEST_RESULT(character_set_name(c, "Ana") == ERROR);
 }

 void test3_character_set_name() {
    Character *c;
    c = character_create(1);
    PRINT_TEST_RESULT(character_set_name(c, NULL) == ERROR);
    character_destroy(c);
}

 /*----------------------------------------------------------------*/
 void test1_character_get_name() {
     Character *c;
     c = character_create(1);
     character_set_name(c, "Ana");
     PRINT_TEST_RESULT(strcmp(character_get_name(c), "Ana") == 0);
     character_destroy(c);
 }
 
 void test2_character_get_name() {
     Character *c = NULL;
     PRINT_TEST_RESULT(character_get_name(c) == NULL);
 }

 /*-------------------------------------------------------------------*/
 void test1_character_set_description() {
    Character *c;
    c = character_create(1);
    PRINT_TEST_RESULT(character_set_description(c, "*-*") == OK);
    character_destroy(c);
}

void test2_character_set_description() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_set_description(c, "*-*") == ERROR);
}

/*-----------------------------------------------------------------------*/
void test1_character_get_description() {
    Character *c;
    c = character_create(1);
    character_set_description(c, "*-*");
    PRINT_TEST_RESULT(strcmp(character_get_description(c), "*-*") == 0);
    character_destroy(c);
}

void test2_character_get_description() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_get_description(c) == NULL);
}
/*------------------------------------------------------------------------*/
void test1_character_set_health() {
    Character *c;
    c = character_create(1);
    PRINT_TEST_RESULT(character_set_health(c, 5) == OK);
    character_destroy(c);
}

void test2_character_set_health() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_set_health(c, 5) == ERROR);
}

/*------------------------------------------------------------------------*/
void test1_character_get_health() {
    Character *c;
    c = character_create(1);
    character_set_health(c, 5);
    PRINT_TEST_RESULT(character_get_health(c) == 5);
    character_destroy(c);
}

void test2_character_get_health() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_get_description(c) == NULL);
}

/*------------------------------------------------------------------------*/
void test1_character_decrease_health() {
    Character *c;
    c = character_create(1);
    character_set_health(c, 5);
    PRINT_TEST_RESULT(character_decrease_health(c) == OK);
    character_destroy(c);
}

void test2_character_decrease_health() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_decrease_health(c) == ERROR);
}

/*------------------------------------------------------------------------*/
void test1_character_set_is_friendly() {
    Character *c;
    c = character_create(1);
    PRINT_TEST_RESULT(character_set_is_friendly(c, TRUE) == OK);
    character_destroy(c);
}

void test2_character_set_is_friendly() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_set_is_friendly(c, TRUE) == ERROR);
}

/*-------------------------------------------------------------------------*/
void test1_character_get_is_friendly() {
    Character *c;
    c = character_create(1);
    character_set_is_friendly(c, TRUE);
    PRINT_TEST_RESULT(character_get_is_friendly(c) == TRUE);
    character_destroy(c);
}

void test2_character_get_is_friendly() {
    Character *c = NULL;
    /* Si da error retorna FALSE */
    PRINT_TEST_RESULT(character_get_is_friendly(c) == FALSE);
}

/*--------------------------------------------------------------------------*/
void test1_character_set_message() {
    Character *c;
    c = character_create(1);
    PRINT_TEST_RESULT(character_set_message(c, "Hola") == OK);
    character_destroy(c);
}

void test2_character_set_message() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_set_message(c, "Hola") == ERROR);
}

void test1_character_get_message(){
    Character *c=NULL;
    c = character_create(11);
    character_set_message(c, "Soy spiderman");
    PRINT_TEST_RESULT(character_get_message(c) != NULL);
    character_destroy(c);
}

void test2_character_get_message(){
    Character *c=NULL;
    character_set_message(c, "Soy spiderman");
    PRINT_TEST_RESULT(character_get_message(c) == NULL);
    character_destroy(c);
}

/*---------------------------------------------------------------------------*/
void test1_character_print() {
    Character *c;
    c = character_create(1);
    character_set_name(c, "Ana");
    character_set_description(c, "*-*");
    character_set_health(c, 5);
    character_set_is_friendly(c, TRUE);
    character_set_message(c, "Hola");

    PRINT_TEST_RESULT(character_print(c) == OK);
    character_destroy(c);
}

void test2_character_print() {
    Character *c = NULL;
    PRINT_TEST_RESULT(character_print(c) == ERROR);
}