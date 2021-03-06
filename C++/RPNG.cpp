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
    cout << "[3] A mixture of the two. Find a random number and add until you get a prime\n";
    cout << "[4] Test a number to see if it's prime.\n";
    cin >> oneOrTwo;
  }while(oneOrTwo != 1 && oneOrTwo != 2 && oneOrTwo != 3 && oneOrTwo != 4);

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
  short min;
  int num = 2;
  bool prime = true;

  cout << "How many minutes do you run for? " << endl;
  cin >> min;
  min *= 60;
  int startTime = time(0);
  int endTime = time(0) + min;

  cout << "1" << endl;
  while(time(0) != endTime && time(0) < endTime){
    prime = true;
    for(int x = 2; x < num; x++){
      if((num % x) == 0.0){
        prime = false;
        break;
      }
    }
    if(prime == true)
      cout << num << endl;
    num++;
    }
}

int mixingPot(){
  int number, startTime;
  bool prime = false;
  startTime = time(0);
  srand(time(0));

  number = rand();
  static_cast<double>(number);

  while(!prime){
    number++;
    for(int n = 2; n < number; n++){
      if((number % n) == 0)
        break;
    }
    if(time(0) - startTime == 300){
      cout << "Program ran for 5 minutes and then ended in order to save time.\n";
      prime = true;
      number = 1;
      break;
    }
  }

  return number;
}

void testNum(){
  long int number;
  bool prime = true;

  cout << "What's the number you wish to test?\n(Enter -1 to quit)\n";
  cin >> number;

  do{
    for(int x = 2; x < number; x++){
      if((number % x) == 0.0){
        cout << "The number " << number << " is not prime.\n";
        cout << "It is divisable by " << x << ".\n";
        prime = false;
      }
      if((number % x) == 0.0)
        break;
    }
    if(prime)
      cout << "The number " << number << " is prime.\n";

    cout << "\nWhat's the number you wish to test?\n(Enter -1 to quit)\n";
    cin >> number;
  }while(number != -1);
}

int main(){
  int numbers, startTime, endTime, totTime, whichWay;

  whichWay = howDoYou();

  if(whichWay == 1){
    startTime = time(0);
    cout << "Starting time: " << startTime << endl;

    numbers = numberGenerator(startTime);
    cout << "Prime Number: " << numbers << endl;

    endTime = time(0);
    totTime = endTime - startTime;
    cout << "Total elapsed time: " << totTime << " seconds" << endl;
  }
  if(whichWay == 2)
    oneToInfinty();
  if(whichWay == 3){
    numbers = mixingPot();
    cout << numbers << endl;
  }
  if(whichWay == 4){
    testNum();
  }
  return 0;
}
