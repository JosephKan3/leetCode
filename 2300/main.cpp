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

class Solution
{
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
  {
    vector<int> output;
    sort(potions.begin(), potions.end());

    for (int i = 0; i < spells.size(); i++)
    {
      int spell_strength = spells[i];

      int left = 0;
      int right = potions.size();
      int mid = (left + right) / 2;

      while (left < right)
      {
        long long product = static_cast<long long>(potions[mid]) * spell_strength;
        if (product < success)
        {
          left = mid + 1;
        }
        else
        {
          right = mid;
        }

        mid = floor((left + right) / 2);
      }

      int success_count = potions.size() - mid;

      output.push_back(success_count);
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

struct TestCase
{
  vector<int> spells;
  vector<int> potions;
  int success;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
      {{5, 1, 3}, {1, 2, 3, 4, 5}, 7},
      {{3, 1, 2}, {8, 5, 8}, 16},
  };

  for (auto &test_case : test_cases)
  {
    vector<int> result = solution.successfulPairs(test_case.spells, test_case.potions, test_case.success);
    cout << "spells: " << vectorToString(test_case.spells) << ", potions: " << vectorToString(test_case.potions) << ", success: " << test_case.success;
    cout << "\nResult: " << vectorToString(result) << "\n\n";
  }

  return 0;
}