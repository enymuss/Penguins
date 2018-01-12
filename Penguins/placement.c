//
//  placement.c
//  Penguins
//  created by Ernest Pokropek 10/12/2017
//
//


#include "placement.h"

void placePenguin(int playerID, string position);
int convertToInt(char character, int startingPoint);

int placement(){
    string position = "";
    int i, playerID;
    for(i=0; i < maxNumberOfPenguinsPerPlayer; i++){
        for(playerID=1; playerID <= numberOfPlayers; playerID++){
            printf("Player : %d\n", playerID);
            printf("Enter location: ");
            scanf("%s", position);
            placePenguin(playerID, position);
            printMap(map);
        }
    }
    printf("All penguins placed; \n");
    
    return 0;
}

void placePenguin(int playerID, string position){
    //TODO: REDO until penguin is placed
    int X = convertToInt(position[0], 'A');
    int Y = convertToInt(position[1], '0');
    int fishes = convertToInt(map[X][Y], '0');
    if (fishes != 1) {
        printf("Choose block with 1 fish! \n");
    }
    else {
        map[X][Y]=(playerID+96); //ASCII 97='a' for player 1, 98='b' for player 2 etc.
    }
    
}

int convertToInt(char character, int startingPoint){
    if (character >= 'A'){
        return (toupper(character) - startingPoint);
    }
    else {
        return (character - startingPoint);
    }
    return 0;
};
