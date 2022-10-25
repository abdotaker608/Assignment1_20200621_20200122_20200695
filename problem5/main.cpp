#include <iostream>
#include <vector>
using namespace std;
struct dominoT {
	int leftDots;
	int rightDots;
};
bool FormsDominoChain(vector<dominoT>& dominos);
int main()
{
	vector<dominoT> dominos;
	vector<dominoT> s;
	dominoT d;
	char chain[50];
	cin.getline(chain, 50);
	for (int i = 0; i < 50; i++)
	{
		if (!(chain[i] == ' ' || chain[i] == '|' || chain[i] == '-')) {
			if (chain[i + 1] == '|') {
				d.leftDots = chain[i];
				d.rightDots = chain[i+2];
				dominos.push_back(d);
			}
		}
	}
	if (FormsDominoChain(dominos)){
		cout << "chain";}
	else {
		cout << "no";
		}
	return 0;


	}
