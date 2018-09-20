#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<string>
using namespace std;

void displayCards(short number);
int howManyRounds();
int houseTurn();

int main(){
  int rounds = howManyRounds(); //how many rounds they want to play BJ
  srand(time(0));
  short endG = 1, totCards = 0;

  for(int x = 1; x <= rounds; x++){//repeats for the amount that you entered
    endG = 1;
    totCards = 0;
    int houseVar = houseTurn();
    cout << "\n " << endl;
    while(endG != 0){
      int card = ((rand() % 10)+1);

      if(card == 1){
        do{
          cout << "You got an Ace! Do you want it to be a 1 or 11?" << endl;
          cin >> card;
        }while(card != 1 && card != 11);
      }
      totCards += card;
      displayCards(card);

      if(totCards > 21){
        cout << "You exceded the number 21. You lose!" << endl;
        endG = 0;
        break;
      }

      if(totCards == 21){
        cout << "Congrats! You got a perfect score!" << endl;
        endG = 0;
        break;
      }

      int addOrNo = 0;

      do{
        addOrNo = 0;
        char addCard;

        cout << "Your card(s) amount to " << totCards << ". Do you want to [A]dd or [F]old? " << endl;
        cin >> addCard;

        switch(addCard){
          case 'a':
          case 'A': addOrNo = 2;
                    break;
          case 'f':
          case 'F': addOrNo = 1;
                    break;
          default: addOrNo = 0;
        }
      }while(addOrNo != 2 && addOrNo != 1);// 2 = add -- 1 = fold

      if(addOrNo == 1)
        endG = 0;

    }//Game buffer
    cout << "You finished with a score of " << totCards << endl;
    cout << "The house finished with a score of " << houseVar << endl;

    if(houseVar <= 21){
      if(totCards > houseVar)
        cout << "You got a better score than the house, YOU WIN!" << endl;

      if(totCards < houseVar)
        cout << "You got a worse score than the house, you lose." << endl;

      if(totCards == houseVar)
        cout << "You and the house got the same score, no one wins";
    }
    else{
      if(houseVar > 21){
        cout << "The house finished with a score over 21" << endl;
        cout << "You win by default" << endl;
      }
    }

    cout << "\n " << endl;

  }//For Loop End
  return 0;
}//End of Main

void displayCards(short number){//Display the card number
  srand(time(0));
  short cardType = ((rand() % 4)+1);
  string suite;
  //µ = alt M
  //ß = alt S
  //π = alt P
  //ø = alt O

  switch(cardType){
    case 1: suite = "µ";
            break;
    case 2: suite = "ß";
            break;
    case 3: suite = "π";
            break;
    case 4: suite = "ø";
            break;
    default: suite = "ß";
  }

  cout << "_________\n";
  cout << "|" << setw(8) << suite << setw(1) << "|\n";
  cout << "|" << setw(9) << "|\n";
  cout << "|" << setw(4) << number << setw(5) << "|\n";
  cout << "|" << setw(9) << "|\n";
  cout << "|" << setw(1) << suite << setw(8) << "|\n";
  cout << "---------\n";
}

int howManyRounds(){
  short rounds;
  cout << "How many rounds of BlackJack do you want to play?" << endl;
  cin >> rounds;
  return rounds;
}

int houseTurn(){
  int bTot = 0;
  bool gameA = true;
  srand(time(0));

  while(gameA != false){
    int bCard = ((rand() % 10)+1);
    bTot += bCard;

    if(bTot > 17)
      gameA = false;
  }

  if(bTot > 21)
    bTot -= 2;

  return bTot;
}
