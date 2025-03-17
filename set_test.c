/**
 * @brief It tests set module
 * 
 * @file set_test.c
 * @version 0.0 
 * @date 17-02-2025
 * @copyright GNU Public License
 */

 #include <stdio.h> 
 #include <stdlib.h> 
 #include "set.h"
 #include "set_test.h"
 #include "test.h"
 
 #define MAX_TESTS 20
 
 /** 
  * @brief Main function for SET unit tests. 
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
     printf("Running all test for module Set:\n");
   } else {
     test = atoi(argv[1]);
     all = 0;
     printf("Running test %d:\t", test);
     if (test < 1 || test > MAX_TESTS) {
       printf("Error: unknown test %d\t", test);
       exit(EXIT_SUCCESS);
     }
   } 
 
   if (all || test == 1) test1_set_create();
   if (all || test == 2) test2_set_create();
   if (all || test == 3) test1_set_add();
   if (all || test == 4) test2_set_add();
   if (all || test == 5) test3_set_add();
   if (all || test == 6) test1_set_get_n_ids();
   if (all || test == 7) test2_set_get_n_ids();
   if (all || test == 8) test1_set_del();
   if (all || test == 9) test2_set_del();
   if (all || test == 10) test1_set_get_id();
   if (all || test == 11) test2_set_get_id();
   if (all || test == 12) test1_set_has();
   if (all || test == 13) test2_set_has();

   PRINT_PASSED_PERCENTAGE;
 
   return 1;
 }
 
 void test1_set_create() {
   Set *set = set_create();
   PRINT_TEST_RESULT(set != NULL);
   set_destroy(set);
 }
 
 void test2_set_create() {
   Set *set = set_create();
   PRINT_TEST_RESULT(set_get_n_ids(set) == 0);
   set_destroy(set);
 }

 void test1_set_add() {
  Set *set = set_create();
  PRINT_TEST_RESULT(set_add(set, 1) == OK);
  set_destroy(set);
}

void test2_set_add() {
  Set *set = NULL;
  PRINT_TEST_RESULT(set_add(set, 1) == ERROR);
}

void test3_set_add() {
  Set *set = set_create();
  set_add(set, 1);
  PRINT_TEST_RESULT(set_add(set, 1) == OK);
  set_destroy(set);
}

void test1_set_get_n_ids(){
  Set *s = set_create();
  PRINT_TEST_RESULT(set_get_n_ids(s) == 0);
  set_destroy(s);
 }

void test2_set_get_n_ids(){
  Set *s = set_create();
  set_add(s,100);
  set_add(s, 101);
  PRINT_TEST_RESULT(set_get_n_ids(s) == 2);
  set_destroy(s);
 }
 
 void test1_set_del() {
   Set *set = set_create();
   set_add(set, 1);
   PRINT_TEST_RESULT(set_del(set, 1) == OK);
   set_destroy(set);
 }
 
 void test2_set_del() {
   Set *set = NULL;
   PRINT_TEST_RESULT(set_del(set, 1) == ERROR);
 }
 
 void test1_set_get_id() {
   Set *set = set_create();
   set_add(set, 1);
   PRINT_TEST_RESULT(set_get_id(set, 0) == 1);
   set_destroy(set);
 }
 
 void test2_set_get_id() {
   Set *set =NULL;
   PRINT_TEST_RESULT(set_get_id(set, 0) == NO_ID);
 }
 
 void test1_set_has() {
   Set *set = set_create();
   set_add(set, 1);
   PRINT_TEST_RESULT(set_has(set, 1) == TRUE);
   set_destroy(set);
 }
 
 void test2_set_has() {
   Set *set = set_create();
   set_add(set, 1);
   PRINT_TEST_RESULT(set_has(set, 13) == FALSE);
 }
 