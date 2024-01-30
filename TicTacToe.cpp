#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
bool toss_win(int choice){
    srand(time (0));
    if ((rand()%2)==choice){
        return 0;
    }
    return 1;
}
void displaygrid(char array[]){
    cout<<"  "<<array[0]<<"  |  "<<array[1]<<"  |  "<<array[2]<<"  \n"
          "-----------------\n"
          "  "<<array[3]<<"  |  "<<array[4]<<"  |  "<<array[5]<<"  \n"
          "-----------------\n"
          "  "<<array[6]<<"  |  "<<array[7]<<"  |  "<<array[8]<<"  \n";
}

void get_move(char array[],int iteration,string player){
    int move;
    int symbol;
    
    if(iteration %2==0){
           cout<<player<<" Enter your move : ";
           cin>>move;
           symbol='O';
    }
    else {cout<<player<<" Enter your move : ";
         cin>>move;
         symbol='X';
        
    }
    if ((move<=9)&&(move>=1)&& (array[move-1]!='X')&&(array[move-1]!='O')){
        array[move-1]=symbol;
    }
    else{
        cout<<"invalid move"<<endl<<"try again "<<endl;
        get_move(array,iteration,player);
    }
   
}
/// win
    bool win(char array[]){
    bool b;
if ((array[0] == array[1] && array[1] == array[2]) ||
    (array[3] == array[4] && array[4] == array[5]) ||
    (array[6] == array[7] && array[7] == array[8]) ||
    (array[0] == array[3] && array[3] == array[6]) ||
    (array[0] == array[4] && array[4] == array[8]) ||
    (array[2] == array[4] && array[4] == array[6]) ||
    (array[1] == array[4] && array[4] == array[7]) ||
    (array[2] == array[5] && array[5] == array[8])){
    b =1;
    }
    else{
      b = 0 ;
    }
 return b;

}
int announcing_winer( char array[],int iteration,string player){
    if((iteration==8)&&(win(array)==0)){
        cout<<"*******Match Draw********"<<endl;
        return 0;
    }
    if (win(array)==1){
        if(iteration%2==0){
            cout<<"******"<<player<<" win*******"<<endl;;
        }
        else if(iteration%2==1){
            cout<<"*******"<<player<<" win*******"<<endl;
            }
        return 0;
}
    return 1;
}

int main(){
int choice;
char array[]={'1','2','3','4','5','6','7','8','9'};
cout<<"*****Welcome to tictak*****"<<endl;
string player1,player2,player;
cout<<"player1 Enter your name : ";
getline(cin,player1);
cout<<"player2 Enter your name : ";
getline(cin,player2);
cout<<player1<<" Enter (heads)=0 or (tails)=1 : "<<endl;
cin>>choice;
displaygrid(array);
for(int i=0+(toss_win(choice));i<9+(toss_win(choice));i++){
    if(i%2==0){ player=player1;}
    else{player=player2;}
    get_move(array,i,player);
    system("clear");
    displaygrid(array);
    if(announcing_winer(array,i,player)==0){
        break;
        }
    }    
    return 0;
}
