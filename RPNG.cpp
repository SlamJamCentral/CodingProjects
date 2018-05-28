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
         << "[2] Start at one, start adding, and display all the prime numbers on the way\n";
    cin >> oneOrTwo;
  }while(oneOrTwo != 1 && oneOrTwo != 2);

  return oneOrTwo;
}

int numberGenerator(int startTime){
  int number, prime;
  srand(time(0));

  number = rand();

  do{
    cout << "Testing: " << number;

    prime = 0;
    for(long int x = 2; x < number; x++){
      if((number % x) == 0){
        cout << " - Failed" << endl;
        prime++;
      }
    }
    if(prime == 0)
      cout << " - Passed" << endl;
    if(prime != 0)
      number++;
  }while(prime != 0);

  return number;
}

void oneToInfinty(){
  long int endN;
  bool prime = false;

  do{
    cout << "What number do you want to stop at? " << endl;
    cin >> endN;
  }while(endN < 1);

  cout << "1" << endl;
  for(int x = 2; x <= endN; x++){
    prime = true;
    for(int y = 1; y < x; y++){
      if((x % y) == 0){
        prime = false;
        break;
      }
    }
    if(prime == true)
      cout << x << endl;
  }
}

int main(){
  int numbers, startTime, endTime, totTime, whichWay;

  whichWay = howDoYou();

  startTime = time(0);
  cout << "Starting time: " << startTime << endl;

  if(whichWay == 1){
    numbers = numberGenerator(startTime);
    cout << "Prime Number: " << numbers << endl;
  }
  if(whichWay == 2){
    oneToInfinty();

  endTime = time(0);
  totTime = endTime - startTime;
  cout << "Total elapsed time: " << totTime << " seconds" << endl;

  return 0;
}
}
