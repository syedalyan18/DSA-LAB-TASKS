#include <iostream>
using namespace std;
const int N = 8;
bool issafe(int board[][N],int r,int c){
	//col check
	for(int i=0;i<r;i++){
		if(board[i][c] == 1){
			return false;
		}
	}
	//digonal check upper left
	for(int i=r-1,j=c-1;j>=0 && i>=0;j--,i--){
		if(board[i][j] == 1){
			return false;
		}
	}
	//upper right
	for(int i=r-1,j=c+1;j<N && i>=0;i--,j++){
		if(board[i][j] == 1){
			return false;
		}
	}
	return true;
}
void solveNqueen(int board[][N],int r,int &nosol){
	if(r == N ){
		(nosol)++;
		return;
	}
	for(int i=0;i<N;i++){
		if(issafe(board,r,i)){
			board[r][i] = 1;
			solveNqueen(board,r+1,nosol);
			board[r][i] = 0;
		}
	}
	return;
}
int main(){
	int board[N][N] = {0};
    int no = 0;
	solveNqueen(board,0,no);
    cout << "No of solution for N=" << N << " :" << no << endl;
	return 0;
}