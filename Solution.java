
import java.util.Arrays;

public class Solution {

    public int bagOfTokensScore(int[] tokens, int power) {

        Arrays.sort(tokens);
        int maxPossibleScore = 0;
        int currentScore = 0;
        int frontIndex = 0;
        int backIndex = tokens.length - 1;

        while (frontIndex <= backIndex && power >= tokens[frontIndex]) {

            while (frontIndex <= backIndex && power >= tokens[frontIndex]) {
                power -= tokens[frontIndex];
                ++currentScore;
                ++frontIndex;
            }

            maxPossibleScore = Math.max(maxPossibleScore, currentScore);
            if (frontIndex < backIndex && currentScore > 0) {
                power += tokens[backIndex];
                --currentScore;
                --backIndex;
            }
        }
        return maxPossibleScore;
    }
}
