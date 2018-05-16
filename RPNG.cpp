//Random Prime Number Generator
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

int howManyRounds(){
  int rounds;

  do{
    cout << "Be reasonable, you don't need anything over 100 or less than 0" << endl;
    cout << "How many numbers would you like to generate? ";
    cin >> rounds;
  }while(rounds < 1 || rounds > 100);

  return rounds;
}

int numberGenerator(){
  int number;
  bool prime;
  srand(time(0));

  do{
    number = rand();

    if((number % 2) == 0)
      prime = false;
    if((number % 3) == 0)
      prime = false;
    if((number % 4) == 0)
      prime = false;
    if((number % 5) == 0)
      prime = false;
    if((number % 6) == 0)
      prime = false;
    if((number % 7) == 0)
      prime = false;
    if((number % 8) == 0)
      prime = false;
    if((number % 9) == 0)
      prime = false;
  }while(prime == false);

  return number;
}

int main(){
  int numbers;
  int repeats = howManyRounds();

  for(int x = 1; x <= repeats; x++){
    numbers = numberGenerator();
    cout << numbers << endl;
  }

  return 0;
}

/*
int number, howMany;

cout << "How many numbers would you like to generate? " << endl;
cin >> howMany;

for(int x = 0; x <= howMany; x++){
  number = rand();
  cout << number << endl;
}
*/
