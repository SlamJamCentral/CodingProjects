#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
//#include<
using namespace std;

int boolinator(bool tester[][5]);
int shuffler(string array[][5], string queue[], bool used[][5]);

int main(){
  bool tester[3][5];
  string music[3][5] = {{"Q1","Q2","Q3","Q4","Q5"},{"W1","W2","W3","W4","W5"},{"E1","E2","E3","E4","E5"}};
  string queue[15];
  shuffler(music, queue, tester);

  for(int x = 0; x < 15; x++){
    cout << queue[x] << endl;
  }

  return 0;
}

int boolinator(bool tester[][5]){
  for(int r = 0; r < 3; r++){
    for(int c = 0; c < 5; c++){
      tester[r][c] = false;
    }
  }
}

int shuffler(string array[][5], string queue[], bool used[][5]){
  srand(time(0));
  boolinator(used);
  short q = 0;
  short r, c;
  do{
    do{
      r = rand() % 3;
      c = rand() % 5;
    }while(used[r][c] == true);
    queue[q] = array[r][c];
    used[r][c] = true;
    q++;
  }while(q < 15);
}
