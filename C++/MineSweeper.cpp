#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
//#include<>
using namespace std;

void showDisplay(short mineF[][9], string playerM[][9]);
void createMines();
void createNumberGrid();
void fillPlayerMarkerGrid(string playerM[][9]);
void playerInput();
//void

int main(){
  short mineField[9][9]; //0: empty - do not display, 1-8: normal bomb numbers, 9: bomb
  string playerMarkers[9][9]; //0: empty - do not display, ?: a marker for unknown, P: flag for known
  short bombCounter = 10; //the counter for how many bombs there are
  int startTime, endTime; //startTime will take the time(0) of start and endTime will - time(0) from startTime at the end

  fillPlayerMarkerGrid(playerMarkers); //will fill the grid with 0 so nothing will be displayed
  showDisplay(mineField, playerMarkers);

  return 0;
}

void fillPlayerMarkerGrid(string playerM[][9]){
  for(int c = 0; c < 9; c++){
    for(int r = 0; r < 9; r++){
      playerM[c][r] = "1";
    }
  }
}

void showDisplay(short mineF[][9], string playerM[][9]){
/*
with this i want to make a simple grid:
     1 2 3
   a x x x
   b x x x
   c x x x
I have achieved the letters on the side but the numbers across the top prove to be a problem
*/
  int r2 = 0; //for use of the row variable outside of the for loop
  for(int c = 0; c < 10; c++){ //displays the full row before the column switch
    if(c == 0){
      switch(r2){
        case 1: cout << "1";
        break;
        case 2: cout << "2";
        break;
        case 3: cout << "3";
        break;
        case 4: cout << "4";
        break;
        case 5: cout << "5";
        break;
        case 6: cout << "6";
        break;
        case 7: cout << "7";
        break;
        case 8: cout << "8";
        break;
        case 9: cout << "9";
        break;
      }//switch
      cout << " ";
    }//if
    for(int r = 0; r < 10; r++){
      if(r == 0){
        switch(c){
          case 1: cout << "a";
          break;
          case 2: cout << "b";
          break;
          case 3: cout << "c";
          break;
          case 4: cout << "d";
          break;
          case 5: cout << "e";
          break;
          case 6: cout << "f";
          break;
          case 7: cout << "g";
          break;
          case 8: cout << "h";
          break;
          case 9: cout << "i";
          break;
        }//switch
        cout << " ";
      }//if
      else{
        if(playerM[c][r] == "0"){
          if(mineF[c][r] == 0)
            cout << " ";
          else
            cout << mineF[c-1][r-1];
          }//if
        else
          cout << playerM[c-1][r-1];
        cout << " ";
      }//else
    }//for
    cout << endl;
    r2++;
  }//for
}
