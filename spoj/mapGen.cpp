
#include <iostream>
#include <map>

using namespace std;

string str;

int main()
{
	string k[4] = {"U", "C", "A", "G"};
	
	for( int i = 0 ; i < 16 ; i ++ )
	{
		string a;
		string b;
		string c;
		string d;
		string e;
		string f;
		string g;

		cin >> a;
		cin >> c;
		cin >> d;
		cin >> e;
		cin >> f;
		cin >> b;
		g = a + k[0] + b;
		cout << "map[\"" << g << "\"] = \"" << c <<"\";" << endl;
		g = a + k[1] + b;
		cout << "map[\"" << g << "\"] = \"" << d <<"\";" << endl;
		g = a + k[2] + b;
		cout << "map[\"" << g << "\"] = \"" << e <<"\";" << endl;
		g = a + k[3] + b;
		cout << "map[\"" << g << "\"] = \"" << f <<"\";" << endl;
	}
}
