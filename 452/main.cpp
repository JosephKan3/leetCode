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
      int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) {
          return 1;
        }
        int arrows_needed = points.size();
        
        vector<pii> intervals;
        for (auto& point : points) {
          intervals.push_back({point[0], point[1]});
        }

        sort(intervals.begin(), intervals.end());
        
        int begin = intervals[0].first;
        int end = intervals[0].second;
        for (int i = 1; i < intervals.size(); i++) {
          int curr_begin = intervals[i].first;
          int curr_end = intervals[i].second;
          // 1: Left overhang or full overlap
          if (curr_begin >= begin && curr_begin <= end) {
            arrows_needed--;
            begin = max(curr_begin, begin);
            end = min(curr_end, end);
          // 2: No overlap (No right overhang since sorted)
          } else {
            begin = curr_begin;
            end = curr_end;
          }
        }
        

        return arrows_needed;
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
    cout << "k: " << gridToString(test_case.grid);
    auto result = solution.findMinArrowShots(test_case.grid);
    cout << "\nResult: " << (result) << "\n\n";
  }

  return 0;
}