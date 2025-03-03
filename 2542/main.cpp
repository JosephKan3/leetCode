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


#define pii pair<int,int>

class Solution {
  public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

      vector<pii> nums1_pairs;
      vector<pii> nums2_pairs;

      // Linear
      for (int i = 0; i < nums1.size(); i++) {
        nums1_pairs.push_back({nums1[i], i});
        nums2_pairs.push_back({nums2[i], i});
      }

      // Linear
      priority_queue<pii, vector<pii>> max_heap_sums(nums1_pairs.begin(), nums1_pairs.end());
      priority_queue<pii, vector<pii>, greater<pii>> min_heap_multipliers;

      long long sum = 0;
      for (int i = 0; i < k; i++) {
        pii largest_sum_component = max_heap_sums.top();
        max_heap_sums.pop();
        sum += largest_sum_component.first;

        min_heap_multipliers.push(nums2_pairs[largest_sum_component.second]);
      }

      long long max_score = min_heap_multipliers.top().first * sum;
      while (!max_heap_sums.empty()) {
        pii largest_sum_component = max_heap_sums.top();
        max_heap_sums.pop();
        pii removed_multiplier = min_heap_multipliers.top();
        
        sum += largest_sum_component.first;
        sum -= nums1_pairs[removed_multiplier.second].first;

        min_heap_multipliers.pop();
        min_heap_multipliers.push(nums2_pairs[largest_sum_component.second]);

        max_score = max(max_score, min_heap_multipliers.top().first * sum);
      }

      return max_score;
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

struct TestCase
{
  vector<int> nums1;
  vector<int> nums2;
  int k;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
      {{1, 3, 3, 2}, {2, 1, 3, 4}, 3},
      {{4,2,3,1,1}, {7,5,10,9,6}, 1},
  };

  for (auto &test_case : test_cases)
  {
    long long result = solution.maxScore(test_case.nums1, test_case.nums2, test_case.k);
    cout << "nums1: " << vectorToString(test_case.nums1) << ", nums2: " << vectorToString(test_case.nums2) << ", k: " << test_case.k;
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}