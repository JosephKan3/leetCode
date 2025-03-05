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
      vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1, vector<string>());

        dp[1] = {"()"};
        for (int i = 2; i < n + 1; i++) {
          unordered_set<string> combos;

          for (auto previous_str : dp[i - 1]) {
            for (int j = 0; j < previous_str.size(); j++) {
              string temp = previous_str;
              combos.insert(temp.insert(j, "()"));
            }
          }

          dp[i] = vector<string>(combos.begin(), combos.end());
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

template <typename T>
string gridToString(const vector<vector<T>> &grid, const string &rowDelimiter = "\n", const string &colDelimiter = ", ") 
{
  ostringstream oss;
  for (size_t i = 0; i < grid.size(); ++i) 
  {
    if (i > 0)
      oss << rowDelimiter; // Add row delimiter between rows

    for (size_t j = 0; j < grid[i].size(); ++j) 
    {
      if (j > 0)
        oss << colDelimiter; // Add column delimiter between elements
      oss << grid[i][j];
    }
  }
  return oss.str();
}


struct TestCase
{
  int n;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {1},
    {2},
    {3},
  };

  for (auto &test_case : test_cases)
  {
    vector<string> result = solution.generateParenthesis(test_case.n);
    cout << "k: " << test_case.n;
    cout << "\nResult: " << vectorToString(result) << "\n\n";
  }

  return 0;
}