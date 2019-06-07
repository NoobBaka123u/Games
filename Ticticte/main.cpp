#include <iostream>
#define MAX 10
using namespace std;
const int arrRow = 9;
const int arrCol = 9;

void inputArray(char arr[][arrCol], int row, int colum);
void outputArray(char arr[][arrCol], int row, int colum);
int checkwin();
void welcome();

int sumPointWin = 3;
int choice;
char arr[arrRow][arrCol];



int main() {

	
	int player = 1;
	int count = 0;
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
	inputArray(arr, arrRow, arrCol);
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
		
	
		cout << "Your Turn " << ((player % 2) ? Player1 : Player2) << "-" << (sign = (player % 2) ? 'X' : 'O')<< " " << "Turn -" << ((player % 2) ? ++countTurnP1 : ++countTurnP2) << ":  ";

		cin >> choice;
		if (arr[choice / 10][choice % 10] == 'X' || arr[choice / 10][choice % 10] == 'O') {
			cout << "This space not empty! Please choose other space!";
			player--;
			cin.ignore();
			cin.get();
		}
		if (choice < 0 || choice >(arrRow * 10 + arrCol)) {
			cout << "This space not exist! Please choose other space!";
			player--;
			cin.ignore();
			cin.get();
		}
//		if (arr[choice / 10][choice % 10] != 'X' && arr[choice / 10][choice % 10] != 'O' && choice < 0 && choice >(arrRow * 10 + arrCol)) {

			sign = (player == 1) ? 'X' : 'O';
			arr[choice / 10][choice % 10] = sign;



				/*		if(choice > (arrRow * 10 + arrCol)){
							cout << "Invalid move ";

							player--;
							cin.ignore();
							cin.get();
						}
				*/
			check = checkwin();
			++count;
			player++;
			
//		}
		
	}while((check == - 1) && (count < (arrRow * arrCol)));
	system("cls");
	outputArray(arr, arrRow, arrCol);

	if (check == 1) {
		cout << "==>\aPlayer " << ((--player % 2) ? Player1 : Player2) << " win ";
	}
	if (count == (arrRow * arrCol)) {
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
	int pointStart = row - sumPointWin - 1;
	int pointEnd = row + sumPointWin - 1;
	char markPoition;

	markPoition = arr[row][col];

	if (pointStart < 0) {
		pointStart = 0;
	}

	if (pointStart < 0) {
		pointStart = 0;
	}
	
	// check row
	for(int j = pointStart; j < pointEnd; j++) {
		if (markPoition == arr[row][j] && markPoition == arr[row][j + 1] && markPoition == arr[row][j + 2]) {
			return 1;
		}

	}
	//check colum
	for(int i = pointStart; i < pointEnd; i++) {
		if (markPoition == arr[i][col] && markPoition == arr[i + 1][col] && markPoition == arr[i + 2][col]) {
			return 1;
		}
	}
	//check cross up - down
	for (int j = pointStart; j < pointEnd; j++) {
		if (markPoition == arr[j][j] && markPoition == arr[j + 1][j + 1] && markPoition == arr[j + 2][j + 2]) {
			return 1;
		}
	}
	//check cross down - up
	int cross = row + sumPointWin - 1;
	for (int j = pointStart; j < pointEnd; j++) {
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
