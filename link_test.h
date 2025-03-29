/** 
 * @brief It declares the tests for the link module
 * 
 * @file link_test.h
 * @author David Buendia
 * @version 0.0 
 * @date 20-03-2025
 * @copyright GNU Public License
 */

 #ifndef link_TEST_H
 #define link_TEST_H

 /**
  * @test Test link creation
  * @pre link ID 
  * @post Non NULL pointer to link 
  */
 void test1_link_create();
 
 /**
  * @test Test link creation
  * @pre link ID 
  * @post link_ID == Supplied link Id
  */
 void test2_link_create();
 
 /**
  * @test Test function for link_name setting
  * @pre String with link name
  * @post Ouput==OK 
  */
 void test1_link_set_name();
 
 /**
  * @test Test function for link_name setting
  * @pre pointer to link = NULL 
  * @post Output==ERROR
  */
 void test2_link_set_name();
 
 /**
  * @test Test function for link_name setting
  * @pre pointer to link_name = NULL (point to link = NON NULL) 
  * @post Output==ERROR
  */
 void test3_link_set_name();
 
/**
  * @test Test function for link_name setting
  * @pre pointer to link_name = NON NULL (point to link = NON NULL)
  * @post Output == OK
  */
 void test1_link_set_name();

 /**
   * @test Test function for link_name setting
   * @pre pointer to link_name = NULL (point to link = NON NULL)
   * @post Output == ERROR
   */
 void test2_link_set_name();
 
 /**
   * @test Test function for link_name setting
   * @pre pointer to link_name = NULL (point to link = NON NULL)
   * @post Output == ERROR
   */
 void test3_link_set_name();
 
 /**
   * @test Test function for link_name getting
   * @pre pointer to link_name = NON NULL (point to link = NON NULL, link_name = "adios")
   * @post Output == "adios"
   */
 void test1_link_get_name();
 
 /**
   * @test Test function for link_name getting
   * @pre pointer to link_name = NULL (point to link = NON NULL)
   * @post Output == NULL
   */
 void test2_link_get_name();
 
 /**
   * @test Test function for link_id getting
   * @pre pointer to link = NON NULL (link_id = 25)
   * @post Output == 25
   */
 void test1_link_get_id();
 
 /**
   * @test Test function for link_id getting
   * @pre pointer to link = NULL
   * @post Output == NO_ID
   */
 void test2_link_get_id();
 
 /**
   * @test Test function for link_id setting
   * @pre pointer to link = NON NULL (point to link = NON NULL, link_id = 4)
   * @post Output == OK
   */
 void test1_link_set_id();
 
 /**
   * @test Test function for link_id setting
   * @pre pointer to link = NULL
   * @post Output == ERROR
   */
 void test2_link_set_id();
 
 /**
   * @test Test function for link_id setting
   * @pre pointer to link = NON NULL (point to link = NON NULL, link_id = 4)
   * @post Output == ERROR
   */
 void test3_link_set_id();
 
 
 /**
   * @test Test function for link_open getting
   * @pre pointer to link = NON NULL (point to link = NON NULL, link_open = TRUE)
   * @post Output == TRUE
   */
 void test1_link_is_open();
 
 /**
   * @test Test function for link_open getting
   * @pre pointer to link = NON NULL (point to link = NON NULL, link_open = FALSE)
   * @post Output == FALSE
   */
 void test2_link_is_open();
 
 /**
   * @test Test function for link_open getting
   * @pre pointer to link = NULL
   * @post Output == ERR
   */
 void test3_link_is_open();
 
 /**
   * @test Test function for link_open setting
   * @pre pointer to link = NON NULL (point to link = NON NULL)
   * @post Output == OK
   */
 void test1_link_set_open();
 
 /**
   * @test Test function for link_open setting
   * @pre pointer to link = NULL
   * @post Output == ERROR
   */
 void test2_link_set_open();
 
 /**
   * @test Test function for link_open setting
   * @pre pointer to link = NON NULL (point to link = NON NULL)
   * @post Output == ERROR
   */
 void test3_link_set_open();
 

 /**
   * @test Test function for link_originID getting
   * @pre pointer to link = NON NULL (link_id = 25)
   * @post Output == 25
   */
  void test1_link_get_originID();
 
  /**
    * @test Test function for link_originID getting
    * @pre pointer to link = NULL
    * @post Output == NO_ID
    */
  void test2_link_get_originID();
  
  /**
    * @test Test function for link_originID setting
    * @pre pointer to link = NON NULL (point to link = NON NULL, link_id = 4)
    * @post Output == OK
    */
  void test1_link_set_originID();
  
  /**
    * @test Test function for link_originID setting
    * @pre pointer to link = NULL
    * @post Output == ERROR
    */
  void test2_link_set_originID();
  
  /**
    * @test Test function for link_originID setting
    * @pre pointer to link = NON NULL (point to link = NON NULL, link_id = 4)
    * @post Output == OK
    */
  void test3_link_set_originID();

   /**
   * @test Test function for link_destID getting
   * @pre pointer to link = NON NULL (link_id = 25)
   * @post Output == 25
   */
  void test1_link_get_destID();
 
  /**
    * @test Test function for link_destID getting
    * @pre pointer to link = NULL
    * @post Output == NO_ID
    */
  void test2_link_get_destID();
  
  /**
    * @test Test function for link_destID setting
    * @pre pointer to link = NON NULL (point to link = NON NULL, link_id = 4)
    * @post Output == OK
    */
  void test1_link_set_destID();
  
  /**
    * @test Test function for link_destID setting
    * @pre pointer to link = NULL
    * @post Output == ERROR
    */
  void test2_link_set_destID();
  
  /**
    * @test Test function for link_destID setting
    * @pre pointer to link = NON NULL (point to link = NON NULL, link_id = 4)
    * @post Output == ERROR
    */
  void test3_link_set_destID();

  /**
   * @test Test function for link_direction getting
   * @pre pointer to link = NON NULL (point to link = NON NULL, link_direction = N)
   * @post Output == N
   */
  void test1_link_get_direction();
 
  /**
    * @test Test function for link_direction getting
    * @pre pointer to link = NON NULL (point to link = NON NULL, link_direction = NOTKNOWN)
    * @post Output == NOTKNOWN
    */
  void test2_link_get_direction();
  
  /**
    * @test Test function for link_direction getting
    * @pre pointer to link = NULL
    * @post Output == NOTKNOWN
    */
  void test3_link_get_direction();
  
  /**
    * @test Test function for link_direction setting
    * @pre pointer to link = NON NULL (point to link = NON NULL)
    * @post Output == OK
    */
  void test1_link_set_direction();
  
  /**
    * @test Test function for link_direction setting
    * @pre pointer to link = NULL
    * @post Output == ERROR
    */
  void test2_link_set_direction();
  
  /**
    * @test Test function for link_direction setting
    * @pre pointer to link = NON NULL (point to link = NON NULL)
    * @post Output == ERROR
    */
  void test3_link_set_direction();
  

 
 #endif