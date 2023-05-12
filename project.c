
#include <stdio.h>

#include <stdbool.h>


char board[3][3];
char chance='O';
void init(){
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    board[i][j]='-';
}

void print(){
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
    printf("%c\t",board[i][j]);}
    printf("\n");
}

}
void change(){
    chance=(chance=='O')?'X':'O';
}
char win(){
    //checking rows
    for(int i=0;i<3;i++)
    if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
    return board[i][0];
    //checking columns
    for(int i=0;i<3;i++)
    if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
    return board[0][i];
    //checking diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
    return board[0][0];
}
void mark(int i,int j){
    if(board[i][j]=='-')
    board[i][j]=chance;
    else
    printf("Chance Wasted");
}
void understand(int i){
    switch(i){
        case 1:
            mark(0,0);
            break;
        case 2:
            mark(0,1);
            break;
        case 3:
            mark(0,2);
            break;
        case 4:
            mark(1,0);
            break;
        case 5:
            mark(1,1);
            break;
        case 6:
            mark(1,2);
            break;
        case 7:
            mark(2,0);
            break;
        case 8:
            mark(2,1);
            break;
        case 9:
            mark(2,2);
            break;
        default:
            printf("\nTurn Wasted\n");
        
    }
}
bool fill(){
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(board[i][j]=='-')
    return true;
    return false;
}
int main(){
      init();
    printf("Welcome To Tic Tac Toe\n");
    printf("----------------------------Starting Board---------------------------\n");
    print();
    int i,j;
    while(win()=='-' && fill()){
        printf("Enter the Cell index(%c turn)",chance);
        scanf("%d",&i);
        understand(i);
        change();
        printf("----------------------------Current Board---------------------------\n");
        print();
    }
    if(win()=='-')
    printf("No One WON!! Its a TIE");
    else
    printf("%c WON!!!!!!!!!!!!",win());
    
   
}
