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
      int primePalindrome(int n) {
          if (n < 2) {
            return 0;
          }
          int MAX = 100000000;
          vector<bool> is_prime(MAX + 1, true);
          is_prime[0] = false;
          is_prime[1] = false;

          for (int i = 2; i * i <= MAX; i++) {
            if (is_prime[i]) {
              for (int j = i * i; j <= MAX; j += i) {
                is_prime[j] = false;
              }
            }
          }

          for (int i = n + 1; i < is_prime.size(); i++) {
            if (is_prime[i]) {
              string int_str = to_string(i);
              int ptr1 = 0;
              int ptr2 = int_str.size() - 1;
              bool found = true;
              while (ptr1 < ptr2) {
                if (int_str[ptr1] != int_str[ptr2]) {
                  found = false;
                  break;
                }
              }
              if (found) {
                return i;
              }

            }
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
  int left;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    // {10},
    {6},
    {8},
    {13},
    // {2},
    // {1},
  };

  for (auto &test_case : test_cases)
  {
    int result = solution.primePalindrome(test_case.left);
    cout << "left: " << test_case.left << endl;
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}