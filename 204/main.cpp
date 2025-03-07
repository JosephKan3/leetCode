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
      int countPrimes(int n) {
          if (n < 2) {
            return 0;
          }
          vector<bool> is_prime(n, true);
          is_prime[0] = false;
          is_prime[1] = false;

          int count = 0;
          for (int i = 2; i * i < n; i++) {
            if (is_prime[i]) {
              for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
              }
              count++;
            }
          }

          for (int i = floor(sqrt(n - 1)) + 1; i < is_prime.size(); i++) {
            if (is_prime[i]) {
              count++;
            }
          }

          return count;
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
    {0},
    // {2},
    // {1},
  };

  for (auto &test_case : test_cases)
  {
    int result = solution.countPrimes(test_case.left);
    cout << "left: " << test_case.left << endl;
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}