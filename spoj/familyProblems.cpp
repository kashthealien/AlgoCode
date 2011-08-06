/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>

using namespace std;
int main()
{
	int N;
	int i;
	int sum;
	while( cin >> N) {
		for( i = 1, sum = 0 ; sum < N ; i ++ ) {
			sum += i;
		}
		cout << "TERM " << N <<" IS " << char(65 + ((i-2)%26)) << endl;
	}
	return 0;										// Successful termination
}

