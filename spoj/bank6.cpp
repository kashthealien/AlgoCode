/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : bank_sorting.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>

using namespace std;
char mat[100000][27];
char mat2[100000][27];
long int count;
int diff;

long int q = 0, Q = 0;			// querry counter, number of querries

void copy (long int i, long int j)
{
    for ( int k = 0 ; k < 26 ; k ++ )
    {
        mat2[j][k] = mat[i][k];
    }
}

void copyMat ()
{
    long int i;
    int j;
    for ( i = 0 ; i < Q ; i ++ ) {
        for ( j = 0 ; j < 26 ; j ++ ) {
            mat[i][j] = mat2[i][j];
        }
    }
}

void print ()
{
    long int i;
    int j;
    for(i = 0 ; i < Q ; i ++ ) {
        for ( j = 0 ; j < 26 ; j ++ ) {
            putchar(mat2[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
int main()
{
	long int t, T;
	long int i, j;
	int k;
    int flag [26] = {false};
    char ch;
    queue<long int> que[10];
	scanf("%ld",&T);
	getchar();
	for( t = 0 ; t < T ; t ++ )
	{

		// Get input ( number of queries
		scanf("%ld", &Q);
		getchar();
		// scan all querries
		for( i = 0 ; i < Q ; i ++ ) {
		    mat[i][0] = getchar();
		    mat[i][1] = getchar();
		    getchar();
		    mat[i][2] = getchar();
		    mat[i][3] = getchar();
		    mat[i][4] = getchar();
		    mat[i][5] = getchar();
		    mat[i][6] = getchar();
		    mat[i][7] = getchar();
		    mat[i][8] = getchar();
		    mat[i][9] = getchar();
		    getchar();
		    mat[i][10] = getchar();
		    mat[i][11] = getchar();
		    mat[i][12] = getchar();
		    mat[i][13] = getchar();
		    getchar();
		    mat[i][14] = getchar();
		    mat[i][15] = getchar();
		    mat[i][16] = getchar();
		    mat[i][17] = getchar();
		    getchar();
		    mat[i][18] = getchar();
		    mat[i][19] = getchar();
		    mat[i][20] = getchar();
		    mat[i][21] = getchar();
		    getchar();
		    mat[i][22] = getchar();
		    mat[i][23] = getchar();
		    mat[i][24] = getchar();
		    mat[i][25] = getchar();
		    mat[i][26] = '\0';
		    getchar();
		    getchar();	    		    		    
		}

        for ( j = 0 ; j < 26 ; j ++ ) {
            ch = mat[0][j];
            flag [j] = false;
            for ( i = 1 ; i < Q ; i ++ ) {
                if ( ch != mat[i][j] ) {
                    flag[j] = 1;
                    break;
                }
            }
        }
		for ( i = 25 ; i >= 0 ; i -- ) {
		    if ( ! flag [i] )
		        continue;
		    for ( j = 0 ; j < Q ; j ++ ) {
		        if(!( mat[j][i] - '0' >= 0 && mat[j][i] -'0' < 10 ))
		            printf("err %c  ", mat[j][i]);
    		    que[ mat[j][i] - '0' ] .push (j);
		    }
		    for ( j = 0 , k = 0 ; j < Q ; j ++ ) {
		        while( que[k].empty() ) k++;
		        copy( que[k].front(), j);
		        que[k].pop();
		    }
		    copyMat();
		}
		
		for( i = 0 ; i < Q ;i ++ ) {
			count = 0;
			diff = 0;
			while ( ! diff ) {
				for ( j = 0 ; j < 26 && i < Q - 1 ; j ++ ) {
					if ( mat[i][0] != mat[i+1][j] ) {
						diff = 1;
						break;
					}
				}
				if ( ! diff )
					i ++;
				count ++;
			}
            putchar( mat[i][0]);
            putchar( mat[i][1]);
            putchar(' ');
            putchar( mat[i][2]);
            putchar( mat[i][3]);
            putchar( mat[i][4]);
            putchar( mat[i][5]);
            putchar( mat[i][6]);
            putchar( mat[i][7]);
            putchar( mat[i][8]);
            putchar( mat[i][9]);
            putchar(' ');
            putchar( mat[i][10]);
            putchar( mat[i][11]);
            putchar( mat[i][12]);
            putchar( mat[i][13]);
            putchar(' ');
            putchar( mat[i][14]);
            putchar( mat[i][15]);
            putchar( mat[i][16]);
            putchar( mat[i][17]);
            putchar(' ');
            putchar( mat[i][18]);
            putchar( mat[i][19]);
            putchar( mat[i][20]);
            putchar( mat[i][21]);
            putchar(' ');
            putchar( mat[i][22]);
            putchar( mat[i][23]);
            putchar( mat[i][24]);
            putchar( mat[i][25]);
            putchar(' ');
            printf("%d", count);
            putchar('\n');
		}
        putchar('\n');		
	}		
	return 0;
}

