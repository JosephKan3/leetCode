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
      void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1) {
          return;
        }

        int rotations = k % nums.size();
        vector<int> first(nums.end() - rotations, nums.end());
        vector<int> second(nums.begin(), nums.end() - rotations);


        for (auto num : second) {
          first.push_back(num);
        }

        nums.swap(first);
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
  int k;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {{1,2,3}, 2},
    {{1,2,3,4,5,6,7}, 3},
    {{-1,-100,3,99}, 2},
    
  };

  for (auto &test_case : test_cases)
  {
    cout << "nums: " << vectorToString(test_case.nums) << "k: " << test_case.k;
    solution.rotate(test_case.nums, test_case.k);
    cout << "\nResult: " << vectorToString(test_case.nums) << "\n\n";
  }

  return 0;
}