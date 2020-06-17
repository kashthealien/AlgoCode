/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char molecule[101];
int ind;
int len;
// Recursive function
int	recCalcMass()
{
	int prevMass = 0;
	int subMass = 0;
	int multiply;
	while (molecule[ind] != '\0')
	{
		switch(molecule[ind]) {
			case 'C':
				if (prevMass > 0)
					subMass += prevMass;
				prevMass = 12;
				ind ++;				
				break;
			case 'H':
				if (prevMass > 0)
					subMass += prevMass;
				prevMass = 1;
				ind ++;				
				break;			
			case 'O':
				if (prevMass > 0)
					subMass += prevMass;			
				prevMass = 16;
				ind ++;				
				break;			
			case '(':
				ind ++;
				if (prevMass > 0)
					subMass += prevMass;
				prevMass = recCalcMass();
				if ( isdigit(molecule[ind])) {
					multiply = 0;
					while(isdigit(molecule[ind])) {
						multiply *= 10;
						multiply += molecule[ind] - '0';
						ind ++;					
					}
					if (! multiply == 0)
						 prevMass *= multiply;
				}			
				break;
			case ')':
				ind ++;
				subMass += prevMass;
				return (subMass);
			default :
				if ( isdigit(molecule[ind])) {
					multiply = 0;
					while(isdigit(molecule[ind])) {
						multiply *= 10;
						multiply += molecule[ind] - '0';
						ind ++;					
					}
					if (! multiply == 0)
						 prevMass *= multiply;
				}
		}
	}
	subMass += prevMass;
	return (subMass);
}

int main()
{
	scanf("%s", &molecule);
	len = strlen(molecule);
	int mass = recCalcMass();
	printf("%d", mass);
}

