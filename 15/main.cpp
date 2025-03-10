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


// #define pii pair<int, int>
// #define tivp tuple<int, vector<pii>>
// class Solution {
// public:
//   vector<vector<int>> threeSum(vector<int>& nums) {
//     unordered_map<int, tivp> value_to_count_map;

//     for (int i = 0; i < nums.size(); i++) {
//       if (value_to_count_map.count(nums[i] < 0)) {
//         value_to_count_map[nums[i]] = {
//           1, {}
//         };
//       } else {
//         get<0>(value_to_count_map[nums[i]])++;
//       }
//     }

//     // Sort and remove duplicates
//     vector<int> sorted_nums = nums;
//     sort(sorted_nums.begin(), sorted_nums.end());
//     sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()), sorted_nums.end());

//     vector<int> arr = sorted_nums;
//     int ptr_one = 0;
//     int ptr_two = 1;

//     vector<vector<int>> outputs;
//     while(ptr_one < sorted_nums.size()) {
//       int val1 = sorted_nums[ptr_one];
//       int val2 = sorted_nums[ptr_two];
      
//       int required_third = -(val1 + val2);
//       int required_count = 1;
//       if (val1 == required_third) {
//         required_count++;
//       }
//       if (val2 == required_third) {
//         required_count++;
//       }

//       if (value_to_count_map.count(required_third)) {
//         tivp map_data = value_to_count_map[required_third];
//         if (get<0>(map_data) > required_count) {
//           bool already_done = false;
//           for (auto pair : get<1>(map_data)) {
//             if ((val1 == pair.first && val2 == pair.second) | (val1 == pair.second && val2 == pair.first)) {
//               already_done = true;
//             }
//           }
//           if (!already_done) {
//             outputs.push_back({val1, val2, required_third});
//             get<1>(map_data).push_back({val1, val2});
//           }
//         }
//       }



//       ptr_two++;
//       if (ptr_two >= sorted_nums.size()) {
//         ptr_one++;
//         ptr_two = ptr_one + 1;
//       }

//     }

//     return outputs;
//   }
// };

class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> output;
        for (int i = 0; i < nums.size() - 2; i++) {
          int ptr1 = i + 1;
          int ptr2 = nums.size() - 1;

          if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
            continue;
          }


          while (ptr1 < ptr2) {
            if (ptr1 - 1 > i && nums[ptr1 - 1] == nums[ptr1]) {
              ptr1++;
              continue;
            }
            if (ptr2 + 1 < nums.size() - 1 && nums[ptr2 + 1] == nums[ptr2]) {
              ptr2--;
              continue;
            }


            int sum = nums[i] + nums[ptr1] + nums[ptr2];

            if (sum == 0) {
              output.push_back({nums[i], nums[ptr1], nums[ptr2]});
              ptr1++;
            } else if (sum < 0) {
              ptr1++;
            } else {
              ptr2--;
            }
          }
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
  vector<int> nums;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {

{{-1,0,1,2,-1,-4}},
{{0,1,1}},
{{0,0,0}},

  };

  for (auto &test_case : test_cases)
  {
    vector<vector<int>> result = solution.threeSum(test_case.nums);
    cout << "k: " << vectorToString(test_case.nums);
    cout << "\nResult: " << gridToString(result) << "\n\n";
  }

  return 0;
}