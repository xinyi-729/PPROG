/** 
 * @brief It tests link module
 * 
 * @file link_test.c
 * @author David Buendia
 * @version 0.0 
 * @date 20-03-2025
 * @copyright GNU Public License
 */


 #include <stdio.h> 
 #include <stdlib.h> 
 #include <string.h> 
 #include "link.h"
 #include "link_test.h"
 #include "test.h"
 #include "types.h"
 
 #define MAX_TESTS 34
 
 /** 
  * @brief Main function for link unit tests. 
  * 
  * You may execute ALL or a SINGLE test
  *   1.- No parameter -> ALL test are executed 
  *   2.- A number means a particular test (the one identified by that number) 
  *       is executed
  */
 int main(int argc, char** argv) {
 
   int test = 0;
   int all = 1;
 
   if (argc < 2) {
     printf("Running all test for module link:\n");
   } else {
     test = atoi(argv[1]);
     all = 0;
     printf("Running test %d:\t", test);
     if (test < 1 && test > MAX_TESTS) {
       printf("Error: NOTKNOWN test %d\t", test);
       exit(EXIT_SUCCESS);
     }
   }
 
 
  if (all || test == 1) test1_link_create();
  if (all || test == 2) test2_link_create();
  if (all || test == 3) test1_link_set_name();
  if (all || test == 4) test2_link_set_name();
  if (all || test == 5) test3_link_set_name();
  if (all || test == 6) test1_link_get_name();
  if (all || test == 7) test2_link_get_name();
  if (all || test == 8) test1_link_get_id();
  if (all || test == 9) test2_link_get_id();
  if (all || test == 10) test1_link_set_id();
  if (all || test == 11) test2_link_set_id();
  if (all || test == 12) test3_link_set_id();
  if (all || test == 13) test1_link_is_open();
  if (all || test == 14) test2_link_is_open();
  if (all || test == 15) test3_link_is_open();
  if (all || test == 16) test1_link_set_open();
  if (all || test == 17) test2_link_set_open();
  if (all || test == 18) test3_link_set_open();
  if (all || test == 19) test1_link_get_originID();
  if (all || test == 20) test2_link_get_originID();
  if (all || test == 21) test1_link_set_originID();
  if (all || test == 22) test2_link_set_originID();
  if (all || test == 23) test3_link_set_originID();
  if (all || test == 24) test1_link_get_destID();
  if (all || test == 25) test2_link_get_destID();
  if (all || test == 26) test1_link_set_destID();
  if (all || test == 27) test2_link_set_destID();
  if (all || test == 28) test3_link_set_destID();
  if (all || test == 29) test1_link_get_direction();
  if (all || test == 30) test2_link_get_direction();
  if (all || test == 31) test3_link_get_direction();
  if (all || test == 32) test1_link_set_direction();
  if (all || test == 33) test2_link_set_direction();
  if (all || test == 34) test3_link_set_direction();

 
   PRINT_PASSED_PERCENTAGE;
 
   return 1;
 }
 
 void test1_link_create() {
   int result;
   link *s;
   s = link_create(5);
   result=s!=NULL ;
   PRINT_TEST_RESULT(result);
   link_destroy(s);
 }
 
 void test2_link_create() {
   link *s;
   s = link_create(4);
   PRINT_TEST_RESULT(link_get_id(s) == 4);
   link_destroy(s);
 }
 
 
 void test1_link_set_name() {
   link *s;
   s = link_create(5);
   PRINT_TEST_RESULT(link_set_name(s, "hola") == OK);
   link_destroy(s);
 }
 
 void test2_link_set_name() {
   link *s = NULL;
   PRINT_TEST_RESULT(link_set_name(s, "hola") == ERROR);
 }
 
 void test3_link_set_name() {
   link *s;
   s = link_create(5);
   PRINT_TEST_RESULT(link_set_name(s, NULL) == ERROR);
   link_destroy(s);
 }
 
 
 void test1_link_get_name() {
   link *s;
   s = link_create(1);
   link_set_name(s, "adios");
   PRINT_TEST_RESULT(strcmp(link_get_name(s), "adios") == 0);
   link_destroy(s);
 }
 
 void test2_link_get_name() {
   link *s = NULL;
   PRINT_TEST_RESULT(link_get_name(s) == NULL);
 }
 
 
 void test1_link_get_id() {
   link *s;
   s = link_create(25);
   PRINT_TEST_RESULT(link_get_id(s) == 25);
   link_destroy(s);
 }
 
 void test2_link_get_id() {
   link *s = NULL;
   PRINT_TEST_RESULT(link_get_id(s) == NO_ID);
 }
 
 
 void test1_link_set_id(){
   link *s;
   s = link_create(5);
   PRINT_TEST_RESULT(link_set_id(s, 4) == OK);
   link_destroy(s);
 }
 
 void test2_link_set_id() {
   link *s = NULL;
   PRINT_TEST_RESULT(link_set_id(s, 4) == ERROR);
 }
 
 void test3_link_set_id() {
   link *s;
   s = link_create(5);
   PRINT_TEST_RESULT(link_set_id(s, -1) == ERROR);
   link_destroy(s);
 }
 

 void test1_link_is_open() {
   link *s;
   s = link_create(1);
   link_set_open(s, TRUE);
   PRINT_TEST_RESULT(link_is_open(s) == TRUE);
   link_destroy(s);
 }
 
 void test2_link_is_open() {
   link *s;
   s = link_create(1);
   link_set_open(s, FALSE);
   PRINT_TEST_RESULT(link_is_open(s) == FALSE);
   link_destroy(s);
 }
 
 void test3_link_is_open() {
   link *s = NULL;
   PRINT_TEST_RESULT(link_is_open(s) == ERR);
 }
 

 void test1_link_set_open() {
   link *s;
   s = link_create(5);
   PRINT_TEST_RESULT(link_set_open(s, TRUE) == OK);
   link_destroy(s);
 }
 
 void test2_link_set_open() {
   link *s = NULL;
   PRINT_TEST_RESULT(link_set_open(s, TRUE) == ERROR);
 }
 
 void test3_link_set_open() {
   link *s;
   s = link_create(5);
   PRINT_TEST_RESULT(link_set_open(s, ERR) == ERROR);
   link_destroy(s);
 }


void test1_link_get_originID() {
  link *s;
  s = link_create(5);
  PRINT_TEST_RESULT(link_get_originID(s) == -1);
  link_destroy(s);
}

void test2_link_get_originID() {
  link *s = NULL;
  PRINT_TEST_RESULT(link_get_originID(s) == NO_ID);
}


void test1_link_set_originID(){
  link *s;
  s = link_create(5);
  PRINT_TEST_RESULT(link_set_originID(s, 4) == OK);
  link_destroy(s);
}

void test2_link_set_originID() {
  link *s = NULL;
  PRINT_TEST_RESULT(link_set_originID(s, 4) == ERROR);
}

void test3_link_set_originID() {
  link *s;
  s = link_create(5);
  PRINT_TEST_RESULT(link_set_originID(s, -1) == OK);
  link_destroy(s);
}
 

void test1_link_get_destID() {
  link *s;
  s = link_create(25);
  PRINT_TEST_RESULT(link_get_destID(s) == -1);
  link_destroy(s);
}

void test2_link_get_destID() {
  link *s = NULL;
  PRINT_TEST_RESULT(link_get_destID(s) == NO_ID);
}


void test1_link_set_destID(){
  link *s;
  s = link_create(5);
  PRINT_TEST_RESULT(link_set_destID(s, 4) == OK);
  link_destroy(s);
}

void test2_link_set_destID() {
  link *s = NULL;
  PRINT_TEST_RESULT(link_set_destID(s, 4) == ERROR);
}

void test3_link_set_destID() {
  link *s;
  s = link_create(5);
  PRINT_TEST_RESULT(link_set_destID(s, -1) == ERROR);
  link_destroy(s);
}
 

void test1_link_get_direction() {
  link *s;
  s = link_create(1);
  link_set_direction(s, N);
  PRINT_TEST_RESULT(link_get_direction(s) == N);
  link_destroy(s);
}

void test2_link_get_direction() {
  link *s;
  s = link_create(1);
  link_set_direction(s, NOTKNOWN);
  PRINT_TEST_RESULT(link_get_direction(s) == NOTKNOWN);
  link_destroy(s);
}

void test3_link_get_direction() {
  link *s = NULL;
  PRINT_TEST_RESULT(link_get_direction(s) == NOTKNOWN);
}


void test1_link_set_direction() {
  link *s;
  s = link_create(5);
  PRINT_TEST_RESULT(link_set_direction(s, S) == OK);
  link_destroy(s);
}

void test2_link_set_direction() {
  link *s = NULL;
  PRINT_TEST_RESULT(link_set_direction(s, W) == ERROR);
}

void test3_link_set_direction() {
  link *s;
  s = link_create(5);
  PRINT_TEST_RESULT(link_set_direction(s, ERR) == ERROR);
  link_destroy(s);
}
