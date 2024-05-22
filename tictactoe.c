#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char board[9];
int gameState = 1; //1 - running 0-over  

void resetBoard();
void printBoard();
int checkDraw();
int cmpBoardCharValue(int,int,int);
int checkResult();

int main(){
    int input_pos,result;
    char turn = 'X';
    resetBoard();
    system("cls");
    printf("Welcome to the TicTacToe!\n\n");
    printBoard();
    while(gameState){
        printf("\nIts %c's turn. Input the position number to play your turn! - ",turn);
        scanf("%d",&input_pos);
        //Changing the turn according to current turn
        if(!(input_pos<1 || input_pos>9)){
            if (board[input_pos-1]==' '){
                board[input_pos-1] = turn;

                    system("cls");
                    printf("Welcome to the TicTacToe!\n\n");
                    result = checkResult();
                    // printf("res : %d\n",result);
                    if(result == 1){
                        char response;
                        printBoard();
                        printf("\nCongratulation! %c is the winner.\nPress R to play again & Q to exit!",turn);
                        fflush(stdin);
                        scanf("%c",&response);
                        if(response == 'R' || response == 'r' ){
                            resetBoard();
                            system("cls");
                            printBoard();
                            continue;
                        }
                        else if(response == 'Q' || response == 'q'){
                            break;
                        }
                        else{
                            printf("Invalid Response!");
                        }
                        break;
                    }
                    else if (result == -1){
                        printBoard();
                        printf("Ohh! It's a draw. Good game!");
                        break;
                    }
                    else{
                        turn = (turn=='X')?'O':'X';
                        printBoard();
                    }
                }
            else{
                printf("Chosen position is already taken! Choose again.");
            }
        }
        else{
            printf("Please input valid position between 1 to 9!");
        }


    } 

}
void resetBoard(){

    for (int i=0;i<9;i++){
        board[i] = ' ';

    }
}
void printBoard(){
    printf(" %c  | %c  | %c \n",board[0],board[1],board[2]);
    printf("----|----|----\n");
    printf(" %c  | %c  | %c \n",board[3],board[4],board[5]);
    printf("----|----|----\n");
    printf(" %c  | %c  | %c \n",board[6],board[7],board[8]);
}

int checkDraw(){
    int i,emptyPos=0;
    for(i=0;i<9;i++){
        emptyPos = (board[i]==' ')? emptyPos+1:emptyPos;
    }
    return (emptyPos==0)?1:0;
}

int cmpBoardCharValue(int pos1,int pos2, int pos3){
    /*Takes input of position on the board and compare its values */
    // printf("board[%d]  board[%d]  board[%d] = '%c'  '%c'  '%c'",pos1,pos2,pos3,board[pos1],board[pos2],board[pos3]);
    // printf("empty? : %d\n",(board[pos1]==' ' &&  board[pos2 ]==' ' && board[pos3]==' '));
    if (!(board[pos1]==' ' &&  board[pos2 ]==' ' && board[pos3]==' ')) {
        // printf("pos1-%d pos2-%d pos3-%d\t",pos1,pos2,pos3);
        // printf("Comparing : board[%d]==board[%d]==board[%d] Result: %d\n",pos1,pos2,pos3,(board[pos1]==board[pos2] && board[pos1]==board[pos3]) );
        return (board[pos1]==board[pos2] && board[pos1]==board[pos3]);
    }
    else{
        return -1;
    }
}


int checkResult(){
    int result;
    int i,k;
    for (i=0;i<8;i++){
        switch (i)
        {
        case 0:
            k = cmpBoardCharValue(0,1,2);
            break;
        case 1:
            k = cmpBoardCharValue(3,4,5);
            break;
        case 2:
            k = cmpBoardCharValue(6,7,8);
            break;
        case 3:
            k = cmpBoardCharValue(0,3,6);
            break;
        case 4:
            k = cmpBoardCharValue(1,4,7);
            break;
        case 5:
            k = cmpBoardCharValue(2,5,8);
            break;
        case 6:
            k = cmpBoardCharValue(0,4,8);
            break;
        case 7:
            k = cmpBoardCharValue(2,4,6);
            break;
        default:
            break;
        
        }
        // printf("k: %d  ",k);
        if(k==1){
            result = 1;
            break;
        }
        else if(checkDraw() && k!=1){
            result = -1;
        }
        else{
            result = 0;
        }

    }  
    return result;
}