/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Profesores Pprog
 * @version 0.0 
 * @date 17-02-2025
 * @copyright GNU Public License
 */

 #ifndef SPACE_TEST_H
 #define SPACE_TEST_H
 
 /**
  * @test Test space creation
  * @pre Space ID 
  * @post Non NULL pointer to space 
  */
 void test1_space_create();
 
 /**
  * @test Test space creation
  * @pre Space ID 
  * @post Space_ID == Supplied Space Id
  */
 void test2_space_create();
 
 /**
  * @test Test function for space_name setting
  * @pre String with space name
  * @post Ouput==OK 
  */
 void test1_space_set_name();
 
 /**
  * @test Test function for space_name setting
  * @pre pointer to space = NULL 
  * @post Output==ERROR
  */
 void test2_space_set_name();
 
 /**
  * @test Test function for space_name setting
  * @pre pointer to space_name = NULL (point to space = NON NULL) 
  * @post Output==ERROR
  */
 void test3_space_set_name();

  /*----------------------------------------------------------*/
    /**
    * @test Comprueba la funcion que devuelve el nombre de un espacio
    * @pre Puntero a espacio
    * @post Nombre del espacio
    */
   void test1_space_get_name();

   /**
   * @test Comprueba la funcion que devuelve el nombre de un espacio
   * @pre Puntero a espacio
   * @post Nombre del espacio
   */
void test2_space_get_name();


     /**
    * @test Comprueba la funcion que establece el norte de un espacio
    * @pre Puntero a espacio y ID del espacio norte
    * @post OK
    */
   void test1_space_set_north();
 
   /**
   * @test Comprueba la funcion que establece el norte de un espacio
   * @pre Puntero a espacio y ID del espacio norte
   * @post ERROR
   */

void test2_space_set_north();
   
       /**
       * @test Comprueba la funcion que establece el sur de un espacio
       * @pre Puntero a espacio y ID del espacio sur
       * @post OK
       */
void test1_space_set_south();
   
       /**
       * @test Comprueba la funcion que establece el sur de un espacio
       * @pre Puntero a espacio y ID del espacio sur
       * @post ERROR
       */
void test2_space_set_south();
   
       /**
       * @test Comprueba la funcion que establece el este de un espacio
       * @pre Puntero a espacio y ID del espacio este
       * @post OK
       */

void test1_space_set_east();
   
       /**
       * @test Comprueba la funcion que establece el este de un espacio
       * @pre Puntero a espacio y ID del espacio este
       * @post ERROR
       */
void test2_space_set_east();

       /**
       * @test Comprueba la funcion que establece el oeste de un espacio
       * @pre Puntero a espacio y ID del espacio oeste
       * @post OK
       */
void test1_space_set_west();

       /**
       * @test Comprueba la funcion que establece el oeste de un espacio
       * @pre Puntero a espacio y ID del espacio oeste
       * @post ERROR
       */
void test2_space_set_west();

/*---------------------------------------------------------------------------*/
           /**
           * @test Comprueba la funcion que devuelve el norte de un espacio
           * @pre Puntero a espacio
           * @post ID del espacio norte
           */
void test1_space_get_north();

           /**
           * @test Comprueba la funcion que devuelve el norte de un espacio
           * @pre Puntero a espacio
           * @post ID del espacio norte
           */
void test2_space_get_north();

           /**
           * @test Comprueba la funcion que devuelve el sur de un espacio
           * @pre Puntero a espacio
           * @post ID del espacio sur
           */
void test1_space_get_south();

           /**
           * @test Comprueba la funcion que devuelve el sur de un espacio
           * @pre Puntero a espacio
           * @post ID del espacio sur
           */
void test2_space_get_south();

           /**
           * @test Comprueba la funcion que devuelve el este de un espacio
           * @pre Puntero a espacio
           * @post ID del espacio este
           */

void test1_space_get_east();

           /**
           * @test Comprueba la funcion que devuelve el este de un espacio
           * @pre Puntero a espacio
           * @post ID del espacio este
           */

void test2_space_get_east();

           /**
           * @test Comprueba la funcion que devuelve el oeste de un espacio
           * @pre Puntero a espacio
           * @post ID del espacio oeste
           */

void test1_space_get_west();

           /**
           * @test Comprueba la funcion que devuelve el oeste de un espacio
           * @pre Puntero a espacio
           * @post ID del espacio oeste
           */

void test2_space_get_west();

/*----------------------------------------------------------*/

    /**
    * @test Comprueba la funcion que devuelve el ID de un espacio
    * @pre Puntero a espacio
    * @post ID del espacio
    */
void test1_space_get_id();
 
   /**
   * @test Comprueba la funcion que devuelve el ID de un espacio
   * @pre Puntero a espacio
   * @post ID del espacio
   */
void test2_space_get_id();

/*------------------------------------------------------*/
   /**
   * @test Comprueba la funcion que establece el nombre de un espacio
   * @pre Puntero a espacio y nombre
   * @post OK
   */
void test1_space_set_name();

   /**
   * @test Comprueba la funcion que establece el nombre de un espacio
   * @pre Puntero a espacio y nombre
   * @post ERROR
   */
void test2_space_set_name();

/**
  *  * @test Comprueba la funcion que establece el nombre de un espacio
  *  * @pre Puntero a espacio y nombre
  *  * @post ERROR
  * 
  */
void test3_space_set_name();
 

/*----------------------------------------------------------*/
            /**
            * @test Comprueba la funcion que devuelve si un espacio tiene un objeto
            * @pre Puntero a espacio y ID del objeto
            * @post TRUE
            */
           void test1_space_has_object();

           /**
           * @test Comprueba la funcion que devuelve si un espacio tiene un objeto
           * @pre Puntero a espacio y ID del objeto
           * @post FALSE
           */
void test2_space_has_object();

/*------------------------------------------------------------*/
           /**
           * @test Comprueba la funcion que añade un objeto a un espacio
           * @pre Puntero a espacio y ID del objeto
           * @post OK
           */
void test1_space_add_object();

           /**
           * @test Comprueba la funcion que añade un objeto a un espacio
           * @pre Puntero a espacio y ID del objeto
           * @post ERROR
           */
void test2_space_add_object();
/*------------------------------------------------------------*/
           /**
           * @test Comprueba la funcion que elimina un objeto de un espacio
           * @pre Puntero a espacio y ID del objeto
           * @post OK
           */
void test1_space_del_object();

           /**
           * @test Comprueba la funcion que elimina un objeto de un espacio
           * @pre Puntero a espacio y ID del objeto
           * @post ERROR
           */
void test2_space_del_object();

/*------------------------------------------------------------*/
           /**
           * @test Comprueba la funcion que devuelve el set de un espacio
           * @pre Puntero a espacio
           * @post Set del espacio
           */
void test1_space_get_set();

           /**
           * @test Comprueba la funcion que devuelve el set de un espacio
           * @pre Puntero a espacio
           * @post NULL
           */
void test2_space_get_set();

/*-------------------------------------------------------------*/

           /**
           * @test Comprueba la funcion que establece la descripcion grafica
           * @pre Puntero al espacio y descripcion grafica
           * @post OK
           */
void test1_space_set_gdesc();

           /**
           * @test Comprueba la funcion que establece la descripcion grafica
           * @pre Puntero al espacio y descripcion grafica
           * @post ERROR
           */
void test2_space_set_gdesc();

           /**
           * @test Comprueba la funcion que establece la descripcion grafica
           * @pre Puntero al espacio y descripcion grafica = NULL
           * @post ERROR
           */
void test3_space_set_gdesc();

/*-----------------------------------------------------------------*/
/**
* @test Comprueba la funcion que devuelve el set de un espacio
* @pre Puntero a espacio
* @post descripcion
*/
void test1_space_get_gdesc();

/**
* @test Comprueba la funcion que devuelve el set de un espacio
* @pre Puntero a espacio
* @post descripcion
*/
void test2_space_get_gdesc();

/**
  * @test Comprueba la funcion que devuelve el id del objeto que se encuentra en un espacio determinado
  * @pre Puntero a space e id de los objetos
  * @post id del objeto localizado en el espacio concreto
  */
 void test1_space_get_objetc_id_at();

 /**
   * @test Comprueba la funcion que devuelve el id del objeto que se encuentra en un espacio determinado
   * @pre Puntero a space e id de los objetos
   * @post id del objeto localizado en el espacio concreto
   */
 void test2_space_get_objetc_id_at();


 /*-------------------------------------------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que asigna el id del character en el espacio
  * @pre Puntero a space e id del character
  * @post OK
  */
void test1_space_set_character_id();

/**
  * @test Comprueba la funcion que asigna el id del character en el espacio
  * @pre Puntero a space e id del character
  * @post ERROR
  */
void test2_space_set_character_id();

/**
  * @test Comprueba la funcion que devuelve el id del character en el espacio
  * @pre Puntero a space e id del character
  * @post id del character en el espacio
  */
void test1_space_get_character_id();

/**
  * @test Comprueba la funcion que devuelve el id del character en el espacio
  * @pre Puntero a space e id del character
  * @post id del character en el espacio
  */
void test2_space_get_character_id();

/*--------------------------------------------------------------*/


 #endif
 