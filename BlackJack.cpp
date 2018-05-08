#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

void cards(short number){
  cout << "_________\n";
  cout << "|" << setw(9) << "|\n";
  cout << "|" << setw(9) << "|\n";
  cout << "|" << setw(4) << number << setw(5) << "|\n";
  cout << "|" << setw(9) << "|\n";
  cout << "|" << setw(9) << "|\n";
  cout << "---------\n";
}


int setup(){
  short numEntry = 5;
  char game;

  cout << "Do you want to play some Black Jack?\n";
  cin >> game;

  //Whether they want to play BJ
  switch(game){
    case 'n':
    case 'N': return 0;
    break;
    default: cout << "Starting...\n";
  }
}


int main(){
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

  }

}
  return 0;
}
