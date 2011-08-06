#include<iostream>
#include<vector>
using namespace std;

vector<int>bitString;

void decToBin(long long e)
{
	bitString.clear();
	bitString.push_back(0);
	while(e>0)
	{
		bitString.push_back(e%2);
		e/=2;
	}
}
int scanLR()
{
	int ctr = 0;
	int oneCtr = 0;
	for(int i = 0;i < bitString.size();i++)
	{
		if(bitString[i] == 1)
		{
			if(bitString[i] == 1)
				oneCtr++;
			if( i > 0 && bitString[i-1] != 1)
				ctr++;
		}
	}
	if(ctr == 1 && oneCtr != 1)
		return 2;
	else
		return ctr;
}
int main()
{
	long long t;
	cin>>t;
	for(int i = 0;i<t;i++)
	{
		long long a,e;
		cin >> a >> e;
		decToBin(e);
		int ans = scanLR();
		cout<<ans<<endl;
	}
}
		
