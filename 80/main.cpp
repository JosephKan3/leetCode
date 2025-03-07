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
      int removeDuplicates(vector<int>& nums) {
          
        int prev = -10001;
        int prev_prev = -10001;

        vector<int> output;
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
          k++;
          if (prev != -10001 && prev_prev != -10001 && prev == prev_prev && prev == nums[i]) {
            k--;
          } else {
            output.push_back(nums[i]);
          }
          prev_prev = prev;
          prev = nums[i];
        }

        for (int i = 0; i < output.size(); i++) {
          nums[i] = output[i];
        }

        return k;
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
    {{1,1,1,2,2,3}},
    {{0,0,1,1,1,1,2,3,3}},
  };

  for (auto &test_case : test_cases)
  {
    auto result = solution.removeDuplicates(test_case.nums);
    cout << "nums: " << vectorToString(test_case.nums);
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}