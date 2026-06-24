class Solution {
public:
    int nextNum(int n){
        int sum = 0;
        while(n){
            int dig = n%10;
            sum += dig*dig;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow =n;
        int fast =n;
        do{
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }while(slow != fast);
        return slow == 1;
    }
};