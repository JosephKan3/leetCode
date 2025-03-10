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
      int maxArea(vector<int>& height) {
        int ptr1 = 0;
        int ptr2 = height.size() - 1;

        int max_area = 0;
        while (ptr1 < ptr2) {
          int dist = ptr2 - ptr1;
          int area = min(height[ptr1], height[ptr2]) * dist;

          max_area = max(area, max_area);

          if (height[ptr1] < height[ptr2]) {
            ptr1++;
          } else {
            ptr2--;
          }
        }

        return max_area;
        
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

{{1,8,6,2,5,4,8,3,7}},
{{1,1}},
  };

  for (auto &test_case : test_cases)
  {
    auto result = solution.maxArea(test_case.nums);
    cout << "k: " << vectorToString(test_case.nums);
    cout << "\nResult: " << (result) << "\n\n";
  }

  return 0;
}