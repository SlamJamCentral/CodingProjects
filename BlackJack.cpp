#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

void cards(short number){//Display the card number
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

  cout << "How many rounds of BlackJack do you want to play?" << endl;
  cin >> rounds;

  return rounds;
}


int main(){
  int rounds = howManyRounds(); //how many rounds they want to play BJ
  srand(time(0));

  for(int x = 1; x <= rounds; x++){//repeats for the amount that you entered
    int card = (rand() % 14)
  }
  return 0;
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
