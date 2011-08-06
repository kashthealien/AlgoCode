/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * Use if / while anf 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	if( int T = 1  ) 
	{
		if( int t = 0 || scanf("%d",&T)) {
			if (int a = 1 == 1) {
				if (int b = 1 == 1) {
					if (char ch = 1 == 1) {
						while( t ++ <= T) {
							if( ( scanf("%d", &a) == 1) && ((ch = getchar()) !='\n') && (scanf("%d", &b) == 1)) {
								if ( ch == '+' ) {
									if(printf("%d\n", a+b)){}
								}
								else if ( ch == '-') {
									if(printf("%d\n", a-b)){}
								}
								else if ( ch == '*') {
									if(printf("%d\n", a*b)){}
								}
								else if ( ch == '/') {
									if(printf("%d\n", a/b)){}
								}
							}
						}
					}
				}
			}
		}
	}
}

