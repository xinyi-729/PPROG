/** 
 * @brief Declaramos las pruebas para el modulo character
 * 
 * @file character_test.h
 * @author Lucia Ordovas y Xinyi Huang
 * @version 0.0 
 * @date 17-02-2025
 * @copyright GNU Public License
 */

 #ifndef CHARACTER_TEST_H
 #define CHARACTER_TEST_H
 
 
/**
  * @test Comprueba la funcion de creacion de un caracter
  * @pre ID del caracter 
  * @post Puntero no nulo al caracter creado
  */
void test1_character_create();

/**
  * @test Comprueba la funcion de creacion de un caracter
  * @pre ID del caracter 
  * @post ID del caracter igual al ID introducido
  */
void test2_character_create();

/**
  * @test Comprueba la funcion de destruccion de un caracter
  * @pre Puntero a caracter
  * @post OK
  */
/*-----------------------------------------------------------*/
void test1_character_destroy();

/**
  * @test Comprueba la funcion de destruccion de un caracter
  * @pre Puntero a caracter
  * @post ERROR
  */
void test2_character_destroy();

/*------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que devuelve el ID de un caracter
  * @pre Puntero a caracter
  * @post ID del caracter
  */
void test1_character_get_id();

/**
  * @test Comprueba la funcion que devuelve el ID de un caracter
  * @pre Puntero a caracter
  * @post ID del caracter
  */
void test2_character_get_id();

/*--------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que establece el nombre de un caracter
  * @pre Puntero a caracter y nombre
  * @post OK
  */
void test1_character_set_name();

/**
  * @test Comprueba la funcion que establece el nombre de un caracter
  * @pre Puntero a caracter y nombre
  * @post ERROR
  */
void test2_character_set_name();

/**
  * @test Comprueba la funcion que establece el nombre de un caracter
  * @pre Puntero a caracter y nombre
  * @post ERROR
  */
void test3_character_set_name();

/*----------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que devuelve el nombre de un caracter
  * @pre Puntero a caracter
  * @post Nombre del caracter
  */
void test1_character_get_name();

/**
  * @test Comprueba la funcion que devuelve el nombre de un caracter
  * @pre Puntero a caracter
  * @post Nombre del caracter
  */
void test2_character_get_name();

/*-------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que establece la descripcion de un caracter
  * @pre Puntero a caracter y descripcion
  * @post OK
  */
void test1_character_set_description();

/**
  * @test Comprueba la funcion que establece la descripcion de un caracter
  * @pre Puntero a caracter y descripcion
  * @post ERROR
  */
void test2_character_set_description();

/*-----------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que devuelve la descripcion de un caracter
  * @pre Puntero a caracter
  * @post Descripcion del caracter
  */
void test1_character_get_description();

/**
  * @test Comprueba la funcion que devuelve la descripcion de un caracter
  * @pre Puntero a caracter
  * @post Descripcion del caracter
  */
void test2_character_get_description();

/*------------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que establece la salud de un caracter
  * @pre Puntero a caracter y valor de la salud
  * @post OK
  */
void test1_character_set_health();

/**
  * @test Comprueba la funcion que establece la salud de un caracter
  * @pre Puntero a caracter y valor de la salud
  * @post ERROR
  */
void test2_character_set_health();

/*------------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que devuelve la salud de un caracter
  * @pre Puntero a caracter
  * @post Salud del caracter
  */
void test1_character_get_health();

/**
  * @test Comprueba la funcion que devuelve la salud de un caracter
  * @pre Puntero a caracter
  * @post Salud del caracter
  */
void test2_character_get_health();

/*------------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que disminuye la salud de un caracter
  * @pre Puntero a caracter
  * @post OK
  */
void test1_character_decrease_health();

/**
  * @test Comprueba la funcion que disminuye la salud de un caracter
  * @pre Puntero a caracter
  * @post ERROR
  */
void test2_character_decrease_health();

/*------------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que establece si un caracter es amigable
  * @pre Puntero a caracter y valor booleano
  * @post OK
  */
void test1_character_set_is_friendly();

/**
  * @test Comprueba la funcion que establece si un caracter es amigable
  * @pre Puntero a caracter y valor booleano
  * @post ERROR
  */
void test2_character_set_is_friendly();

/*-------------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que devuelve si un caracter es amigable
  * @pre Puntero a caracter
  * @post Valor booleano
  */
void test1_character_get_is_friendly();

/**
  * @test Comprueba la funcion que devuelve si un caracter es amigable
  * @pre Puntero a caracter
  * @post Valor booleano
  */
void test2_character_get_is_friendly();

/*--------------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que establece el mensaje de un caracter
  * @pre Puntero a caracter y mensaje
  * @post OK
  */
void test1_character_set_message();

/**
  * @test Comprueba la funcion que establece el mensaje de un caracter
  * @pre Puntero a caracter y mensaje
  * @post ERROR
  */
void test2_character_set_message();

/**
  * @test Comprueba la funcion que establece el mensaje de un caracter
  * @pre Puntero a caracter y mensaje
  * @post OK
  */
 void test1_character_get_message();

 /**
   * @test Comprueba la funcion que establece el mensaje de un caracter
   * @pre Puntero a caracter y mensaje
   * @post ERROR
   */
 void test2_character_get_message();

/*---------------------------------------------------------------------------*/
/**
  * @test Comprueba la funcion que imprime el character por pantalla
  * @pre Puntero a caracter y sus atributos
  * @post OK
  */
void test1_character_print();

/**
  * @test Comprueba la funcion que devuelve el mensaje de un caracter
  * @pre Puntero a caracter y sus atributos
  * @post ERROR
  */
void test2_character_print();

#endif