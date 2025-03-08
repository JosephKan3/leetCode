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
      bool canJump(vector<int>& nums) {
        vector<bool> can_jump(nums.size(), false);

        can_jump[0] = true;
        for (int i = 0; i < can_jump.size(); i++) {
          if (can_jump[i]) {
            
            int next_jump = 1;
            while (i + next_jump < nums.size() && next_jump <= nums[i]) {
              can_jump[i + next_jump] = true;
              next_jump++;

            }
          }
        }

        return can_jump[nums.size() - 1];
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
    {{2,3,1,1,4}},
  };

  for (auto &test_case : test_cases)
  {
    auto result = solution.canJump(test_case.nums);
    cout << "k: " << vectorToString(test_case.nums);
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}