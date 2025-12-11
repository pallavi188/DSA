class Solution {
public:
    string removeDigit(string number, char digit) {
        int base = 1;
        string ans = "";
        int idx = -1;
        for (int i = 0; i < number.length(); i++) {
            if (number[i] == digit) {
                idx = i;

                if (i + 1 < number.length() && number[i + 1] > digit) {
                    idx = i;
                    break;
                }
            }
        }
        for (int j = 0; j < number.length(); j++) {
            if (j != idx)
                ans += number[j];
        }
        return ans;
    }
};