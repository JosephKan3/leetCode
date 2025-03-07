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
      vector<vector<int>> solve(int ptr_1, vector<int> candidates, int target) {

        vector<vector<int>> output;
        for (int ptr_2 = candidates.size() - 1; ptr_2 >= 0; ptr_2--) {
          int val1 = candidates[ptr_1];
          int val2 = candidates[ptr_2];
          
          if (val2 == target) {
            output.push_back({val2});
            ptr_2--;
          } else if (val2 > target) {
            ptr_2--;
          } else {
            int difference = target - val2;
            vector<int> mini_vector(candidates.begin() + ptr_1, upper_bound(candidates.begin(), candidates.end(), difference));
            vector<vector<int>> mini_sols = solve(ptr_1 + 1, mini_vector, difference);

            for (auto sol : mini_sols) {
              sol.push_back(val2);
              output.push_back(sol);
            }
            ptr_2--;
          }
        }



        return {output};
      };


      vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin(), candidates.end());
          auto sol = solve(0, candidates, target);

          set<vector<int>> unique;
          for (auto& v : sol) {
            sort(v.begin(), v.end());
            unique.insert(v);
          }

          return vector<vector<int>>(unique.begin(), unique.end());
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
  vector<int> vect;
  int target;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {
      {10,1,2,7,6,1,5},
      8
    },
    // {
    //   {2,5,2,1,2},
    //   5
    // },
  };

  for (auto &test_case : test_cases)
  {
    vector<vector<int>> result = solution.combinationSum2(test_case.vect, test_case.target);
    cout << "k: " << vectorToString(test_case.vect) << "k: " << test_case.target;
    cout << "\nResult: " << gridToString(result) << "\n\n";
  }

  return 0;
}