/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : drink.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 *
 * energy = mw cw ( tw2 - tw1 ) for energying water
 *        = mi ci ( ti2 - ti1 ) for energying ice
 *        = mi em to melt mi mass of ice
 * at equilibrium energy = 0
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define cw 4.19
#define ci 2.09
#define em 335.0

int main()
{
	while(1)
	{
		// mw and mi are the masses of water and ice initially
		// mw2 and mi2 are the masses of water and ice finally
		// tw and ti are the temperatures of water and ice initially

		float mw, mi, mi2, mw2, tw, ti;
		float energy;
		scanf("%f%f%f%f", &mw, &mi, &tw, &ti);	
		if(mw == 0.0 && mi == 0.0)
			break;
		
		// convert all water and ice to water at 0 degrees Celcius
		// We have surplus energy, calculate it
		energy = mw * tw * cw + mi * ti * ci - mi * em;
		
		if ( energy >= 0.0 )
			// heat the water using the surplus energy, no ice left
			printf("0.0 g of ice and %.1f g of water at %.1f C\n", mw + mi, energy/ cw/ (mw + mi));
			
		else if ( energy < 0.0 && energy <= -( mi + mw ) * em ) {
			// convert all water to ice
			energy += ( mi + mw ) * em;
			// cool ice further, no water left
			printf("%.1f g of ice and 0.0 g of water at %.1f C\n", mw + mi, energy/ ci/ (mw + mi));
		}
		
		else if ( energy < 0.0 && energy > -( mi + mw ) * em ) {
			mi2 = - energy/ em;
			mw2  = mi + mw - mi2;
			printf("%.1f g of ice and %0.1f g of water at 0.0 C\n", mi2, mw2);
		}
		
		else {
		printf("zoink\n");
		}
	}		
	return 0;
}

