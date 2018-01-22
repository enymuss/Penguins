//
//  placement.c
//  Penguins
//  created by Ernest Pokropek 10/12/2017
//
//


#include "placement.h"

void placePenguin(int playerID, string position);
int convertToInt(char character, int startingPoint);
bool positionIsValid(int playerID, string position);

int placement(){
    string position = "";
    int i, playerID;
    for(i=0; i < maxNumberOfPenguinsPerPlayer; i++){
        for(playerID=0; playerID < numberOfPlayers; playerID++){
            printf("Player : %d\n", playerID);
            printf("Enter location: ");
            scanf("%s", position);
            if (positionIsValid(playerID, position)) {
                placePenguin(playerID, position);
            } else {
                playerID--; //repeat
            }
            printMap(map);
        }
    }
    printf("All penguins placed; \n");
    
    return 0;
}

bool positionIsValid(int playerID, string position) {
    int X = convertToInt(position[0], 'A');
    int Y = convertToInt(position[1], '0');
    int fishes = convertToInt(map[X][Y], '0');
    if (fishes == 1) {
        return true;
    }
    
    printf("Choose block with 1 fish! \n");
    return false;
}

void placePenguin(int playerID, string position){
    int X = convertToInt(position[0], 'A');
    int Y = convertToInt(position[1], '0');
    map[X][Y]=(playerID+96); //ASCII 97='a' for player 1, 98='b' for player 2 etc.
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
