#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

void cardGraphic(short number);
int howManyRounds();

int main(){
  srand(time(0));
  int rounds = howManyRounds(); //how many rounds they want to play BJ

  for(int x = 1; x <= rounds; x++){//repeats for the amount that you entered
    int gameTrig = 1;

    while(gameTrig == 1){
      int card = ((rand() % 10)+1);//assigns the card number to 1-13 !!ONLY IN THIS LOOP!!

      if(card == 1){
        do{
          cout << "You got an Ace! Do you want that to be a 1 or 11? " << endl;
          cin >> card;
        }while(card != 1 || card != 11);
      }

      cardGraphic(card);

      char addC = ' ';

      do{
        cout << "You have a " << card << "do you want to add another card or fold? [A]dd or [F]old: " << endl;
        cin >> addC;
      }while(addC != 'A' || addC != 'a' || addC != 'F' || addC != 'f');



    }//End of While Loop (when the user folds or is over 21 it ends)
  }//End of the game loop (it loops while they still have rounds to play)
  return 0;
}

void cardGraphic(short number){//Display the card number
  cout << "_________\n";
  cout << "|" << setw(9) << "|\n";
  cout << "|" << setw(9) << "|\n";
  cout << "|" << setw(4) << number << setw(5) << "|\n";
  cout << "|" << setw(9) << "|\n";
  cout << "|" << setw(9) << "|\n";
  cout << "---------\n";
}

int howManyRounds(){
  short rounds;
  cout << "How many rounds of BlackJack do you want to play? " << endl;
  cin >> rounds;
  return rounds;
}

/*
setup();
cout << "\n";
srand(time(0));
short number, totalNum; //card number -- total number of the cards
char addVar; //char for adding cards
bool addC = false, gameFlag = false; //Bool to add a Card -- bool to end the game

while(gameFlag == false){

do{
  number = rand();
  number = number % 11;
  ++number;
}while(number <= 0 || number >= 12);

if(number == 1){
  cout << "You got an ace! Do you want that to be 1 or 11?";
  cin >> number;
}

cards(number);

cout << "\nDo you want to add another card? (y/n) ";
cin >> addVar;

switch(addVar){
  case 'y':
  case 'Y':
*/
