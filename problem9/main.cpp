#include <bits/stdc++.h>
using namespace std;


int main() {
    string firstName, secondName;

    int choice;

    cout << "Enter the two files names separated by a space\n";

    cin >> firstName >> secondName;

    cout << "Select comparison method\n\n";
    cout << "0) Character by character\n";
    cout << "1) Word by word\n";

    cin >> choice;

    ifstream firstFile, secondFile;

    firstFile.open(firstName, ios::in);
    secondFile.open(secondName, ios::in);

    int counter = 1;

    bool diff = false;

    string s1, s2;

    if (choice == 0) {
        while (!firstFile.eof() && !secondFile.eof()) {
            getline(firstFile, s1), getline(secondFile, s2);

            int i = 0, j = 0;

            while (i < s1.length() && j < s2.length()) {
                if (s1[i] != s2[j]) {
                    cout << counter << " : " << s1 << "\n";
                    diff = true;
                    break;
                }

                i++, j++;
            }

            if (i < s1.length() || j < s2.length()) {
                cout << counter << " : " << s1 << "\n";
                diff = true;
                counter++;
                break;
            }

            if (diff) {
                counter++;
                break;
            }

            counter++;
        }

        if ((!firstFile.eof() || !secondFile.eof()) && !diff) {
            cout << counter - 1 << " : " << s1 << "\n";
            diff = true;
        }
    }
    else {
        getline(firstFile, s1), getline(secondFile, s2);

        int i = 0, j = 0;

        while (i < s1.length() && j < s2.length()) {
            while (i < s1.length() && (s1[i] == '\t' || s1[i] == ' ')) i++;
            while (j < s2.length() && (s2[j] == '\t' || s2[j] == ' ')) j++;

            if (i < s1.length() && j < s2.length() && s1[i] != s2[j]) {
                cout << s1 << "\n";
                diff = true;
                break;
            }

            i++, j++;

            if (i == s1.length() && !firstFile.eof()) {
                i = 0;
                getline(firstFile, s1);
            }

            if (j == s2.length() && !secondFile.eof()) {
                j = 0;
                getline(secondFile, s2);
            }

            if (diff) {
                break;
            }
        }

        if (firstFile.eof() || secondFile.eof()) {
            cout << s1 << "\n";
            diff = true;
        }
     }

    if (!diff) {
        cout << "Identical\n";
    }
}
