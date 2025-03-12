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


#define tii tuple<int,int,int> // x, y, time
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      return -1;
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
  vector<vector<int>> grid;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {{{2,1,1},{1,1,0},{0,1,1}}},
    {{{2,1,1},{0,1,1},{1,0,1}}},
    {{{0,2}}},
  };

  for (auto &test_case : test_cases)
  {
    cout << "k: " << gridToString(test_case.grid);
    auto result = solution.orangesRotting(test_case.grid);
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}