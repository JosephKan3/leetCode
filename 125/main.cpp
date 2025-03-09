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

// class Solution {
//   public:
//       bool isPalindrome(string s) {
//         string cleaned = "";

//         for (char character : s) {
//           if (!isalnum(character)) continue;

//           cleaned.push_back(tolower(character));
//         }

//         int half_size = floor(cleaned.size() / 2);

//         string first = cleaned.substr(0, half_size);
//         string second = cleaned.substr(cleaned.size() - half_size, cleaned.size() - 1);
//         reverse(second.begin(), second.end());

//         return first == second;
//       }
//   };


class Solution {
  public:
      bool isPalindrome(string s) {
        string cleaned = "";

        for (char character : s) {
          if (!isalnum(character)) continue;

          cleaned.push_back(tolower(character));
        }

        string temp = cleaned;
        reverse(temp.begin(), temp.end());

        return temp == cleaned;
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
  string input;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {
      "A man, a plan, a canal: Panama"
    },
  };

  for (auto &test_case : test_cases)
  {
    cout << "left: " << test_case.input;
    auto result = solution.isPalindrome(test_case.input);
    cout << "\nResult: " << (result) << "\n\n";
  }

  return 0;
}