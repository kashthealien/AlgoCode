#include<cstdio>
#include<list>

using namespace std;

int main()
{
	int myint = 41;
	list < int > mylist;
	list < int >::iterator i;
	
	while(myint != 42)
	{
		scanf("%d",&myint);
		mylist.push_back(myint);
	}
	mylist.pop_back();
	for( i = mylist.begin() ; i != mylist.end() ; i ++ )
	{
		printf("%d\n",(*i));
	}

	return 0;
}
