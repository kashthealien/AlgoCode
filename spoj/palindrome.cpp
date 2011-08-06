#include <string>
#include <list>

#include <iostream>

using namespace std;

int isPalin( unsigned int num, int base)
{
    int x;                        // A temporary variable
    list<int> que;                         // A stack for LIFO storage

    while ( num ) {
        x = num % base;
        num /= base;
        que.push_back(x);
    }
    
    while(que.size() > 1 ) {
    	int ch1, ch2;
    	ch1 = que.back();
    	ch2 = que.front();
    	if ( ch1 != ch2 )
    		return 0;
    	 
    	que.pop_front();
    	que.pop_back();		
    }

    return 1;
}

int main()
{
	int t, T;
	cin >> T;
	for ( t = 0 ; t < T ; t ++)
	{
		long long int n;
		int base;
		cin >> n;
		
		for (base = 2; ; base ++)
		{
			if(isPalin(n, base))
			{
				cout << base << endl;
				break;
			}
		}
	}
}
