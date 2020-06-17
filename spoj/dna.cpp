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
#include <map>
#include <string>

using namespace std;
string trans;
map<string, string> codonMap;

void init__()
{
	codonMap["5"] = 6;
	codonMap["UUU"] = "Phe";
	codonMap["UCU"] = "Ser";
	codonMap["UAU"] = "Tyr";
	codonMap["UGU"] = "Cys";
	codonMap["UUC"] = "Phe";
	codonMap["UCC"] = "Ser";
	codonMap["UAC"] = "Tyr";
	codonMap["UGC"] = "Cys";
	codonMap["UUA"] = "Leu";
	codonMap["UCA"] = "Ser";
	codonMap["UAA"] = "---";
	codonMap["UGA"] = "---";
	codonMap["UUG"] = "Leu";
	codonMap["UCG"] = "Ser";
	codonMap["UAG"] = "---";
	codonMap["UGG"] = "Trp";
	codonMap["CUU"] = "Leu";
	codonMap["CCU"] = "Pro";
	codonMap["CAU"] = "His";
	codonMap["CGU"] = "Arg";
	codonMap["CUC"] = "Leu";
	codonMap["CCC"] = "Pro";
	codonMap["CAC"] = "His";
	codonMap["CGC"] = "Arg";
	codonMap["CUA"] = "Leu";
	codonMap["CCA"] = "Pro";
	codonMap["CAA"] = "Gln";
	codonMap["CGA"] = "Arg";
	codonMap["CUG"] = "Leu";
	codonMap["CCG"] = "Pro";
	codonMap["CAG"] = "Gln";
	codonMap["CGG"] = "Arg";
	codonMap["AUU"] = "Ile";
	codonMap["ACU"] = "Thr";
	codonMap["AAU"] = "Asn";
	codonMap["AGU"] = "Ser";
	codonMap["AUC"] = "Ile";
	codonMap["ACC"] = "Thr";
	codonMap["AAC"] = "Asn";
	codonMap["AGC"] = "Ser";
	codonMap["AUA"] = "Ile";
	codonMap["ACA"] = "Thr";
	codonMap["AAA"] = "Lys";
	codonMap["AGA"] = "Arg";
	codonMap["AUG"] = "Met";
	codonMap["ACG"] = "Thr";
	codonMap["AAG"] = "Lys";
	codonMap["AGG"] = "Arg";
	codonMap["GUU"] = "Val";
	codonMap["GCU"] = "Ala";
	codonMap["GAU"] = "Asp";
	codonMap["GGU"] = "Gly";
	codonMap["GUC"] = "Val";
	codonMap["GCC"] = "Ala";
	codonMap["GAC"] = "Asp";
	codonMap["GGC"] = "Gly";
	codonMap["GUA"] = "Val";
	codonMap["GCA"] = "Ala";
	codonMap["GAA"] = "Glu";
	codonMap["GGA"] = "Gly";
	codonMap["GUG"] = "Val";
	codonMap["GCG"] = "Ala";
	codonMap["GAG"] = "Glu";
	codonMap["GGG"] = "Gly";
}

bool parse(string input)
{
	
	return true;
}
// Returns the reverse of the string
string rev(string input)
{
	string out;
	for(int i = input.size()-1 ; i >= 0 ; i -- )
	{
		out += input[i];
	}
	return out;
}

// Returns the complement DNA of the input
string comple(string input)
{
	string out;
	for(int i = 0; i < input.size() ; i ++ )
	{
		switch(input[i])
		{
			case 'A': out += 'T'; break;
			case 'T': out += 'A'; break;
			case 'G': out += 'C'; break;
			case 'C': out += 'G'; break;
		}
	}
	return out;
}

int main()
{
	init__();

	while(1)
	{
		string str, str2, str3, str4;

		cin >> str;
		if (str == "*") break;
		
		if(parse(str)) {
			cout << trans << endl; continue;
		}
		
		str2 = rev(str);
		if (parse(str2)) {
			cout << trans << endl; continue;
		}
			
		str3 = comple(str);
		if (parse(str3)) {
			cout << trans << endl; continue;
		}
		
		str4 = rev(str3);
		if (parse(str4)) {
			cout << trans << endl; continue;
		}
		
		cout << "*** No translatable DNA found ***\n";
	}	
	return 0;										// Successful termination
}

