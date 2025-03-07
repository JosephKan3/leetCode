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

// O(n^2)
// class Solution {
//   public:
//       vector<int> closestPrimes(int left, int right) {
//           unordered_map<int, bool> is_composite;

//           int last_prime = -1;
//           int min_diff = INT_MAX;
//           vector<int> output = {-1, -1};
//           for (int i = 2; i <= right; i++) {
//             if (min_diff == 1) {
//               return output;
//             }
//             if (is_composite[i]) {
//               continue;
//             }
            
            
//             if (last_prime != -1 & last_prime >= left) {
//               if (i - last_prime < min_diff) {
//                 min_diff = i - last_prime;
//                 output = {last_prime, i};
                
//               }
              
//             }
//             last_prime = i;
            
            
//             for (int j = i; j <= right; j += i) {
//               is_composite[j] = true;
//             }

            
//           }

//         return output;
//       }
//   };


// class Solution {
//   public:
//       vector<int> closestPrimes(int left, int right) {
//           vector<int> primes = {2};

//           int last_prime = -1;
//           int min_diff = INT_MAX;
//           vector<int> output = {-1, -1};
//           for (int i = 2; i <= right; i++) {
//             if (min_diff == 1) {
//               return output;
//             }

//             bool is_prime = true;
//             for (int prime : primes) {
//               if (i % prime == 0) {
//                 is_prime = false;
//                 break;
//               }
//             }
//             if (!is_prime) {
//               continue;
//             }
            
            
//             if (last_prime != -1 & last_prime >= left) {
//               if (i - last_prime < min_diff) {
//                 min_diff = i - last_prime;
//                 output = {last_prime, i};
                
//               }
              
//             }

//             last_prime = i;
//             primes.push_back(i);
            
//           }

//         return output;
//       }
//   };

class Solution {
  public:
      vector<int> closestPrimes(int left, int right) {
          vector<bool> is_composite(right + 1, false);
          is_composite[0] = true;
          is_composite[1] = true;
          is_composite[2] = false;

          for (int i = 2; i * i <= right; i++) {
            if (is_composite[i]) {
              continue;
            }
            
            for (int j = i * i; j <= right; j += i) {
              is_composite[j] = true;
            }            
          }
          
          int last_prime = -1;
          int min_diff = INT_MAX;
          vector<int> output = {-1, -1};

          for (int i = left; i < is_composite.size(); i++) {
            if (is_composite[i]) {
              continue;
            }
            if (last_prime != -1) {
              if (i - last_prime < min_diff) {
                min_diff = i - last_prime;
                output = {last_prime, i};
                
              }
              
            }
            last_prime = i;
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
  int left;
  int right;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
    {958995, 959083},
    // {4, 6},
    // {10, 13}
  };

  for (auto &test_case : test_cases)
  {
    vector<int> result = solution.closestPrimes(test_case.left, test_case.right);
    cout << "left: " << test_case.left << " right: " << test_case.right;
    cout << "\nResult: " << vectorToString(result) << "\n\n";
  }

  return 0;
}