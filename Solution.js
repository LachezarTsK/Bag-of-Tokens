
/**
 * @param {number[]} tokens
 * @param {number} power
 * @return {number}
 */
var bagOfTokensScore = function (tokens, power) {

    tokens.sort((x, y) => x - y);
    let maxPossibleScore = 0;
    let currentScore = 0;
    let frontIndex = 0;
    let backIndex = tokens.length - 1;

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
};
