#include<iostream>
using namespace std;
#define Max 15
int N,M;
int grid[Max][Max]; 
int color[Max];

void printSolution(){
	for (int i = 0; i < N; i++)
		cout << i << " " << color[i] << endl;
}
bool isSafe(int x, int _color){
	for (int i = 0; i < N;i++)
		if (grid[x][i] && color[i] == _color)
			return false;
	return true;
}
bool solveMColoringUtils(int v){
	if (v == N)
		return true;
	for (int m = 1; m <= M; m++)
	{ 
		if (isSafe(v, m)){
			color[v]= m;
			if (solveMColoringUtils(v+1)){
				return true;
			}
			color[v] = 0;
		}
	}
	return false;
}
void solveMColoring(){
	for (int i = 0; i < N; i++)
		color[i] = 0;

	if (solveMColoringUtils(0)){
		printSolution();
	}
	else
		cout << "No Solution" << endl;
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];
	cin >> M;
	solveMColoring();
	return 0;
}
