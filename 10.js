function isMatch(s, p) {
    // Creates dp matrix
    var stringLength = s.length + 1;
    var patternLength = p.length + 1;
    var dp = new Array(patternLength + 1);
    for (var i = 0; i < patternLength; i++) {
        dp[i] = new Array(stringLength).fill(0);
    }
    dp[0][0] = 1;
    // Fill dp matrix with matches
    for (var i = 1; i < patternLength; i++) {
        for (var j = 1; j < stringLength; j++) {
            // Check if pattern is .
            if (p.charAt(i - 1) == '.') {
                dp[i][j] = dp[i - 1][j - 1];
                // Check if pattern is *
            }
            else if (p.charAt(i - 1) == '*') {
                // Check if the duplicated pattern is found at the current string
                if (p.charAt(i - 2) != s.charAt(j - 1) && p.charAt(i - 2) != ".") {
                    dp[i][j] = dp[i - 2][j]; // Treats the previous two characters (a*) as empty
                }
                else {
                    if (dp[i - 1][j] == 1 || dp[i - 2][j] == 1 || dp[i][j - 1] == 1) {
                        dp[i][j] = 1; // Matches the previous character + times
                    }
                }
                // Check if the pattern is a character and equal to the string
            }
            else if (p.charAt(i - 1) == s.charAt(j - 1)) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    for (var i = 0; i < patternLength; i++) {
        process.stdout.write("".concat(i, "\t["));
        for (var j = 0; j < stringLength; j++) {
            process.stdout.write("".concat(dp[i][j], ", "));
        }
        console.log("]");
    }
    // Scan last element to search for a full match
    if (dp[patternLength - 1][stringLength - 1] == 1) {
        return true;
    }
    else {
        return false;
    }
}
;
console.log(isMatch("mississippi", "mis*is*p*."));
