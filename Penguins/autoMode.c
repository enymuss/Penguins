
#include "autoMode.h"

int convertToInt(char character, int startingPoint);
bool movementPossible(string position, string destination);
bool pathPossible(string position, string destination);
bool pathCorrect(string position, string destination);
int getFishesFromCharacter(char character);

bool isPenguinYours(int, int);
bool teamCorrect(string playerTurn, string playerID);
bool insideMap(string position, string destiantion);
bool isPenguinAtDestination(string destination);

int autoPlacement(){
    string position = "";
    int i, playerID;
    srand(time(NULL));
    int fishes=0;
    int X,Y;
    //int loopsleft = (maxNumberOfPenguinsPerPlayer*numberOfPlayers)-penguinsOnBoard(map);
    int loopsleft = 1;
    for(i=0; i < loopsleft; i++){
        playerID = ((playerTurn+i)%numberOfPlayers);
            do
            {
                position[0]=rand()%mapRows+65;
                position[1]=rand()%mapColumns+48;
                X = convertToInt(position[0], 'A');
                Y = convertToInt(position[1], '0');
                fishes = convertToInt(map[X][Y], '0');
            }while(fishes!=1);
            map[X][Y]=(playerID+'a'); //ASCII 97='a' for player 1, 98='b' for player 2 etc.
            playerPoints[playerID] += fishes;
            printMap(map);
    }
    printf("Each player gets %d fishes.\n",playerPoints[0]);
    printf("All penguins placed \n");
    printf("\n");
    
    return 0;
}

int autoMovement()
{
    string position, destination;
    int playerID = 0;
    int count = 0;
    srand(time(NULL));
    
    
    while (count != 1) {
        playerID = (playerTurn%numberOfPlayers);
        
        //Choosing random starting point of each player
        int i,j,k=0;
        char containerRow[maxNumberOfPenguinsPerPlayer];
        char containerCol[maxNumberOfPenguinsPerPlayer];
        int tempNum,randomizeNum;
        int Xd,Yd;
        for(i=0;i<mapRows;i++)
        {
            for(j=0;j<mapColumns;j++)
            {
                if(map[i][j]==97+playerID||map[i][j]==65+playerID||map[i][j]==85+playerID)
                {
                    //printf("map[i][j] : %c\n",map[i][j]);
                    containerRow[k]=i+65;
                    containerCol[k]=j+48;
                    //printf("k: %d, Row : %c, Col : %c\n",k,containerRow[k],containerCol[k]);
                    k++;
                }
            }
        }
        int movementTry = 0;
        do
        {
            movementTry++;
            if (movementTry > 50) {
                return 0;
            }
            tempNum=rand()%maxNumberOfPenguinsPerPlayer;
            position[0]=containerRow[tempNum];
            position[1]=containerCol[tempNum];
            //printf("position : %s\n",position);
            Xd=convertToInt(position[0], 'A');
            Yd=convertToInt(position[1], '0');
            //printf("Xd : %d, Yd : %d\n",Xd,Yd);
            if(Xd==0)
            {
                if(Yd==0)
                {
                    randomizeNum=rand()%3+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+48;
                            break;
                        case 2:
                            destination[0]=Xd+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 3:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+1+48;
                            break;
                    }
                }else if(Yd==mapColumns-1)
                {
                    randomizeNum=rand()%3+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+48;
                            break;
                        case 2:
                            destination[0]=Xd+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 3:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd-1+48;
                            break;
                    }
                }else
                {
                    randomizeNum=rand()%5+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 2:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+48;
                            break;
                        case 3:
                            destination[0]=Xd+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 4:
                            destination[0]=Xd+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 5:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+1+48;
                            break;
                    }
                }
            }else if(Xd==mapRows-1)
            {
                if(Yd==0)
                {
                    randomizeNum=rand()%3+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+48;
                            break;
                        case 2:
                            destination[0]=Xd+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 3:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+1+48;
                            break;
                    }
                }else if(Yd==mapColumns-1)
                {
                    randomizeNum=rand()%3+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+48;
                            break;
                        case 2:
                            destination[0]=Xd+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 3:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd-1+48;
                            break;
                    }
                }else
                {
                    randomizeNum=rand()%5+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 2:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+48;
                            break;
                        case 3:
                            destination[0]=Xd+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 4:
                            destination[0]=Xd+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 5:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+1+48;
                            break;
                    }
                }
            }else
            {
                if(Yd==0)
                {
                    randomizeNum=rand()%5+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+48;
                            break;
                        case 2:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 3:
                            destination[0]=Xd+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 4:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 5:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+48;
                            break;
                    }
                }else if(Yd==mapColumns-1)
                {
                    randomizeNum=rand()%5+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+48;
                            break;
                        case 2:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 3:
                            destination[0]=Xd+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 4:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 5:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+48;
                            break;
                    }
                }else
                {
                    randomizeNum=rand()%8+1;
                    switch(randomizeNum)
                    {
                        case 1:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+48;
                            break;
                        case 2:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 3:
                            destination[0]=Xd-1+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 4:
                            destination[0]=Xd+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 5:
                            destination[0]=Xd+65;
                            destination[1]=Yd+1+48;
                            break;
                        case 6:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd-1+48;
                            break;
                        case 7:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+48;
                            break;
                        case 8:
                            destination[0]=Xd+1+65;
                            destination[1]=Yd+1+48;
                            break;
                    }
                }
                
            }
            //printf("destination[0] : %c,destination[1] : %c\n",destination[0],destination[1]);
        }while(movementPossible(position, destination)==false);
        printf("position : %s ,destination : %c%c, playerID : %d, Turn : %d th\n",position,destination[0],destination[1],playerID+1,count+1);
        
        int tempXp=convertToInt(position[0], 'A');
        int tempYp=convertToInt(position[1], '0');
        int tempXd=convertToInt(destination[0], 'A');
        int tempYd=convertToInt(destination[1], '0');
        playerPoints[playerID] += getFishesFromCharacter(map[tempXp][tempYp]);
        map[tempXp][tempYp]=' ';
        int fishesAtDestination = convertToInt(map[tempXd][tempYd], '0');
        switch (fishesAtDestination) {
            case 1:
                map[tempXd][tempYd]=playerID+'a';
                break;
            case 2:
                map[tempXd][tempYd]=playerID+'A';
                break;
            case 3:
                map[tempXd][tempYd] = playerID+'U';
                break;
                
            default:
                printf("Good Penguin. Found bug but no fishes.\n");
                exit(1);
                break;
                
        }
        
        count++;
        printMap(map);
        printf("Player %d has %d fish now!\n",playerID+1,playerPoints[playerID]);
        printf("\n");
    }
    return 0;
}
