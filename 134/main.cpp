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
      int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 1) {
          if (gas[0] >= cost[0]) {
            return 0;
          } else {
            return -1;
          }
        }
        vector<int> profit;
        for (int i = 0; i < gas.size(); i++) {
          profit.push_back(gas[i] - cost[i]);
        }

        vector<int> sum_from_zero;
        int min_sum = INT_MAX;
        int station_after_min;
        int sum = 0;
        for (int i = 0; i < gas.size(); i++) {
          sum = profit[i] + sum;
          sum_from_zero.push_back(sum);
          
          if (sum < min_sum) {
            station_after_min = (i + 1) % profit.size();
            min_sum = sum;
          }
        }

        vector<int> new_cycle = profit;
        rotate(new_cycle.begin(), new_cycle.begin() + station_after_min, new_cycle.end());

        sum = 0;
        for (int i = 0; i < new_cycle.size(); i++) {
          sum += new_cycle[i];
          if (sum < 0) {
            return -1;
          }
        }
        return station_after_min;

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
  vector<int> arr1;
  vector<int> arr2;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {{1,2,3,4,5},{3,4,5,1,2}},
    {{2,3,4},{3,4,3}},
  };

  for (auto &test_case : test_cases)
  {
    cout << "1: " << vectorToString(test_case.arr1) << "2: " << vectorToString(test_case.arr2);
    auto result = solution.canCompleteCircuit(test_case.arr1, test_case.arr2);
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}