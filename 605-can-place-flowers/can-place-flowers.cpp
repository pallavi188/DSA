class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k = flowerbed.size();

        for (int i = 0; i < k && n > 0; i++) {
            if (flowerbed[i] == 0) {
                int left  = (i == 0) ? 0 : flowerbed[i - 1];
                int right = (i == k - 1) ? 0 : flowerbed[i + 1];

                if (left == 0 && right == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }

        return n == 0;
    }
};
