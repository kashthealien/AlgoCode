/*******************************************************************************
 *  Author      : Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *  fileName    : <replace>.cpp
 *  description : solves the problem in ACM by the name <replace>
 *
 *  date        :
 ******************************************************************************/

#include<cstdio>
#include<string.h>

using namespace std;

int main()
{
    int N, n, i;
    int len;
    char str[102];
	int f;
    scanf("%d", &N);

    for ( n = 0 ; n < N ; n ++ )
    {
    	f = true;
        scanf("%s", str);
        len = strlen(str);
        // printf("%d %d %s", len, len/2, str);
        for ( i = 0 ; i < len/2 ; i ++ ) {
        	if (str[i] != str[len-i-1])
        		f = false;
        }
        if(f)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

