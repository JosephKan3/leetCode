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

class MinStack {
  stack<int> base;
  stack<int> min_val;
  public:
      MinStack() {
        
      }
      
      void push(int val) {
        if (min_val.size() == 0) {
          min_val.push(val);
        } else {
          min_val.push(min(min_val.top(), val));
        }
        base.push(val);
      }
      
      void pop() {
        base.pop();
        min_val.pop();
      }
      
      int top() {
        return base.top();
      }
      
      int getMin() {
        return min_val.top();
      }
  };
  
  /**
   * Your MinStack object will be instantiated and called as such:
   * MinStack* obj = new MinStack();
   * obj->push(val);
   * obj->pop();
   * int param_3 = obj->top();
   * int param_4 = obj->getMin();
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
  string input;
};

// int main()
// {
//   Solution solution;
//   vector<TestCase> test_cases = {
//     {
//       "A man, a plan, a canal: Panama"
//     },
//   };

//   for (auto &test_case : test_cases)
//   {
//     cout << "left: " << test_case.input;
//     auto result = solution.simplifyPath(test_case.input);
//     cout << "\nResult: " << (result) << "\n\n";
//   }

//   return 0;
// }