//Random Prime Number Generator
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

int howManyRounds(){
  int rounds;

  do{
    cout << "This takes a long time. Start at your own risk." << endl;
    cout << "How many numbers would you like to generate? " << endl;
    cin >> rounds;
  }while(rounds < 1 || rounds > 5);

  return rounds;
}

int numberGenerator(){
  int number;
  bool prime;
  srand(time(0));

  do{
    number = rand();
    cout << "Testing: " << number << endl;

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
  int numbers, startTime, endTime, totTime;
  int repeats = howManyRounds();

  startTime = time(0);
  cout << "Starting time: " << startTime << endl;

  for(int x = 1; x <= repeats; x++){
    numbers = numberGenerator();
    cout << "Prime Number: " << numbers << endl;
  }

  endTime = time(0);
  cout << "Ending time: " << endTime << endl;

  totTime = endTime - startTime;
  cout << "Total elapsed time: " << totTime << endl;

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
15265050101
1526505012
*/
