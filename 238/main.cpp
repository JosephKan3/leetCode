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
      stack<int> left_products;

      if (nums.size() <= 1) {
        return {-1};
      }
      

      // Assemble left product stack
      for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (i == 0) {
          left_products.push(num);
          continue;
        }

        left_products.push(left_products.top() * num);
      }

      // Calculate first row
      left_products.pop();
      vector<int> output = {left_products.top()};

      int right_product = nums[nums.size() - 1];
      for (int i = nums.size() - 2; i >= 0; i--) {
        int num = nums[i];
        left_products.pop();

        if (left_products.empty()) {
          output.push_back(right_product);
        } else {
          output.push_back(left_products.top() * right_product);
        }

        right_product = right_product * num;
      }

      


      reverse(output.begin(), output.end());

      return output;
    }
};


int main() {
  Solution solution;

  // Example test cases with different inputs
  vector<vector<int>> test_cases = {
      {1, 2, 3, 4}, // Example 1
      {2, 3, 4, 5}, // Example 2
      {1, 1, 1, 1}, // Example 3
      {-1,1,0,-3,3} // Example 4
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