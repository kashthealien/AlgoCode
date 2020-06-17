/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>

char input[201];

int LIST(index)
{
	int adv = ELEMENT()
	if (adv == -1)
		return -1;
	index += adv;
	if (input[index] == ',')
	{
		index ++;
	}
	else
	{
		return adv;
	}
}

int ELEMENT_LIST(index)
{
	int adv = LIST(index);
	if(adv == -1)
		return 0;
	
	else return adv;
}

int SET(index)
{
	int init = index;

	if(input[index] == '{')
		index ++;
	else
		return -1;

	int adv = ELEMENT_LIST(index);

	if(adv == -1)
		return -1;
	index += adv;
	if(input[index] == '}')
		return (index - init);
	else
		return -1;
}

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);								// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		gets(input);
		index = 0;
		
		if(SET(index))
			printf("Word #%d: Set", t+1);
		else
			printf("Word #%d: No Set", t+1);
		
	}
	
	return 0;										// Successful termination
}

