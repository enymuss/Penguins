//
//  endGame.h
//  Penguins
//
//  Created by Borys Bondos on 10/12/2017.
//

#ifndef endGame_h
#define endGame_h

#include "main.h"
#include "map.h"

int game_end(int game_type, int fishes_on_board, int turn_number, int possible_move, int numb_of_penguins_team, int x);
int who_win(int playerPoints[MAXPLAYERS]);


#endif /* endGame_h */
