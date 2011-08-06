
/*
 * Notes:
 *  I don't store a matrix instead calculate the matrix element dynamically.
 *  Using a matrix wastes space and also time if paging and things like that are involved.
 */
 
// The following macros return the row and column for a number
#define ROWS 1234
#define COLS 5678
// The following macro returns the matrix element given x and y
#define GET_ELEMENT(x, y) ((x) * COLS + (y))
#define GET_ROW(z) ((z) / COLS)
#define GET_COL(z) ((z) % COLS)

#include <cstdio>
#include <map>

using namespace std;
// Control flow starts here
int main()
{

	// Only 1 test case	
	int forwardRowMap[ROWS];				// Map from initial row number to final row number
	int backwardRowMap[ROWS];			    // Map from current row number to initial row number
	int forwardColMap[COLS];				// Map from initial col number to final col number
	int backwardColMap[COLS];				// Map from current col number to initial col number

	// Initialise the forward and backward maps for both rows and columns
	for ( int i = 0 ; i < ROWS ; i ++ ) {
		forwardRowMap[i] = backwardRowMap[i] = i;
 	}
 	for ( int i = 0 ; i < COLS ; i ++ ) {
 		forwardColMap[i] = backwardColMap[i] = i;
 	}

	char ch;									// The command
	int x, x_, y, y_;							// The x and y co-ordinates
	int x2, x3, y2, y3;							// temporary variables
	int z;					     				// M[x][y] for some X, Y 

	bool cont = true;
	
	while (cont) {
		ch = getchar();
		switch(ch) {
			case 'R' :
				scanf("%d %d\n", &x, &x_);
				// swap specified rows
				x --; x_ --;
				x2 = backwardRowMap[x];
				x3 = backwardRowMap[x_];
				forwardRowMap[x2] = x_;
				forwardRowMap[x3] = x;
				backwardRowMap[x] = x3;
				backwardRowMap[x_] = x2;
				break;
			case 'C' :
				scanf("%d %d\n", &y, &y_);
				// swap specified columns
				y --; y_ --;
				y2 = backwardColMap[y];
				y3 = backwardColMap[y_];
				forwardColMap[y2] = y_;
				forwardColMap[y3] = y;
				backwardColMap[y] = y3;
				backwardColMap[y_] = y2;
				break;
			case 'Q' :
				scanf("%d %d\n", &x, &y);
				// print out the element in the specified position
				x2 = backwardRowMap[x-1];
				y2 = backwardColMap[y-1];
				printf("%d\n", GET_ELEMENT(x2,y2) + 1);
				break;
			case 'W' : 
				scanf("%d\n", &z);
				// Print out the row, column corresponding to the element
				x2 = GET_ROW(z-1);
				y2 = GET_COL(z-1);
				x = forwardRowMap[x2];
				y = forwardColMap[y2];
				printf("%d %d\n", x + 1, y + 1);
				break;								// Print out the element
			default : cont = false; break;
		}
	}
	
	return 0;
}
