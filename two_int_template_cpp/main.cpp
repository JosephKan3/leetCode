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
      vector<int> closestPrimes(int left, int right) {
          vector<int> output = {-1, -1};

        return output;
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
  int left;
  int right;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {958995, 959083},
  };

  for (auto &test_case : test_cases)
  {
    cout << "left: " << test_case.left << " right: " << test_case.right;
    auto result = solution.closestPrimes(test_case.left, test_case.right);
    cout << "\nResult: " << vectorToString(result) << "\n\n";
  }

  return 0;
}