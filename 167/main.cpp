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
      vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1 = 0;
        int ptr2 = numbers.size() - 1;

        int sum;
        while (ptr1 < ptr2) {
          sum = numbers[ptr1] + numbers[ptr2];
          if (sum == target) return {ptr1 + 1, ptr2 + 1};

          if (sum > target) {
            ptr2--;
          } else {
            ptr1++;
          }
        }

        return {-1, -1};
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
    auto result = solution.twoSum(test_case.arr, test_case.target);
    cout << "k: " << vectorToString(test_case.arr) << "target: " << test_case.target;
    cout << "\nResult: " << vectorToString(result) << "\n\n";
  }

  return 0;
}