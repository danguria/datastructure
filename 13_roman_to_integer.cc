#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int romanToInt(string roman) {
            unordered_map<char, int> rToi = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
            };

            int base = 0, num = 0;

            std::string::reverse_iterator rit = roman.rbegin();
            for (; rit != roman.rend(); rit++) {

                int v = rToi[*rit];
                if (v >= base) {
                    num += v;
                    base = v;
                } else {
                    num -= v;
                }
            }
            return num;
        }
};

int main() {

    Solution s;
    cout << s.romanToInt("I") << endl;
    cout << s.romanToInt("II") << endl;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("IV") << endl;
    cout << s.romanToInt("V") << endl;
    cout << s.romanToInt("VI") << endl;
    cout << s.romanToInt("VII") << endl;
    cout << s.romanToInt("VIII") << endl;
    cout << s.romanToInt("IX") << endl;
    cout << s.romanToInt("X") << endl;
    return 0;
}

