#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, modified = "";

    getline(cin, s);

    string current = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == '.') {
            if (current == "He" || current == "She") modified += "He or she";
            else if (current == "he" || current == "she") modified += "he or she";
            else if (current == "Him" || current == "Her") modified += "Him or her";
            else if (current == "him" || current == "her") modified += "him or her";
            else modified += current;

            modified += s[i];

            current = "";
        }
        else {
            current += s[i];
        }
    }

    cout << modified << "\n";
}
