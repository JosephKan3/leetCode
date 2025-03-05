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

#define pii pair<int, int>

enum class Direction {
  SOUTH = 1,
  NORTH_EAST = 2,
};

class Solution {
  public:
      string convert(string s, int numRows) {
          if (numRows == 1) {
            return s;
          }
          vector<vector<char>> arr(numRows, vector<char>(1000, ' '));

          pii curr_pos = {0, 0};
          Direction mode = Direction::SOUTH;

          int max_x = 0;
          for (int i = 0; i < s.size(); i++) {
            max_x = curr_pos.first;
            arr[curr_pos.second][curr_pos.first] = s[i];

            if (mode == Direction::SOUTH) {
              if (curr_pos.second + 1 >= numRows) {
                mode = Direction::NORTH_EAST;
                curr_pos.second--;
                curr_pos.first++;
              } else {
                curr_pos.second++;
              }
            } else if (mode == Direction::NORTH_EAST) {
              if (curr_pos.second - 1 < 0) {
                mode = Direction::SOUTH;
                curr_pos.second++;
              } else {
                curr_pos.second--;
                curr_pos.first++;
              }
            }
          }

          string output = "";
          for (int j = 0; j < numRows; j++) {
            for (int i = 0; i <= max_x; i++) {
              if (arr[j][i] != ' ') {
                output += arr[j][i];
              }
            }
          }
          return output;

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
  string word;
  int row_num;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {{"PAYPALISHIRING"}, 3},
    {{"PAYPALISHIRING"}, 4},
    {{"A"}, 1},
  };

  for (auto &test_case : test_cases)
  {
    string result = solution.convert(test_case.word, test_case.row_num);
    cout << "k: " << test_case.word << "k: " << test_case.row_num;
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}