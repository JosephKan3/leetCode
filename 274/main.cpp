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
      int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int max_score = INT_MIN;
        for (int i = 0; i < citations.size(); i++) {
          int valid_papers = citations.size() - i;
          int val = citations[i];
          int h_score = min(valid_papers, val);
          max_score = max(max_score, h_score);
        }

        return max_score;
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
  vector<int> nums;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {{3,0,6,1,5}},
    {{1,3,1}},
  };

  for (auto &test_case : test_cases)
  {
    cout << "k: " << vectorToString(test_case.nums);
    auto result = solution.hIndex(test_case.nums);
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}