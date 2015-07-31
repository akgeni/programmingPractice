#include <iostream>
#include <vector>
const int size = 4;
const int N = 4;

using namespace std;

void printSolution(int board[][size]) {
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueenUtil(int board[][size], int col) {
	if(col >= size) {
		return true;
	}

	for(int row=0; row < size; row++) {
		if(isSafe(board, row, col)) {
			board[row][col] = 1;
			if(solveNQueenUtil(board, col+1)) {
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}

void solveNQueen() {
	int board[size][size];
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			board[i][j] = 0;
		}
	}

	if(solveNQueenUtil(board, 0)) {
		printSolution(board);

	} else {
		cout << "No Place to hide all queen \n";
	}
}

int main() {
	solveNQueen();

return 0;
}
