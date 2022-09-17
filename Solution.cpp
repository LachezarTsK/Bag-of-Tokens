
#include <vector>
using namespace std;

class Solution {
    
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        //C++20: std::ranges::sort(tokens);
        sort(tokens.begin(), tokens.end());
        int maxPossibleScore = 0;
        int currentScore = 0;
        int frontIndex = 0;
        int backIndex = tokens.size() - 1;

        while (frontIndex <= backIndex && power >= tokens[frontIndex]) {

            while (frontIndex <= backIndex && power >= tokens[frontIndex]) {
                power -= tokens[frontIndex];
                ++currentScore;
                ++frontIndex;
            }

            maxPossibleScore = max(maxPossibleScore, currentScore);
            if (frontIndex < backIndex && currentScore > 0) {
                power += tokens[backIndex];
                --currentScore;
                --backIndex;
            }
        }
        return maxPossibleScore;
    }
};
