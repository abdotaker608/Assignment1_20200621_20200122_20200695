#include <iostream>
#include <string>
using namespace std;

class BigInt {
    private:
        bool isNegative;
        string dec;

    public:
        BigInt(string decStr) {
            for (int i = 0; i < decStr.length(); i++) {
                if ((i != 0 && decStr[i] == '-') && !isdigit(decStr[i])) throw "Rejected..Bad Input!";
            }
            string absDecStr = abs(decStr);
            isNegative = absDecStr != decStr;
            dec = absDecStr;
        }

        BigInt(int decInt) {
            isNegative = decInt < 0;
            dec = isNegative ? to_string(decInt).substr(1) : to_string(decInt);
        }

        string abs(string s) {
            if (s.length() > 0 && s[0] == '-') return s.substr(1);
            return s;
        }

        int size() {
            return dec.size();
        }

        BigInt operator + (BigInt anotherDec) {
            if (!(anotherDec.isNegative && isNegative) && (anotherDec.isNegative || isNegative)) {
                BigInt b1(anotherDec.dec);
                b1.isNegative = false;
                BigInt b2(dec);
                b2.isNegative = false;
                return anotherDec.isNegative ? b2 - b1 : b1 - b2;
            }
            int n1 =  dec.length() - 1;
            int n2 = anotherDec.dec.length() - 1;
            int carry = 0;
            string result;
            while (n1 >= 0 || n2 >= 0) {
                int sum = carry;
                if (n1 >= 0) sum += dec[n1] - '0';
                if (n2 >= 0) sum += anotherDec.dec[n2] - '0';
                if (sum > 9) {
                    carry = sum / 10;
                    sum %= 10;
                }
                else carry = 0;
                result = to_string(sum) + result;
                n1 -= 1;
                n2 -= 1;
            }
            string sol = carry > 0 ? to_string(carry) + result : result;
            if (anotherDec.isNegative || isNegative) return BigInt('-' + sol);
            return BigInt(sol);
        }

        BigInt operator - (BigInt anotherDec) {
            if (!isNegative && anotherDec.isNegative) {
                BigInt b1(anotherDec.dec);
                b1.isNegative = false;
                BigInt b2(dec);
                b2.isNegative = false;
                return b1 + b2;
            }
            if (isNegative && anotherDec.isNegative) {
                BigInt b1(anotherDec.dec);
                b1.isNegative = false;
                BigInt b2(dec);
                b2.isNegative = false;
                return b1 - b2;
            }
            if (isNegative && !anotherDec.isNegative) {
                BigInt b1(anotherDec.dec);
                b1.isNegative = true;
                BigInt b2(dec);
                b2.isNegative = true;
                return b1 + b2;
            }
            int n1 =  dec.length() - 1;
            int n2 = anotherDec.dec.length() - 1;
            bool negativeResult = n1 < n2 || (n1 == n2 && dec[0] < anotherDec.dec[0]);
            string mx = negativeResult ? anotherDec.dec : dec;
            string mn = negativeResult ? dec : anotherDec.dec;
            n1 = mx.length() - 1;
            n2 = mn.length() - 1;
            string result;
            int borrow = 0;
            int lastBorrow = 0;
            while (n1 >= 0 || n2 >= 0) {
                int sub = n2 >= 0 ? (mn[n2] - '0') : 0;
                int diff = ((mx[n1] - '0') - lastBorrow) - sub;
                if (diff < 0) borrow = 1;
                else borrow = 0;
                int rem = ((10 * borrow) + ((mx[n1] - '0') - lastBorrow)) - sub;
                result = to_string(rem) + result;
                lastBorrow = borrow;
                n1 -= 1;
                n2 -= 1;
            }
            result = result.erase(0, min(result.find_first_not_of('0'), result.length() - 1));
            return BigInt(negativeResult ? "-" + result : result);
        }

        BigInt operator = (BigInt anotherDec) {
            isNegative = anotherDec.isNegative;
            dec = anotherDec.dec;
            return (*this);
        }

        friend ostream& operator << (ostream& out, BigInt b) {
            if (b.isNegative) out << '-' << b.dec << endl;
            else out << b.dec << endl;
            return out;
        }

        ~BigInt() {}
};

int main() {
    BigInt num1("123456789012345678901234567890");
    BigInt num2("123456789012345678901234567890");
    BigInt num3 = num1 + num2;
    cout << "num1 is: " << num1 << endl;
    cout << "num2 is: " << num2 << endl;
    cout << "num3 is: " << num3 << endl;
}
