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

 void test3_set_add() ;
 
 /**
  * @test Test function for set_remove
  * @pre Set pointer and element to remove
  * @post Output==OK 
  */
 void test1_set_del();
 
 /**
  * @test Test function for set_remove
  * @pre Set pointer = NULL
  * @post Output==ERROR
  */
 void test2_set_del();
 
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
  * @test Test function for set_has
  * @pre Set pointer
  * @post Output==TRUE
  */
 void test1_set_has();

  /**
  * @test Test function for set_has
  * @pre Set pointer with elements
  * @post Output==FALSE
  */
 void test2_set_has();
 
  /**
  * @test Test function for set_get_n_ids
  * @pre Set pointer with elements
  * @post Output==ID
  */
 void test1_set_get_n_ids();

   /**
  * @test Test function for set_get_n_ids
  * @pre Set pointer with elements
  * @post Output==NO_ID
  */
 void test2_set_get_n_ids();

 
 #endif