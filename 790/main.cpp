#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <sstream>
#include <climits>

using namespace std;

class Solution {
  public:
      int numTilings(int n) {
        if (n == 1) {
          return 1;
        }
        if (n == 2) {
          return 2;
        }
        if (n == 3) {
          return 5;
        }


        vector<long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i < n + 1; i++) {
          long triple_increase = 1 * dp[i - 3];
          long single_increase = 2 * dp[i - 1];
          dp[i] = (triple_increase + single_increase) % (1000000007);
        }

        return dp[n];
      }
  };

template <typename T>
string vectorToString(const vector<T> &vec, const string &delimiter = ", ")
{
  ostringstream oss;
  for (size_t i = 0; i < vec.size(); ++i)
  {
    if (i > 0)
      oss << delimiter; // Add delimiter between elements
    oss << vec[i];
  }
  return oss.str();
}

struct TestCase
{
  int k;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
      // { 3},
      // { 1},
      // { 4},
      { 5},
  };

  for (auto &test_case : test_cases)
  {
    long long result = solution.numTilings(test_case.k);
    cout << "k: " << test_case.k;
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}