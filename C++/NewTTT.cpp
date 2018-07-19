#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;

//* * * * * * * * * * * * * * * * *
//    <array name>[row][column]   *
//    this is the board:          *
//                                *
//                columns         *
//                [0 1 2]         *
//    r    [0]    7 8 9           *
//    o    [1]    4 5 6           *
//    W    [2]    1 2 3           *
//* * * * * * * * * * * * * * * * *

int botOrNot();
int rounds();
void drawBoard(char board[][3]);
int xInput();
void xInputValidation(short xIn, char board[][3]);
int oInput();
void oInputValidation(short oIn, char board[][3]);
int testBoard(char board[][3]);
int getRand();

int main(){
  short x, o;
  int endG;
  char board[3][3] = {{'7', '8', '9'}, {'4', '5', '6'}, {'1', '2', '3'}};
  int hmRounds = 1;

  if(botOrNot() == 1){              //If one is a bot
    for(x = 1; x <= hmRounds; x++){ //Repeats to create multiple rounds
      endG = 0;                     //Makes the winner of the round reset
      bool g = true;                //Game trigger is set to active
      while(g != false){            //Keeps the code looping while game is active
        drawBoard(board);           //Draws the board
        x = xInput();               //Gets the numpad number from the user X
        xInputValidation(x, board); //Sends the numpad and the board to
        endG = testBoard(board);    //Tests the board to see if a match was made
        if(endG == 1 || endG == 2){ //Finds the winner and ends the loop early if a winner is detected
          g = false;
          break;
        }
        drawBoard(board);           //Draws the board
        o = getRand();              //Assigns O to a random variable to emulate another person
        oInputValidation(o, board); //...
        endG = testBoard(board);    //Tests the board to see if a match was made
        if(endG == 1 || endG == 2){ //Finds the winner and ends the loop early if a winner is detected
          g = false;
          break;
        }
      }
      cout << "\nPlayer " << endG << " won!" << endl;
      drawBoard(board);
    }
  }
  else{                             //If both are humans
    for(x = 1; x <= hmRounds; x++){ //Repeats to create multiple rounds
      endG = 0;                     //Makes the winner of the round reset
      bool g = true;                //Game trigger is set to active
      while(g != false){            //Keeps the code looping while game is active
        drawBoard(board);           //Draws the board
        x = xInput();               //Gets the numpad number from the user X
        xInputValidation(x, board);
        endG = testBoard(board);    //Tests the board to see if a match was made
        if(endG == 1 || endG == 2){ //Test to end game early
          g = false;
          break;
        }
        drawBoard(board);           //Draws the board
        o = oInput();               //Gets the numpad number from the user O
        oInputValidation(o, board);
        endG = testBoard(board);
        if(endG == 1 || endG == 2)
          g = false;
      } //Game Repeat (While Loop)
      cout << "\nPlayer " << endG << " won!" << endl;
      drawBoard(board);
    } //For Loop Trigger
  } //Else End
  return 0;
} //Main End

int botOrNot(){
  short bot;
  do{
    cout << "Are you playing with 1 player or 2? (Enter '1' or '2'): ";
    cin >> bot;
  }while(bot != 1 && bot != 2);

  return bot;

}

int rounds(){
  int rnds;
  do{
    cout << "How many rounds do you want to play for? ";
    cin >> rnds;
  }while(rnds <= 0);
  return rnds;
}

void drawBoard(char board[][3]){
  cout << "\n " << endl;
  cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  cout << "-----------" << endl;
  cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  cout << "-----------" << endl;
  cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
  cout << "\n " << endl;
}

int xInput(){
  int x;
  do{
    cout << "What move would you like to make for X?: " << endl;
    cin >> x;
  }while(x > 9 || x < 1);
  return x;
}

void xInputValidation(short xIn, char board[][3]){
  if(xIn == 7){
    if(board[0][0] != 'X' && board[0][0] != 'O')
      board[0][0] = 'X';
  }
  if(xIn == 8){
    if(board[0][1] != 'X' && board[0][1] != 'O')
      board[0][1] = 'X';
  }
  if(xIn == 9){
    if(board[0][2] != 'X' && board[0][2] != 'O')
      board[0][2] = 'X';
  }

  if(xIn == 4){
    if(board[1][0] != 'X' && board[1][0] != 'O')
      board[1][0] = 'X';
  }
  if(xIn == 5){
    if(board[1][1] != 'X' && board[1][1] != 'O')
      board[1][1] = 'X';
  }
  if(xIn == 6){
    if(board[1][2] != 'X' && board[1][2] != 'O')
      board[1][2] = 'X';
  }

  if(xIn == 1){
    if(board[2][0] != 'X' && board[2][0] != 'O')
      board[2][0] = 'X';
  }
  if(xIn == 2){
    if(board[2][1] != 'X' && board[2][1] != 'O')
      board[2][1] = 'X';
  }
  if(xIn == 3){
    if(board[2][2] != 'X' && board[2][2] != 'O')
    board[2][2] = 'X';
  }
}

int oInput(){
  int o;
  do{
    cout << "What move would you like to make for O?: " << endl;
    cin >> o;
  }while(o > 9 || o < 1);
  return o;
}

void oInputValidation(short oIn, char board[][3]){
  if(oIn == 7){
    if(board[0][0] != 'X' && board[0][0] != 'O')
      board[0][0] = 'O';
  }
  if(oIn == 8){
    if(board[0][1] != 'X' && board[0][1] != 'O')
      board[0][1] = 'O';
  }
  if(oIn == 9){
    if(board[0][2] != 'X' && board[0][2] != 'O')
      board[0][2] = 'O';
  }

  if(oIn == 4){
    if(board[1][0] != 'X' && board[1][0] != 'O')
      board[1][0] = 'O';
  }
  if(oIn == 5){
    if(board[1][1] != 'X' && board[1][1] != 'O')
      board[1][1] = 'O';
  }
  if(oIn == 6){
    if(board[1][2] != 'X' && board[1][2] != 'O')
      board[1][2] = 'O';
  }

  if(oIn == 1){
    if(board[2][0] != 'X' && board[2][0] != 'O')
      board[2][0] = 'O';
  }
  if(oIn == 2){
    if(board[2][1] != 'X' && board[2][1] != 'O')
      board[2][1] = 'O';
  }
  if(oIn == 3){
    if(board[2][2] != 'X' && board[2][2] != 'O')
      board[2][2] = 'O';
  }
}

int testBoard(char board[][3]){
  //Down - X
  if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
    cout << "Player 1 (X) Wins!" << endl;
    return 1;
  }
  if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
    cout << "Player 1 (X) Wins!" << endl;
    return 1;
  }
  if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
    cout << "Player 1 (X) Wins!" << endl;
    return 1;
  }

  //Across - X
  if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
    cout << "Player 1 (X) Wins!" << endl;
    return 1;
  }
  if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
    cout << "Player 1 (X) Wins!" << endl;
    return 1;
  }if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
    cout << "Player 1 (X) Wins!" << endl;
    return 1;
  }

  //Diaginal - X
  if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
    cout << "Player 1 (X) Wins!" << endl;
    return 1;
  }
  if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'){
    cout << "Player 1 (X) Wins!" << endl;
    return 1;
  }


  //Down - O
  if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
    cout << "Player 2 (O) Wins!" << endl;
    return 2;
  }
  if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
    cout << "Player 2 (O) Wins!" << endl;
    return 2;
  }
  if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
    cout << "Player 2 (O) Wins!" << endl;
    return 2;
  }

  //Across - O
  if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
    cout << "Player 2 (O) Wins!" << endl;
    return 2;
  }
  if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
    cout << "Player 2 (O) Wins!" << endl;
    return 2;
  }if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
    cout << "Player 2 (O) Wins!" << endl;
    return 2;
  }

  //Diaginal - O
  if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
    cout << "Player 2 (O) Wins!" << endl;
    return 2;
  }
  if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'){
    cout << "Player 2 (O) Wins!" << endl;
    return 2;
  }
  return 0;
}

int getRand(){
  srand(time(0));
  int var;

  do{
    var = rand();
    var %= 10;
  }while(var > 9 || var < 1);

  return var;
}
