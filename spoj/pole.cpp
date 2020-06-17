/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : pole.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 * 	
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Car{
	int num;				// Car number
	long int rel;			// Relative position
	int dirty;				// Dirty bit
};
typedef struct Car car;		// car dataType

int main()
{
	while(1)
	{
		int N;					// number of cars
		int i;					// for loop counter
		car temp, ZERO={0, 0L, 0}, prev;
		int curr = 0, next = 0;	// current and next cars used while swapping
		int flag = true;
		scanf("%d", &N);		// Get the number of cars
		if(!N)					// If end of input has been reached, end
			return 0;

		// Allocation of memory for N cars
		car * cars = (car *)malloc(N*sizeof(car));

		// scan N entries
		for(i=0;i<N;i++){
			// Get the input
			scanf("%d%ld",&(cars[i].num), &(cars[i].rel));
			// If relative position is invalid then set flag to false
			if (i + cars[i].rel < 0 || i + cars[i].rel > N-1)
				flag = false;
			// Reset dirty bit of each car
			cars[i].dirty = 0;
		}

		// If input is invalid, output -1
		if ( !flag ) {
			printf("-1\n");
			continue;
		}

		for( i = 0 ; i < N ; i ++ ) {
			if ( cars[i].rel == 0)
				continue;
			if ( cars[i].rel != 0 && cars[i].dirty == 1 ) {
				flag = false;
				break;
			}
			curr = i;
			prev = ZERO;
			while (1) {
				next = curr + cars[curr].rel;
				temp = cars[curr];				// store next car in temp
				// swap current with previous car
				// relative position nullified
				// Dirty bit set				
				cars[curr] = (car){prev.num, 0L, 1};
				prev = temp;
				curr = next;
				if (temp.num == 0) {
					break;
				}				
				if ( temp.dirty == 1 ) {
					flag = false;
					break;
				}
			}
		}
		
		// If cars cannot be reordered to a valid initial, print -1
		if( !flag ) {
			printf("-1\n");
		}
		// Print valid initial order
		else {
			for ( i = 0 ; i < N ; i ++ ) {
				printf("%d ",cars[i].num);
			}
			printf("\n");					
		}
	}
}

