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


# define pii pair<int,int>
class Solution {
  public:
      vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pii> interval_pairs;
        for (auto& interval : intervals) {
          interval_pairs.push_back({interval[0], interval[1]});
        }
        
        // Intervals sorted by start
        sort(interval_pairs.begin(), interval_pairs.end());
        
        vector<vector<int>> merged;
        merged.push_back({interval_pairs[0].first, interval_pairs[0].second});
        for (int i = 1; i < interval_pairs.size(); i++) {
          int start = interval_pairs[i].first;
          int end = interval_pairs[i].second;

          if (start <= merged[merged.size() - 1][1]) {
            merged[merged.size() - 1][1] = max(end, merged[merged.size() - 1][1]);
          } else {
            merged.push_back({start, end});
          }
        }

        return merged;
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
    {{{1,3},{2,6},{8,10},{15,18}}},
    {{{1,4},{4,5}}},
  };

  for (auto &test_case : test_cases)
  {
    auto result = solution.merge(test_case.grid);
    cout << "k: " << gridToString(test_case.grid);
    cout << "\nResult: " << gridToString(result) << "\n\n";
  }

  return 0;
}