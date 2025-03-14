/**
 * @brief It tests character module
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
     if (all || test == 3) test1_character_set_name();
     if (all || test == 4) test2_character_set_name();
     if (all || test == 5) test3_character_set_name();
     if (all || test == 6) test1_character_get_name();
     if (all || test == 7) test2_character_get_name();
 
     PRINT_PASSED_PERCENTAGE;
 
     return 1;
 }
 
 /* Test functions */
 
 void test1_character_create() {
     Character *c;
     c = character_create(1);
     PRINT_TEST_RESULT(c != NULL);
     character_destroy(c);
 }
 
 void test2_character_create() {
     Character *c;
     c = character_create(1);
     PRINT_TEST_RESULT(character_get_id(c) == 1);
     character_destroy(c);
 }
 
 void test1_character_set_name() {
     Character *c;
     c = character_create(1);
     PRINT_TEST_RESULT(character_set_name(c, "John") == OK);
     character_destroy(c);
 }
 
 void test2_character_set_name() {
     Character *c = NULL;
     PRINT_TEST_RESULT(character_set_name(c, "John") == ERROR);
 }
 
 void test3_character_set_name() {
     Character *c;
     c = character_create(1);
     PRINT_TEST_RESULT(character_set_name(c, NULL) == ERROR);
     character_destroy(c);
 }
 
 void test1_character_get_name() {
     Character *c;
     c = character_create(1);
     character_set_name(c, "John");
     PRINT_TEST_RESULT(strcmp(character_get_name(c), "John") == 0);
     character_destroy(c);
 }
 
 void test2_character_get_name() {
     Character *c = NULL;
     PRINT_TEST_RESULT(character_get_name(c) == NULL);
 }
