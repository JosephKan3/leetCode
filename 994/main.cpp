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


#define tii tuple<int,int,int> // x, y, time
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Empty = 0
        // Fresh = 1
        // Rot = 2

        int minutes = 0;
        queue<tii> rot_queue;
        int fresh_count = 0;
        int last_time = 0;

        int y_len = grid.size();
        int x_len = grid[0].size();

        for (int y = 0; y < y_len; y++) {
          for (int x = 0; x < x_len; x++) {
            if (grid[y][x] == 2) {
              rot_queue.push({x, y, 0});
            } else if (grid[y][x] == 1) {
              fresh_count++;
            }
          }
        }

        // x, y
        vector<pair<int, int>> directions = {
          {-1, 0}, {0, 1}, {1, 0}, {0, -1}
        };

        while (not rot_queue.empty()) {
          tii curr = rot_queue.front();
          rot_queue.pop();
          last_time = get<2>(curr);

          for (const auto& [x_change, y_change] : directions) {
            int new_x = get<0>(curr) + x_change;
            int new_y = get<1>(curr) + y_change;

            if (new_x >= 0 & new_x < x_len & new_y >= 0 & new_y < y_len) {
              int adjacent_value = grid[new_y][new_x];
              if (adjacent_value == 1) {
                grid[new_y][new_x] = 2;
                fresh_count--;
                rot_queue.push({new_x, new_y, last_time + 1});
              }
            }
          }



        }

        if (fresh_count == 0) {
          return last_time;
        } else {
          return -1;
        }



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
  vector<vector<int>> grid;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {{{2,1,1},{1,1,0},{0,1,1}}},
    {{{2,1,1},{0,1,1},{1,0,1}}},
    {{{0,2}}},
  };

  for (auto &test_case : test_cases)
  {
    long long result = solution.orangesRotting(test_case.grid);
    cout << "k: " << gridToString(test_case.grid);
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}