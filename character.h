/**
 * @brief Define la interfaz del modulo del caracter
 * @author Xinyi Huang y Lucia Ordovas
 *
 * @file character.h
 * @version 0
 * @date 31-01-2025
 * @copyright Licencia Publica GNU
 */
 
 #ifndef CHARACTER_H
 #define CHARACTER_H
 
 #include "types.h"
 
 typedef struct _Character Character;
 
 /**
   * @brief Crea un nuevo caracter, reservando memoria e inicializando sus miembros
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param id el numero de identificacion para el nuevo caracter
   * @return un nuevo caracter inicializado
  */
 Character* character_create(Id id);
 
 /**
   * @brief Destruye un caracter, liberando su memoria
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter a destruir
   * @return OK si se destruye correctamente, ERROR en caso contrario
  */
 Status character_destroy(Character* character);
 
 /**
   * @brief Obtiene el id de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter del que se quiere obtener el id
   * @return el id del caracter
  */
 Id character_get_id(Character* character);
 
 /**
   * @brief Establece el nombre de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter al que se le quiere establecer el nombre
   * @param name el nombre a establecer
   * @return OK si se establece correctamente, ERROR en caso contrario
  */
 Status character_set_name(Character* character, const char* name);
 
 /**
   * @brief Obtiene el nombre de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter del que se quiere obtener el nombre
   * @return el nombre del caracter
  */
 const char* character_get_name(Character* character);
 
 /**
   * @brief Establece la descripción de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter al que se le quiere establecer la descripción
   * @param gdesc la descripción a establecer
   * @return OK si se establece correctamente, ERROR en caso contrario
  */
 Status character_set_description(Character* character, char* gdesc);
 
 /**
   * @brief Obtiene la descripción de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter del que se quiere obtener la descripción
   * @return la descripción del caracter
   */
 const char* character_get_description(Character* character);
 
 /**
   * @brief Establece la salud de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter al que se le quiere establecer la salud
   * @param health la salud a establecer
   * @return OK si se establece correctamente, ERROR en caso contrario
  */
 Status character_set_health(Character* character, long value);
 
 /**
   * @brief Obtiene la salud de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter del que se quiere obtener la salud
   * @return la salud del caracter
   */
 long character_get_health(Character* character);
 
 /**
   * @brief Decrece la salud de un caracter en 1
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter del que se quiere obtener la salud
   * @return OK si se establece correctamente, ERROR en caso contrario
   */
 Status character_decrease_health(Character *character);

 /**
   * @brief Establece si un caracter es amigable
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter al que se le quiere establecer el valor
   * @param value el valor a establecer (TRUE o FALSE)
   * @return OK si se establece correctamente, ERROR en caso contrario
   */
 Status character_set_is_friendly(Character *character, Bool value);
 
 /**
   * @brief Obtiene si un caracter es amigable
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter del que se quiere obtener el valor
   * @return TRUE si el caracter es amigable, FALSE en caso contrario
   */
 Bool character_get_is_friendly(Character *character);
 
 /**
   * @brief Establece el mensaje de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter al que se le quiere establecer el mensaje
   * @param message el mensaje a establecer
   * @return OK si se establece correctamente, ERROR en caso contrario
   */
 Status character_set_message(Character *character, char *message);
 
 /**
   * @brief Obtiene el mensaje de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter del que se quiere obtener el mensaje
   * @return el mensaje del caracter
   */
 char * character_get_message(Character *character);
 
 /**
   * @brief Imprime la información de un caracter
   * @author Xinyi Huang y Lucia Ordovas
   *
   * @param character el caracter del que se quiere imprimir la información
   * @return OK si se imprime correctamente, ERROR en caso contrario
   */
 Status character_print(Character *character);
 
 #endif /* CHARACTER_H */

