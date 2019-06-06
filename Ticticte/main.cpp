#include <iostream>
#define MAX 10
using namespace std;
const int arrRow = 3;
const int arrCol = 3;

void inputArray(char arr[][arrCol], int row, int colum);
void outputArray(char arr[][arrCol], int row, int colum);
int checkwin();
void welcome();

int sumPointWin = 3;
int choice;
char arr[arrRow][arrCol];



int main() {

	
	int player = 1;
	int countTurnP1 = 0;
	int countTurnP2 = 0;
	int check;	

	char sign;
	char select;
	char Player1[50];
	char Player2[50];

	cout << "Enter Player 1 Name: ";
	cin.getline(Player1, 20);
	cout << "Enter Player 2 Name: ";
	fflush(stdin);
	cin.getline(Player2, 20);
	inputArray(arr, 5, 5);
	welcome();
	cout << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME):";
	cin >> select;
	if (select == '1') {

	}
	else {
		exit(0);
	}
	do {
		system("cls");
		outputArray(arr, arrRow, arrCol);

		player = (player % 2) ? 1 : 2;
		
		do {
			cout << "Your Turn " << ((player % 2) ? Player1 : Player2) << "-" << (sign = (player % 2) ? 'X' : 'O')<< " " << "Turn -" << ((player % 2) ? ++countTurnP1 : ++countTurnP2) << ":  ";
			cin >> choice;
		}while (choice < 0);

//		sign = (player == 1) ? 'X' : 'O';
		if (arr[choice / 10][choice % 10] == 'X' && arr[choice / 10][choice % 10] != 'O') {	
			arr[choice / 10][choice % 10] = sign;
		}
		
		if(choice > 33){
			cout << "Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		if(choice > (arrRow * 10 + arrCol)){
			cout << "Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		check = checkwin();
        player++;
	}while(check == - 1);
	system("cls");
	outputArray(arr, arrRow, arrCol);

	if (check == 1) {
		cout << "==>\aPlayer " << ((--player % 2) ? Player1 : Player2) << " win ";
	}else if(countTurnP1 >= (arrRow * arrCol / 2 + 1)){
		cout << "==>\aGame draw";
	}
		
	cin.ignore();
	cin.get();
	system("pause");
	return 0;
	
	
}
int checkwin() {
	int row = choice / 10;
	int col = choice % 10;
	int locationStartRow = row - sumPointWin - 1;
	int locationStartCol = col - sumPointWin - 1;
	char markPoition;

	markPoition = arr[row][col];

	if (locationStartRow < 0) {
		locationStartRow = 0;
	}

	if (locationStartCol < 0) {
		locationStartRow = 0;
	}
	
	// check row
	for(int j = locationStartRow; j < sumPointWin * 2 - 2; j++) {
		if (markPoition == arr[row][j] && markPoition == arr[row][j + 1] && markPoition == arr[row][j + 2]) {
			return 1;
		}

	}
	//check colum
	for(int i = locationStartCol; i < sumPointWin * 2 - 2; i++) {
		if (markPoition == arr[i][col] && markPoition == arr[i + 1][col] && markPoition == arr[i + 2][col]) {
			return 1;
		}
	}
	//check cross up - down
	for (int j = locationStartRow; j < sumPointWin * 2 - 2; j++) {
		if (markPoition == arr[j][j] && markPoition == arr[j + 1][j + 1] && markPoition == arr[j + 2][j + 2]) {
			return 1;
		}
	}
	//check cross down - up
	int cross = row + sumPointWin - 1;
	for (int j = locationStartRow; j < sumPointWin * 2 - 2; j++) {
		if (markPoition == arr[cross - j][j] && markPoition == arr[cross - j - 1][j + 1] && markPoition == arr[cross - j - 2][j + 2]) {
			return 1;
		}
	}
	return -1;
}
void inputArray(char arr[][arrCol], int row, int colum)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < colum; ++j)
		{
			arr[i][j] = '?';

		}

	}
}
void outputArray(char arr[][arrCol], int row, int colum)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < colum; ++j)
		{
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
}
void welcome() {
	cout << "Welcome To Tic-tac-toe game! Play with your way!\n If you find any problem, please contact minhvuonga31996@mgail.com" << endl;
}
