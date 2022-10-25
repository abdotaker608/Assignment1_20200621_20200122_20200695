#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    bool ok =false;
    int C = 0;
    vector<pair<int, string>>v(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    sort(v.rbegin(), v.rend());
    pair<int, string>pr;
    cin >> pr.first >> pr.second;
    for (int j =0; j <10; j++)
    {
        if (pr.first > v[j].first)
        {
            v.insert(v.begin() + j, pr);
            ok = true;
            break;
        }
    }
    for (int k = 0; k < 10; k++)
    {
        cout << v[k].second << " " << v[k].first << endl;
    }
    if (ok == false)
    {
        cout << "the player’s name has not been in the top 10" << endl;
    }
    return 0;
}
