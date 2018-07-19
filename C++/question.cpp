#include<iostream>
#include<string>
using namespace std; 

//* * * * * * * * * * * * * * * * *
//   <array name>[row][column]    *
//                                *
//          	columns             *
//      [0]         [1-4]         *
//    questions     answers       *
//                                *
//* * * * * * * * * * * * * * * * *

void output(string qA2[][5], int rounds, short rA[][5]);

void fillNull(short array[][5], int fill);

int main(){
	int rounds;
	char yN;
	do{
		cout << "How many questions do you have to ask?\n";
		cin >> rounds;
	}while(rounds <= 0);
	string qA[rounds][5];
	short rightAns[rounds][5];
	fillNull(rightAns, rounds);
	for(int x = 0; x < rounds; x++){
		cin.ignore();
		cout << "\nWhat is the question you'd like to ask?\n";
		getline(cin, qA[x][0]);
		for(int y = 1; y <= 4; y++){
			cout << "Answer " << y << ": " << endl;
			getline(cin, qA[x][y]);
			do{
				cout << "Is that the right answer? (y/n)\n";
				cin >> yN;
				switch(yN){
					case 'Y': yN = 'y';
					break;
					case 'N': yN = 'n';
					break;
				}
				cin.ignore();
			}while(yN != 'n' && yN != 'y');
			if(yN == 'y')
				rightAns[x][y] = 1;
		}
		cout << string(50, '\n');
		output(qA, x, rightAns);
	}
	return 0;
}

void output(string qA2[][5], int r, short rA[][5]){
	short answer;
	cout << "Question: " << qA2[r][0] << endl;
	for(int w = 1; w < 5; w++){
			cout << "Answer " << w << ": " << qA2[r][w] << endl;
	}
	do{
		cout << "What's your answer?: \n";
		cin >> answer;
	}while(answer > 4 && answer < 1);
	cout << "Your answer was " << answer << endl;
	if(rA[r][answer] == 1)
		cout << "That is the right answer!\n";
	if(rA[r][answer] == 0)
		cout << "That is the wrong answer.\n";
	do{
   cout << '\n' << "Press any key to ask another question";
 	}while (cin.get() != '\n');
}

void fillNull(short array[][5], int fill){
	for(int r = 0; r < fill; r++){
		for(int c = 0; c < 5; c++){
			array[r][c] = 0;
		}
	}
}
