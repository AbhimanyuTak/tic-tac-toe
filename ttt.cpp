// Author : Abhimanyu Tak
// Title : Tic Tac Toe Game 

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

const int size = 3;
int arr[9];
int board[size][size];
int flag = -1;
int moved = 0;

void printBoard(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(board[i][j] == -1)
				cout << "-" << " ";
			else if(board[i][j] == 0)
				cout << "O" << " ";
			else 
				cout << "X" << " ";
		}
		cout << endl;		
	}	
}

void printArray(){
	for(int i = 0; i < size*size; i++){
		cout << arr[i]	<< " ";	
	}
	cout << endl;	
}

void rMove(){
	for(int i = 0; i < size*size; i++){
		if(arr[i] == 0){
			board[i/size][i%size] = 0;
			arr[i] = 1;
			moved = 1;
			break;
		}
	}
}

void altMove(int a){
	board[a/size][a%size] = 0;
	arr[a] = 1;
	moved = 1;
}

void winner(){
	if(board[0][0] == board[0][1] && board[0][1] == board[0][2]){
		if(board[0][0] == 1)
			flag = 1;
		else if(board[0][0] == 0)
			flag = 0;
	}
	else if(board[1][0] == board[1][1] && board[1][1] == board[1][2]){
		if(board[1][0] == 1)
			flag = 1;
		else if(board[1][0] == 0)
			flag = 0;
	}
	else if(board[2][0] == board[2][1] && board[2][1] == board[2][2]){
		if(board[2][0] == 1)
			flag = 1;
		else if(board[2][0] == 0)
			flag = 0;
	}
	else if(board[0][0] == board[1][0] && board[1][0] == board[2][0]){
		if(board[0][0] == 1)
			flag = 1;
		else if(board[0][0] == 0)
			flag = 0;
	}
	else if(board[0][1] == board[1][1] && board[1][1] == board[2][1]){
		if(board[0][1] == 1)
			flag = 1;
		else if(board[0][1] == 0)
			flag = 0;
	}
	else if(board[0][2] == board[1][2] && board[1][2] == board[2][2]){
		if(board[0][2] == 1)
			flag = 1;
		else if(board[0][2] == 0)
			flag = 0;
	}
	else if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		if(board[0][0] == 1)
			flag = 1;
		else if(board[0][0] == 0)
			flag = 0;
	}
	else if(board[2][0] == board[1][1] && board[1][1] == board[0][2]){
		if(board[2][0] == 1)
			flag = 1;
		else if(board[2][0] == 0)
			flag = 0;
	}

	if(flag == 1)
		cout << "You Win" << endl;
	else if(flag == 0)
		cout << "You Lose" << endl;
}

int compVsPlayer(int x, int y){
	int random;
	srand (time(NULL));	
	static int start = 0;
	moved = 0;
	start++;
	if(x > 2 || y > 2 || board[x][y] != -1){
		cout << "Invalid Move" << endl;
		return 0;
	}
	else{
		board[x][y] = 1;
		arr[x*size+y]= 1;
	}

	winner();
	if(flag==1){
		cout << "------------" << endl;
		printBoard();
		cout << "------------" << endl;
		return 1;
	}

	if(start == 1){
		// Case 1
		// - - -
		// - X -
		// - - -
		if(x==1 && y==1){
			random = rand() % 8 + 1;
			switch(random){
				case 1:
					board[0][0] = 0;
					arr[0] = 1;
					break;
				case 2:
					board[0][1] = 0;
					arr[1] = 1;
					break;
				case 3:
					board[0][2] = 0;
					arr[2] = 1;
					break;
				case 4:
					board[1][0] = 0;
					arr[3] = 1;
					break;
				case 5:
					board[1][2] = 0;
					arr[5] = 1;
					break;
				case 6:
					board[2][0] = 0;
					arr[6] = 1;
					break;
				case 7:
					board[2][1] = 0;
					arr[7] = 1;
					break;
				case 8:
					board[2][2] = 0;
					arr[8] = 1;
					break;
			}
			
		}
		// Case 2
		// X - -
		// - - -
		// X - -
		else if(y==0 && (x==0 || x==2)){
			random = rand() % 6 + 1;
			if(x==0){
				switch(random){
					case 1:
						board[0][1] = 0;
						arr[1] = 1;
						break;
					case 2:
						board[0][2] = 0;
						arr[2] = 1;
						break;
					case 3:
						board[1][0] = 0;
						arr[3] = 1;
						break;
					case 4:
						board[2][0] = 0;
						arr[6] = 1;
						break;
					case 5:
						board[1][1] = 0;
						arr[4] = 1;
						break;
					case 6:
						board[2][2] = 0;
						arr[8] = 1;
						break;
				}
			}
			else if(x==2){
				switch(random){
					case 1:
						board[0][0] = 0;
						arr[0] = 1;
						break;
					case 2:
						board[1][0] = 0;
						arr[1] = 1;
						break;
					case 3:
						board[2][1] = 0;
						arr[7] = 1;
						break;
					case 4:
						board[2][2] = 0;
						arr[8] = 1;
						break;
					case 5:
						board[1][1] = 0;
						arr[4] = 1;
						break;
					case 6:
						board[0][2] = 0;
						arr[2] = 1;
						break;
				}
			}
		}
		// Case 3
		// - - X
		// - - -
		// - - X
		else if(y==2 && (x==0 || x==2)){
			random = rand() % 6 + 1;
			if(x==0){
				switch(random){
					case 1:
						board[0][0] = 0;
						arr[0] = 1;
						break;
					case 2:
						board[0][1] = 0;
						arr[1] = 1;
						break;
					case 3:
						board[1][2] = 0;
						arr[5] = 1;
						break;
					case 4:
						board[2][2] = 0;
						arr[8] = 1;
						break;
					case 5:
						board[1][1] = 0;
						arr[4] = 1;
						break;
					case 6:
						board[2][0] = 0;
						arr[6] = 1;
						break;
				}
			}
			else if(x==2){
				switch(random){
					case 1:
						board[2][0] = 0;
						arr[6] = 1;
						break;
					case 2:
						board[2][1] = 0;
						arr[8] = 1;
						break;
					case 3:
						board[0][2] = 0;
						arr[2] = 1;
						break;
					case 4:
						board[1][2] = 0;
						arr[5] = 1;
						break;
					case 5:
						board[1][1] = 0;
						arr[4] = 1;
						break;
					case 6:
						board[0][0] = 0;
						arr[0] = 1;
						break;
				}
			}
		}
		// Case 4
		// - X -
		// - - -
		// - X -
		else if(y==1 && (x==0 || x==2)){
			random = rand() % 4 + 1;
			if(x==0){
				switch(random){
					case 1:
						board[0][0] = 0;
						arr[0] = 1;
						break;
					case 2:
						board[0][2] = 0;
						arr[2] = 1;
						break;
					case 3:
						board[1][1] = 0;
						arr[4] = 1;
						break;
					case 4:
						board[2][1] = 0;
						arr[7] = 1;
						break;
				}
			}
			else if(x==2){
				switch(random){
					case 1:
						board[2][0] = 0;
						arr[6] = 1;
						break;
					case 2:
						board[2][2] = 0;
						arr[8] = 1;
						break;
					case 3:
						board[0][1] = 0;
						arr[1] = 1;
						break;
					case 4:
						board[1][1] = 0;
						arr[4] = 1;
						break;
				}
			}
		}
		// Case 5
		// - - -
		// X - X
		// - - -
		else if(x==1 && (y==0 || y==2)){
			random = rand() % 4 + 1;
			if(y==0){
				switch(random){
					case 1:
						board[0][0] = 0;
						arr[0] = 1;
						break;
					case 2:
						board[2][0] = 0;
						arr[6] = 1;
						break;
					case 3:
						board[1][1] = 0;
						arr[4] = 1;
						break;
					case 4:
						board[1][2] = 0;
						arr[5] = 1;
						break;
				}
			}
			else if(y==2){
				switch(random){
					case 1:
						board[0][2] = 0;
						arr[2] = 1;
						break;
					case 2:
						board[2][2] = 0;
						arr[8] = 1;
						break;
					case 3:
						board[1][0] = 0;
						arr[3] = 1;
						break;
					case 4:
						board[1][1] = 0;
						arr[4] = 1;
						break;
				}
			}
		}
		moved = 1;
	}

	if(start >= 2){
		if(board[0][0] == 0){
			if(board[1][0] == 0){
				if(board[2][0] == -1)
					board[2][0] = 0;
			}
			else if(board[1][1] == 0){
				if(board[2][2] == -1)
					board[2][2] = 0;
			}
			else if(board[0][1] == 0){
				if(board[0][2] == -1)
					board[0][2] = 0;
			}
			else if(board[2][0] == 0){
				if(board[1][0] == -1)
					board[1][0] = 0;
			}
			else if(board[2][2] == 0){
				if(board[1][1] == -1)
					board[1][1] = 0;
			}
			else if(board[0][2] == 0){
				if(board[0][1] == -1)
					board[0][1] = 0;
			}
		}
		else if(board[0][1] == 0){
			if(board[0][2] == 0){
				if(board[0][0] == -1)
					board[0][0] = 0;
			}
			else if(board[1][1] == 0){
				if(board[2][1] == -1)
					board[2][1] = 0;
			}
			else if(board[2][1] == 0){
				if(board[1][1] == -1)
					board[1][1] = 0;
			}
		}
		else if(board[0][2] == 0){
			if(board[1][1] == 0){
				if(board[2][0] == -1)
					board[2][0] = 0;
			}
			else if(board[2][0] == 0){
				if(board[1][1] == -1)
					board[1][1] = 0;
			}
			else if(board[1][2] == 0){
				if(board[2][2] == -1)
					board[2][2] = 0;
			}
			else if(board[2][2] == 0){
				if(board[1][2] == -1)
					board[1][2] = 0;
			}
		}
		else if(board[1][0] == 0){
			if(board[2][0] == 0){
				if(board[0][0] == -1)
					board[0][0] = 0;
			}
			else if(board[1][1] == 0){
				if(board[1][2] == -1)
					board[1][2] = 0;
			}
			else if(board[1][2] == 0){
				if(board[1][1] == -1)
					board[1][1] = 0;
			}
		}
		else if(board[1][2] == 0){
			if(board[2][2] == 0){
				if(board[0][2] == -1)
					board[0][2] = 0;
			}
			else if(board[1][1] == 0){
				if(board[1][0] == -1)
					board[1][0] = 0;
			}
		}
		else if(board[2][0] == 0){
			if(board[1][1] == 0){
				if(board[0][2] == -1)
					board[0][2] = 0;
			}
			else if(board[2][1] == 0){
				if(board[2][2] == -1)
					board[2][2] = 0;
			}
			else if(board[2][2] == 0){
				if(board[2][1] == -1)
					board[2][1] = 0;
			}
		}
		else if(board[2][1] == 0){
			if(board[2][2] == 0){
				if(board[2][0] == -1)
					board[2][0] = 0;
			}
			else if(board[1][1] == 0){
				if(board[0][1] == -1)
					board[0][1] = 0;
			}
			else if(board[0][1] == 0){
				if(board[1][1] == -1)
					board[1][1] = 0;
			}
		}
		else if(board[2][2] == 0){
			if(board[1][1] == 0){
				if(board[1][1] == -1)
					board[1][1] = 0;
			}
		}
		
		if(board[0][0] == 1 && !moved){
			if(board[1][0] == 1 && board[2][0] == -1){
				altMove(6);
			}
			else if(board[1][1] == 1 && board[2][2] == -1){
				altMove(8);
			}
			else if(board[0][1] == 1 && board[0][2] == -1){
				altMove(2);
			}
			else if(board[2][0] == 1 && board[1][0] == -1){
				altMove(3);
			}
			else if(board[2][2] == 1 && board[1][1] == -1){
				altMove(4);
			}
			else if(board[0][2] == 1 && board[0][1] == -1){
				altMove(1);
			}
		}
		
		if(board[0][1] == 1 && !moved){
			if(board[0][2] == 1 && board[0][0] == -1){
				altMove(0);
			}
			else if(board[1][1] == 1 && board[2][1] == -1){
				altMove(7);
			}
			else if(board[2][1] == 1 && board[1][1] == -1){
				altMove(4);
			}
		}
		if(board[0][2] == 1 && !moved){
			if(board[1][1] == 1 && board[2][0] == -1){
				altMove(6);
			}
			else if(board[2][0] == 1 && board[1][1] == -1){
				altMove(4);
			}
			else if(board[1][2] == 1 && board[2][2] == -1){
				altMove(8);
			}
			else if(board[2][2] == 1 && board[1][2] == -1){
				altMove(5);
			}
		}
		if(board[1][0] == 1 && !moved){
			if(board[2][0] == 1 && board[0][0] == -1){
				altMove(0);
			}
			else if(board[1][1] == 1 && board[1][2] == -1){
				altMove(5);
			}
			else if(board[1][2] == 1 && board[1][1] == -1){
				altMove(4);
			}
		}
		if(board[1][2] == 1 && !moved){
			if(board[2][2] == 1 && board[0][1] == -1){
				altMove(2);
			}
			else if(board[1][1] == 1 && board[1][0] == -1){
				altMove(3);
			}
		}
		if(board[2][0] == 1 && !moved){
			if(board[1][1] == 1 && board[0][2] == -1){
				altMove(2);
			}
			else if(board[2][1] == 1 && board[2][2] == -1){
				altMove(8);
			}
			else if(board[2][2] == 1 && board[2][1] == -1){
				altMove(7);
			}
		}
		if(board[2][1] == 1 && !moved){
			if(board[2][2] == 1 && board[2][0] == -1){
				altMove(6);
			}
			else if(board[1][1] == 1 && board[0][1] == -1){
				altMove(1);
			}
			else if(board[0][1] == 1 && board[1][1] == -1){
				altMove(4);
			}
		}
		if(board[2][2] == 1 && !moved){
			if(board[1][1] == 1 && board[0][0] == -1){
				altMove(0);
			}
			else if(board[2][1] == 1 && board[2][0] == -1){
				altMove(0);
			}
			else if(board[1][2] == 1 && board[0][2] == -1){
				altMove(0);
			}
		}
		if(!moved)
			rMove();
	}

	winner();
	if(flag==0){
		cout << "------------" << endl;
		printBoard();
		cout << "------------" << endl;
		return 1;
	}

	cout << "Start :" << start << endl;
	return 0;
}

int main()
{	
	cout << "============== Tic Tac Toe ==============" << endl;
	
	cout << "=================Rules===================" << endl;
	cout << "1) For every move, you have to insert" << endl; 
	cout << "   coordinates as spaced integers ie \"1 2\"" << endl;
	cout << "2) Coordinates start from \"0 0\" and ends" << endl;
	cout << "   at \"2 2\"" << endl;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			board[i][j] = -1;
			arr[i*size+j] = 0;
		}
	}
	
	int k = 1;
	int x = -1, y = -1;
	while(k <= size*size){
		cout << "Your turn" << endl;
		cin >> x >> y;
		if(compVsPlayer(x,y)){
			break;
		}
		k = k + 2;
		cout << "------------" << endl;
		printBoard();
		cout << "------------" << endl;
		//printArray();
	}

	if(flag == -1){
		cout << "Draw" << endl;
	}
	
	return 0;
}
