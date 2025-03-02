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
//       bool increasingTriplet(vector<int>& nums) {
//         if (nums.size() <= 2) {
//           return false;
//         }

//         int i = 0;
//         int j = 1;
//         int k = 2;

//         int val1 = nums[i];
//         int val2 = nums[j];
//         int val3 = nums[k];

//         // Loop while no correct match
//         while (i < nums.size() - 2) {
//           if (val1 < val2 & val2 < val3) {
//             return true;
//           }

//           k++;

//           if (k >= nums.size()) {
//             j++;
//             k = j + 1;
//           }

//           // If either j or k go over, reset to next i, i+1, i+2
//           if (j >= k | k >= nums.size()) {
//             i++;
//             j = i + 1;
//             k = i + 2;
//           }

//           val1 = nums[i];
//           val2 = nums[j];
//           val3 = nums[k];

//         }
//         return false;
//       }
//   };



class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
          if (nums.size() <= 2) {
            return false;
          }
  
          int val1 = INT_MAX;
          int val2 = INT_MAX;

          for (int x = 0; x < nums.size(); x++) {
            int value = nums[x];

            if (value > val2) {
              return true;
            } else if (value < val1) {
              val1 = value;
            } else if (value < val2 & value > val1) {
              val2 = value;
            }
          }
          return false;

        }
    };

int main() {
  Solution solution;

  // Example test cases with different inputs
  vector<vector<int>> test_cases = {

    {1,0,5,0,4,1,3},
    // {1,2,3,4,5},
    {5,4,3,2,1},
    {2,1,5,0,4,6},

  };

  // Process each test case
  for (auto& test_case : test_cases) {
      bool result = solution.increasingTriplet(test_case);

      // Output the result for the current test case
      cout << "Input: ";
      for (int num : test_case) {
          cout << num << " ";
      }
      cout << "\nResult: ";
      cout << result << " ";
      cout << "\n\n";
  }

  return 0;
};