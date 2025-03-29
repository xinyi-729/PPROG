/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H


/*It sets the max size of a word in the game*/
#define WORD_SIZE 1000

/*The case something dont have an id*/
#define NO_ID -1

/*The specific identificator of spaces, objects, players and characters*/
typedef long Id;

/*Boolean definition of a case of error, we added ERR in case when we set if a character is friendly or hostile if theres some problem*/
typedef enum { ERR = -1, FALSE, TRUE } Bool;

/*A status definition of a case of error*/
typedef enum { ERROR, OK } Status;

/*The cardinal points, north, south, east and west*/
typedef enum { N, S, E, W, NOTKNOWN } Direction;

#endif
