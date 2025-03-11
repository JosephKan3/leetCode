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
      vector<int> findSubstring(string s, vector<string>& words) {
        int word_size = words[0].size();
        int min_substr_size = words.size();
        
        int begin_ptr = 0;
        int end_ptr = word_size * min_substr_size;

        unordered_map<string, int> base_required_words;
        for (auto word : words) {
          base_required_words[word]++;
        }
        
        unordered_map<string, int> required_words = base_required_words;
        vector<int> outputs;


        while (end_ptr <= s.size()) {
          required_words = base_required_words;

          // For word in window
          for (int i = 0; i < min_substr_size; i++) {
            string word = s.substr(begin_ptr + i * word_size, word_size);
            required_words[word]--;
          }

          bool all_0 = true;
          for (auto& [word, count] : required_words) {
            if (count != 0) {
              all_0 = false;
            }
          }
          if (all_0) {
            outputs.push_back(begin_ptr);
          }
          begin_ptr += 1;
          end_ptr += 1;
        }

        return outputs;
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
  vector<string> arr;
  string target;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {

// {{"foo","bar"}, "barfoothefoobarman"},
// {{"bar","foo","the"}, "barfoofoobarthefoobarman"},
{{"word","good","best","good"}, "wordgoodgoodgoodbestword"},
// {{"word","good","best","word"}, "wordgoodgoodgoodbestword"},

  };

  for (auto &test_case : test_cases)
  {
    auto result = solution.findSubstring(test_case.target, test_case.arr);
    cout << "k: " << vectorToString(test_case.arr) << "target: " << test_case.target;
    cout << "\nResult: " << vectorToString(result) << "\n\n";
  }

  return 0;
}