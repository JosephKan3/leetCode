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
    int search(vector<int>& nums, int target) {
      int lo = 0;
      int hi = nums.size();
      int mid = floor((lo + hi) / 2);

      while (lo < hi) {
        if (nums[mid] == target) {
          return mid;
        }

        // Left sorted
        if (nums[lo] <= nums[mid]) {
          if (target < nums[mid] && target >= nums[lo]) {
            hi = mid;
          } else {
            lo = mid + 1;
          }
          
        // Right sorted
        } else {
          if (target > nums[mid] && target <= nums[hi - 1]) {
            lo = mid + 1;
          } else {
            hi = mid;
          }
        }
        
        mid = floor((lo + hi) / 2);
      }

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
  vector<int> arr;
  int target;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {

    // {{1,9,2,3,4,5,6,7,8}, 9}
    // {{2,3,4,5,6,7,8,9,1}, 9}
{{4,5,6,7,0,1,2}, 3},
// {{4,5,6,7,0,1,2}, 3},
// {{4,5,6,7,0,1,2}, 5},


  };

  for (auto &test_case : test_cases)
  {
    cout << "k: " << vectorToString(test_case.arr) << "target: " << test_case.target;
    auto result = solution.search(test_case.arr, test_case.target);
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}