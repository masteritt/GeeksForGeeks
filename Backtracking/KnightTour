#include<iostream>
using namespace std;
#define Max 8
int sol[Max][Max];
int paths[2][8] = {
	{ 2, 1, -1, -2, -2, -1, 1, 2 },
	{ 1, 2, 2, 1, -1, -2, -2, -1 } };

void printSolution(){
	for (int i = 0; i < Max; i++)
	{
		for (int j = 0; j < Max; j++)
			printf("%3d ", sol[i][j]);
		cout << endl;
	}
}
bool isSafe(int i, int j){
	if ((i >= 0) && (j >= 0) && (i < Max) && (j < Max) && (sol[i][j] == -1))
		return true;
	return false;
}
bool solveKTUtils(int x, int y, int moves){
	if (moves == (Max*Max)){
		return true;
	}
	for (int i = 0; i < 8; i++){
		int nextx = x + paths[0][i];
		int nexty = y + paths[1][i];
		if (isSafe(nextx, nexty)){
			sol[nextx][nexty] = moves;
			if (solveKTUtils(nextx, nexty, moves + 1))
				return true;
			else
				sol[nextx][nexty] = -1;
		}
	}
	return false;
}
void solveKT(){
	for (int i = 0; i < Max; i++)
		for (int j = 0; j < Max; j++)
			sol[i][j] = -1;

	sol[0][0] = 0;
	if (solveKTUtils(0,0,1)){
		printSolution();
	}
	else
		cout << "No Solution" << endl;
}

int main(){
	solveKT();
	return 0;
}
