/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int will;
	while(cin >> will)								// Get test cases till as long as there are more
	{
		int copy = will;
		int radius = 1;
		int diff = 6;
		
		/// Origin (trivial case)
		if (will == 1) {
			cout << "0 0\n";
			continue;
		}
		
		/// Non-trivial cases
		/*
		 * The honey comb consists of blocks lying on concentric hexagons + a centre
		 * The block (a small hexagon) we are searching for lies on a hexagon of some radius.
		 * We should find the radius of the hexagon, the side of the hexagon and the location on
		 * that side. By finding them, we can get the co-ordinates of the block.
		 */
		will --;
		while( will > diff) {							// 1.> Get the radius of the hexagon
			will -= diff;
			diff += 6;
			radius ++;				
		}
		will --;
		will = (will+1) % diff;
		int partSize = diff / 6;						// The length of the hexagon
		int partNum = will / partSize;					// 2.> The side of the hexagon ( 6 sides )
		int location = will % partSize;						// 3.> Location on a particular side
		int x, y;										// The co-ordinates (answer)
		// cout << copy << " " << radius << " " << partSize << " " << partNum << " "<< will <<" " << location << " " << diff <<endl;
		switch(partNum) {								// Get the co-ordinates depeding on partNum
			case 0: x = radius - location; y = location; break;
			case 1: x = - location; y = radius; break;
			case 2: x = -radius; y = radius - location; break;
			case 3: y = -location; x = location - radius; break;
			case 4: x = location; y = - radius; break;
			case 5: x = radius; y = location - radius; break;
		}
		
		cout << x << " " << y << endl;					// Output the result
	}
	return 0;											// Successful termination
}

