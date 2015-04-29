#include <iostream>
#include <unistd.h>
using namespace std;
int cell[40][40];					//0 = empty, 1 = head, 2 = tail, 3 = conductor
int compcell[40][40];					//Same rules

void reDraw(){
	cout << endl << endl << endl << endl;
	cout << endl << endl << endl << endl;
	cout << endl << endl << endl << endl;
	for (int j = 0; j <= 39; ++j){
		cout << "    ";
		for (int i = 0; i <= 39; ++i){
			if (cell[i][j] == 0){
				cout << '.';
			} else if (cell[i][j] == 1) {
				cout << 'H';
			} else if (cell[i][j] == 2) {
				cout << 'T';
			} else if (cell[i][j] == 3) {
				cout << 'C';
			}
			cout << ' ';
		}
		cout << endl;
	}
	cout << endl << endl << endl << endl;
	cout << endl << endl << endl << endl;
	cout << endl << endl << endl << endl;
}

int numNeighbors(int x, int y){
	cout << x << ',' << y << ' ';
	int totalN = 0;
	if (cell[x+1][y] == 1) { totalN = totalN + 1;}
	else if (cell[x-1][y] == 1) {totalN = totalN + 1;}
	else if (cell[x][y+1] == 1) {totalN = totalN + 1;}
	else if (cell[x][y-1] == 1) {totalN = totalN + 1;}
	else if (cell[x-1][y-1] == 1) {totalN = totalN + 1;}
	else if (cell[x-1][y+1] == 1) {totalN = totalN + 1;}
	else if (cell[x+1][y-1] == 1) {totalN = totalN + 1;}
	else if (cell[x+1][y+1] == 1) {totalN = totalN + 1;}
	cout << totalN << ' ';
	return totalN;
}

void duplicateChart(){
	for (int j = 0; j <= 39; ++j){
    	for (int i = 0; i <= 39; ++i){
			compcell[i][j] = cell[i][j];
		}
	}
}

void applyChanges(){
	for (int j = 0; j <= 39; ++j){
    	for (int i = 0; i <= 39; ++i){
			cell[i][j] = compcell[i][j];
		}
	}
}

void updateTick(){
	duplicateChart();
	for (int j = 0; j <= 39; ++j){
		for (int i = 0; i <= 39; ++i){
        	// if cell [i][j] == 0, do nothing
			if (cell[i][j] == 1) {
            	compcell[i][j] = 2;
			} else if (cell[i][j] == 2) {
				compcell[i][j] = 3;
			} else if (cell[i][j] == 3){
				int n = numNeighbors(i,j);
				cout << "Found " << n << " "; 
				if (n == 1 || n == 2){
					compcell[i][j] = 1;
		   		}
			}
		}
	}
	applyChanges();
	reDraw();
}

int main(){
	for (int j = 0; j <= 39; ++j){
		for (int i = 0; i <= 39; ++i){
			cell[i][j] = 0; 			//Initializes all cells to empty
			compcell[i][j] = 0;			//Same as Above
		}
	}

    //wire
		cell[10][10] = 1;
		cell[10][11] = 3;
		cell[10][12] = 3;
 		cell[10][13] = 3;
		cell[10][14] = 3;
		cell[10][15] = 3;
 		cell[10][16] = 3;
		cell[10][17] = 3;
		cell[10][18] = 3;
		cell[10][19] = 3;
		cell[10][20] = 3;
    	//bend
		cell[10][20] = 3;
		cell[11][20] = 3;
		cell[12][20] = 3;
		cell[13][20] = 3;
		cell[14][20] = 1;

    reDraw();
	while (true){
		usleep(100000);
		updateTick();
	}
	
	//reDraw();
	return 0;
}
