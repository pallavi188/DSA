class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, maxlen = 0, maxfreq = 0;
        int hash[26] = {0};

        for (int r = 0; r < n; r++) {
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r] - 'A']);

            // shrink window if replacements exceed k
            while ((r - l + 1) - maxfreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
