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
      vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (int i = 0; i < strs.size(); i++) {
          string temp = strs[i];
          sort(temp.begin(), temp.end());

          anagrams[temp].push_back(strs[i]);
        }

        vector<vector<string>> output;
        for (auto& [key, anagram_group] : anagrams) {
          output.push_back(anagram_group);
        }

        return output;
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
  vector<string> nums;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {

{{"eat","tea","tan","ate","nat","bat"}},
{{""}},
{{"a"}},

  };

  for (auto &test_case : test_cases)
  {
    auto result = solution.groupAnagrams(test_case.nums);
    cout << "k: " << vectorToString(test_case.nums);
    cout << "\nResult: " << gridToString(result) << "\n\n";
  }

  return 0;
}