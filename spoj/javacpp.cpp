/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum lang {
	NONE = 0,
	JAVA = 1,
	CPP = 2,
	ERROR = 3
};

int main()
{
	int upper = 0;
	int under = 0;
	int mode = NONE;
	int len;

	do 
	{
		char ch;
		char word[150]={0};
		scanf("%s", word);
		len = strlen(word);
		if (len == 0)
			continue;
		mode = NONE;

		for ( int i = 0 ; i < len ; i ++ ) {
			if ( word[i] == '_') {
				if ( i == 0 || i == len-1 || !(isalpha(word[i+1] ))){
					mode = ERROR;
					continue;
				}
				if ( mode == JAVA )
					mode = ERROR;
				else if ( mode == NONE )
					mode = CPP;
			}
			
			else if (isupper(word[i])) {
				if ( i == 0 ) {
					mode = ERROR;
					continue;
				}
				if ( mode == CPP ) {
					mode = ERROR;
				}
				else if ( mode == NONE )					
					mode = JAVA;
			}
		}
		if ( mode == ERROR ) {
			printf("Error!\n");
		}
		else if ( mode == JAVA ) {
			for ( int i = 0 ; i < len ; i ++ ) {
				if (isupper(word[i]) && i > 0) {
					putchar('_');
					putchar(word[i] + 32);					
				}
				else
					putchar(word[i]);
			}
			putchar('\n');
		}
		else {
			for ( int i = 0 ; i < len ; i ++ ) {
				if(word[i]=='_' && i < len - 1 ) {
					i++;
					putchar(word[i] - 32);
				}
				else
					putchar(word[i]);					
			}
			putchar('\n');			
		}
	}while( !feof(stdin) );
	return 0;
}

