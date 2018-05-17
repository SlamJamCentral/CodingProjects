//Random Prime Number Generator
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

int howDoYou(){
  int oneOrTwo;

  do{
    cout << "There are two ways to find a prime number in this program.\n"
         << "[1] Find a random number and see if it's prime (Will cut off after 5 minutes)\n"
         << "[2] Get a random number and then add something to it until it's prime\n";
    cin >> oneOrTwo;
  }while(oneOrTwo != 1 && oneOrTwo != 2);

  return oneOrTwo;
}

int numberGenerator(int startTime){
  int number;
  bool prime;
  srand(time(0));

  do{
    if((time(0) - startTime) >= 300){
      cout << "In order to save your RAM, the program has ended after 5 minutes. :/" << endl;
      number = 1;
      break;
    }

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
  int numbers, startTime, endTime, totTime, whichWay;

  whichWay = howDoYou();

  startTime = time(0);
  cout << "Starting time: " << startTime << endl;

  if(whichWay == 1)
    numbers = numberGenerator(startTime);
  if(whichWay == 2){
    //numbers =
//2 to the power of X - 1

  cout << "Prime Number: " << numbers << endl;

  endTime = time(0);
  totTime = endTime - startTime;
  cout << "Total elapsed time: " << totTime << " seconds" << endl;

  return 0;
}
