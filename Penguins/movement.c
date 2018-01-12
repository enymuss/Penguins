 //
 //  movement.c
 //  Penguins
 //
 //  created by Ernest Pokropek 10/12/2017
 //
 //

#include "movement.h"

bool pathPossible(string position, string destination);
bool pathCorrect(string position, string destination);
int getFishesFromCharacter(char character);

bool isPenguinYours(int, int);
bool teamCorrect(string playerTurn, string playerID);
bool insideMap(string position, string destiantion);
bool isPenguinAtDestination(string destination);
bool movementPossible(string position, string destination);

int initMovement() {
    string position, destination;
    int playerID = 0;
    int count = 0;
    while (penguinsOnBoard(map)!= 0) {
        printMap(map);
        playerID = (count%numberOfPlayers)+1;

        printf("Player %d move penguin\n", playerID);
        printf("From Location: ");
        scanf("%s", position);
        printf("To Destination: ");
        scanf("%s", destination);

        movement(position, destination, playerID);
        count++;
    }

    return 0;
}


int movement(string position, string destination, int playerID){

    int Xp=convertToInt(position[0], 'A');
    int Yp=convertToInt(position[1], '0');
    int Xd=convertToInt(destination[0], 'A');
    int Yd=convertToInt(destination[1], '0');

  if(isPenguinYours(playerID, playerTurn)==false){
        printf("It's not your penguin!\n");
  }
  else{
  if(movementPossible(position,destination)==true) {
      playerPoints[playerID-1] += getFishesFromCharacter(map[Xp][Yp]);
      map[Xp][Yp]=' ';
      int fishesAtDestination = convertToInt(map[Xd][Yd], '0');
      switch (fishesAtDestination) {
          case 1:
              map[Xd][Yd]=playerID+96;
              break;
          case 2:
              map[Xd][Yd]=playerID-1+'A';
              break;
          case 3:
              map[Xd][Yd] = playerID-1+'U';
              break;

          default:
              printf("Good Penguin. Found bug but no fishes.\n");
              exit(1);
              break;
      }

   }
   else printf("Wrong destination! \n");
  }

  return 0;
  
}

bool pathPossible(string position, string destination) {

    int Xp=convertToInt(position[0], 'A');
    int Yp=convertToInt(position[1], '0');
    int Xd=convertToInt(destination[0], 'A');
    int Yd=convertToInt(destination[1], '0');

    if(abs(Xd-Xp)==abs(Yd-Yp)) return true;
    else if (abs(Xd-Xp) == 0) return true; // diagonally
    else if (abs(Yd-Yp) == 0) return true; // vertically
    else return false;

}

bool pathCorrect(string position, string destination){

    int Xp=convertToInt(position[0], 'A');
    int Yp=convertToInt(position[1], '0');
    int Xd=convertToInt(destination[0], 'A');
    int Yd=convertToInt(destination[1], '0');

    int pathLength=sqrt((abs(Xd-Xp)*abs(Xd-Xp))+(abs(Yd-Yp)*abs(Yd-Yp))); // nice
    int i;

    if (Xd == Xp){ // horizontally
        if(Yd>Yp){ // right
            for(i=1; i <= pathLength; i++){
                if(map[Xp][Yp+i]<'1'|| map[Xp][Yp+i]>'3') return false;
            } return true;
        }
        else if(Yd<Yp){ // left
            for(i=1; i<=pathLength; i++){
                if(map[Xp][Yp-i]<'1'|| map[Xp][Yp-i]>'3') return false;
            } return true;
        }
        else {
            printf("You can't stay here, dummy! ");
            return false;
        }
    }
    else if (Xd>Xp){ // down
        if(Yd>Yp){ // right
            for(i=1; i <= pathLength; i++){
                if(map[Xp+i][Yp+i]<'1'|| map[Xp+i][Yp+i]>'3') return false;
            }return true;
        }
        else if(Yd<Yp){ // left
            for(i=1; i <= pathLength; i++){
                if(map[Xp+i][Yp-i]<'1'|| map[Xp+i][Yp-i]>'3') return false;
            }return true;
        }
        else{ //same column
            for(i=1; i <= pathLength; i++){
                if(map[Xp+i][Yp]<'1'|| map[Xp+i][Yp]>'3') return false;
            }return true;
        }
    }
    else if (Xd<Xp) { // up
        if (Yd>Yp) { // right
            for(i=1; i <= pathLength; i++){
                if(map[Xp-i][Yp+i]<'1'|| map[Xp-i][Yp+i]>'3') return false;
            }return true;
        }
        else if(Yd<Yp){ // left
            for(i=1; i <= pathLength; i++){
                if(map[Xp-i][Yp-i]<'1'|| map[Xp-i][Yp-i]>'3') return false;
            }return true;
        }
        else { //same column
            for(i=1; i <= pathLength; i++){
                if(map[Xp-i][Yp]<'1'|| map[Xp-i][Yp]>'3') return false;
            }return true;
        }
    }
    return false;
}

int getFishesFromCharacter(char character){
    if ('a' <= character && character <= 'a'+MAXPLAYERS){
        return 1;
    }
    if ('A' <= character && character <= 'A'+MAXPLAYERS){
        return 2;
    }
    if ('U' <= character && character <= 'U'+MAXPLAYERS){
        return 3;
    }
    return 0;
}

bool teamCorrect(string playerTurn, string playerID){
   if(playerID==playerTurn) return true;
   else return false;
}

bool insideMap(string position, string destination){

    int Xp=convertToInt(destination[0], 'A');
    int Yp=convertToInt(destination[1], '0');
    int Xd=convertToInt(destination[0], 'A');
    int Yd=convertToInt(destination[1], '0');

    if(Xd>mapRows || Yd>mapColumns ||
        Xd < 0 || Yd < 0 ||
        Xp>mapRows || Yp>mapColumns ||
        Xp < 0 || Yp < 0)return false;
    else return true;
}

bool isPenguinYours(int playerID, int playerTurn){
    if(playerID==playerTurn){
        return true;
    }
    else{
        return false;
    }
}



bool movementPossible(string p, string d){    //position, destination
    if(  (pathPossible(p,d)==true)
       &&(pathCorrect(p,d)==true)
       &&(insideMap(p,d)==true)) return true;
        else return false;
}

