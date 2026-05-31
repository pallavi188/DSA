class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long currMass = mass;
        for(int ast : asteroids){
            if(currMass < ast){
                return false;
            }
            currMass += ast;
        }
        return true;
    }
};