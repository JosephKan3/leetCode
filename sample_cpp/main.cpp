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

using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      return {-1};
    }
};


int main() {
  Solution solution;

  // Example test cases with different inputs
  vector<vector<int>> test_cases = {
      {1, 2, 3, 4}, // Example 1
      {2, 3, 4, 5}, // Example 2
      {1, 1, 1, 1}, // Example 3
      {4, 5, 1, 8, 2} // Example 4
  };

  // Process each test case
  for (auto& test_case : test_cases) {
      vector<int> result = solution.productExceptSelf(test_case);

      // Output the result for the current test case
      cout << "Input: ";
      for (int num : test_case) {
          cout << num << " ";
      }
      cout << "\nResult: ";
      for (int num : result) {
          cout << num << " ";
      }
      cout << "\n\n";
  }

  return 0;
};