//
//  map.h
//  Penguins
//
//  Created by Richard Szczerba on 26/11/2017.
//

#ifndef map_h
#define map_h

#include "main.h"

#endif /* map_h */

#define MAXPLAYERS 6

extern int playerTurn, numberOfPlayers, maxNumberOfPenguinsPerPlayer;
extern int playerPoints[MAXPLAYERS];
extern char phase[10];
extern char **map;
extern int mapRows;
extern int mapColumns;

extern void readMap(const char *nameOfFile);
extern void printMap(char **map);
extern int penguinsOnBoard(char **map);
extern void outputMap(const char *fileName);
extern void printScores(void);
