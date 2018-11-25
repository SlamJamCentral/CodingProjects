#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
//#include<
using namespace std;

void displayQ(string qA[]){
  cout << "\nQuestion: " << qA[0] << endl;
  cout << "A: " << qA[1] << endl;
  cout << "B: " << qA[2] << endl;
  cout << "C: " << qA[3] << endl;
  cout << "D: " << qA[4] << endl;
}

short findPack(){
  short answer;
  cout << "What question pack would you like to open? \n";
       << "[1] Random Pack\n";
       << "[2] Abby's Pack\n";
  cin >> answer;
  return answer;
}

void loadThePack(short qPack, string qaa[5][5]){
  ifstream document;
  string word;
  string line;
  short r = 0, c = 0;

  switch(qPack){
    case 1:
      document.open("Desktop/DocumentTesting/QuestionPack1.txt");
      if(!document.is_open())
        exit(EXIT_FAILURE);
      document >> word; //puts the text into a string var
      line = word; //puts the word into a string
      while(document.good()){ //if you are not at the end of a document
        document >> word; //puts the text into a string var
        if(word != "endl"){ //tests to see if the end of the line has come
          line += " " + word; //if the line isnt done, add the word to the string
        }
        else{ //if the end of the line is here
          qaa[r][c] = line; //put the string into the array
          c++; //move onto the next answer slot
          line = "";
          if(c > 4){ //see if the answer slots are filled
            c = 0; //reset the answer slot
            r++; //move on to the question slot
          }//if
        }//else
      }//while
    break;

    case 2:
      document.open("Desktop/DocumentTesting/QuestionPack2.txt");
      if(!document.is_open())
        exit(EXIT_FAILURE);
      document >> word; //puts the text into a string var
      line = word; //puts the word into a string
      while(document.good()){ //if you are not at the end of a document
        document >> word; //puts the text into a string var
        if(word != "endl"){ //tests to see if the end of the line has come
          line += " " + word; //if the line isnt done, add the word to the string
        }
        else{ //if the end of the line is here
          qaa[r][c] = line; //put the string into the array
          c++; //move onto the next answer slot
          line = "";
          if(c > 4){ //see if the answer slots are filled
            c = 0; //reset the answer slot
            r++; //move on to the question slot
          }//if
        }//else
      }//while
    break;
  }
}

int main(){
  short questionPack, questionNumber; //what set of questions, what is the number you're on
  char answer; //what is the answer you would like to select
  string questAndAnswer[5][5] //displays Q+A, 0-13 = question number, 0 = Q, 1-4 = A

  short packN = findPack()
  loadThePack(packN, questAndAnswer){
  return 0;
}

/* ~~TIMER~~
int startTime = time(0);
if(time(0) >= (startTime + 15)){
  cout << "You ran out of time! Better Hurry up next time!";
  <some code here that triggers the wrong answer
}
