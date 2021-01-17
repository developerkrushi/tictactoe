#include<iostream>
using namespace std;

void board();
void winpattern(int player);
void checkwin();

char numbers[9] = {'1','2','3','4','5','6','7','8','9'};
bool win=0;


int main(){
    int value;
    int player=1;
    char mark;    
    int valid_move=1;

    loop:while(true){
        board();
        
        player = (player%2)?1:2;

        if(valid_move==1)
            cout<<"\n\nIt's your turn, Player"<<player<<" : ";
        else if(valid_move==0)
            cout<<"\n\nPlease enter the correct value, Player"<<player<<" : ";
            

        cin>>value;
        mark = (player==1)?'X':'O';

        int x = numbers[value-1];
        x -= 48;
        if(x == value){
            numbers[value-1] = mark;
            player++;
            valid_move = 1;
            checkwin();}
        else{
            valid_move = 0;
            goto loop;
            } 
        

        if(win)
            winpattern(++player);
    }

    
    
    return 0;
}

void board(){

    system("cls");

    cout<<"\n\n\t       TicTacToe    "<<endl;
    cout<<"\t                      "<<endl;
    cout<<"\tPlayer1 : X  Player2 : O"<<endl;
    cout<<"\t                      "<<endl;
    cout<<"\t        |     |       "<<endl;
    cout<<"\t     "<<numbers[0]<<"  |  "<<numbers[1]<<"  |  "<<numbers[2]<<"    "<<endl;
    cout<<"\t   _____|_____|_____  "<<endl;
    cout<<"\t        |     |       "<<endl;
    cout<<"\t     "<<numbers[3]<<"  |  "<<numbers[4]<<"  |  "<<numbers[5]<<"    "<<endl;
    cout<<"\t   _____|_____|_____  "<<endl;
    cout<<"\t        |     |       "<<endl;
    cout<<"\t     "<<numbers[6]<<"  |  "<<numbers[7]<<"  |  "<<numbers[8]<<"    "<<endl;
    cout<<"\t        |     |       "<<endl;
    cout<<"\t                      "<<endl;

 
}

void checkwin(){
       
    if (numbers[0] == numbers[1] && numbers[1] == numbers[2])
		win = 1;
	else if (numbers[3] == numbers[4] && numbers[4] == numbers[5])
		win = 1;
	else if (numbers[6] == numbers[7] && numbers[7] == numbers[8])
		win = 1;
	else if (numbers[0] == numbers[3] && numbers[3] == numbers[6])
		win = 1;
	else if (numbers[1] == numbers[4] && numbers[4] == numbers[7])
		win = 1;
	else if (numbers[2] == numbers[5] && numbers[5] == numbers[8])
		win = 1;
	else if (numbers[0] == numbers[4] && numbers[4] == numbers[8])
		win = 1;
	else if (numbers[2] == numbers[4] && numbers[4] == numbers[6])
		win = 1;
	else 
    	win = 0;

}

void winpattern(int player){

    board();
    int value;
    player = (player%2)?1:2;

    cout<<"\nPlayer"<<player<<" has won!!\nPress 1 to play again, 0 to quit:  ";
    cin>>value;

    if(value==1){
        char j='1';
        for(int i=1;i<10;i++){numbers[i-1]=j;j++;}
        main();
    }
    else
    {
        exit(0);
    }
    

 
}
