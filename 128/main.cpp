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
      int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> visited;

        for (auto num : nums) {
          visited[num] = true;
        }

        int max_count = 0;
        int curr_count = 0;
        while (visited.size() != 0) {
          int curr_key = visited.begin()->first;
          curr_count = 1;

          int left_key = curr_key - 1;
          while (visited.count(left_key)) {
            visited.erase(left_key);
            curr_count++;
            left_key--;
          }

          int right_key = curr_key + 1;
          while (visited.count(right_key)) {
            visited.erase(right_key);
            curr_count++;
            right_key++;
          }

          visited.erase(curr_key);
          max_count = max(max_count, curr_count);
        }

        return max_count;
      }
  };

/**
 * Runner Logic
 */
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

{{-1,0,1,2,-1,-4}},
{{0,1,1}},
{{0,0,0}},

  };

  for (auto &test_case : test_cases)
  {
    int result = solution.longestConsecutive(test_case.nums);
    cout << "k: " << vectorToString(test_case.nums);
    cout << "\nResult: " << (result) << "\n\n";
  }

  return 0;
}