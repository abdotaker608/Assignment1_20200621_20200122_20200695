#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string target, string delimiter);
int main()
{

	cout << "Enter string to split : \n";
	char chain[50];
	cin.getline(chain, 50);
	cout << "Enter delimiter : \n";
	char chain1[1];
	cin.getline(chain1, 1);
	string target(chain), delimiter(chain1);
	vector<string>  resulte =split(target, delimiter);
	for (size_t i = 0; i < resulte.size(); i++)
	{
		cout << '"' << resulte.at(i) << '"';
	}
}
vector<string> split(string target, string delimiter) {
	string tmp;
	vector<string> vec;
	for (int i = 0; i < target.length(); i++)
	{
		if (target[i] != delimiter[0])
		{
			tmp += target[i];
		}
		else{
			vec.push_back(tmp);
			tmp = "";
		}
	}
	return vec;
}
