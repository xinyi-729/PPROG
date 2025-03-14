/**
 * @brief It declares the tests for the set module
 * 
 * @file set_test.h
 * @version 0.0 
 * @date 17-02-2025
 * @copyright GNU Public License
 */

 #ifndef SET_TEST_H
 #define SET_TEST_H
 
 /**
  * @test Test set creation
  * @pre None
  * @post Non NULL pointer to set 
  */
 void test1_set_create();
 
 /**
  * @test Test set creation
  * @pre None
  * @post Set size == 0
  */
 void test2_set_create();
 
 /**
  * @test Test function for set_add
  * @pre Set pointer and element to add
  * @post Output==OK 
  */
 void test1_set_add();
 
 /**
  * @test Test function for set_add
  * @pre Set pointer = NULL
  * @post Output==ERROR
  */
 void test2_set_add();
 
 /**
  * @test Test function for set_remove
  * @pre Set pointer and element to remove
  * @post Output==OK 
  */
 void test1_set_remove();
 
 /**
  * @test Test function for set_remove
  * @pre Set pointer = NULL
  * @post Output==ERROR
  */
 void test2_set_remove();
 
 /**
  * @test Test function for set_get_id
  * @pre Set pointer and position
  * @post Output==Element ID
  */
 void test1_set_get_id();
 
 /**
  * @test Test function for set_get_id
  * @pre Set pointer = NULL
  * @post Output==NO_ID
  */
 void test2_set_get_id();
 
 /**
  * @test Test function for set_get_size
  * @pre Set pointer
  * @post Output==Set size
  */
 void test1_set_get_size();
 
 /**
  * @test Test function for set_get_size
  * @pre Set pointer = NULL
  * @post Output==-1
  */
 void test2_set_get_size();
 
 /**
  * @test Test function for set_contains
  * @pre Set pointer and element to check
  * @post Output==TRUE
  */
 void test1_set_contains();
 
 /**
  * @test Test function for set_contains
  * @pre Set pointer = NULL
  * @post Output==FALSE
  */
 void test2_set_contains();
 
 /**
  * @test Test function for set_is_empty
  * @pre Set pointer
  * @post Output==TRUE
  */
 void test1_set_is_empty();
 
 /**
  * @test Test function for set_is_empty
  * @pre Set pointer with elements
  * @post Output==FALSE
  */
 void test2_set_is_empty();
 
 /**
  * @test Test function for set_destroy
  * @pre Set pointer
  * @post Output==OK
  */
 void test1_set_destroy();
 
 /**
  * @test Test function for set_destroy
  * @pre Set pointer = NULL
  * @post Output==ERROR
  */
 void test2_set_destroy();
 
 #endif