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


// class Solution {
//   public:
//       string decodeString(string s) {
//         string output = "";

//         string repeat_count = "";
//         string letters_to_repeat = "";
//         bool read_letters = false;
//         for (auto letter : s) {
//           if (isdigit(letter)) {
//             repeat_count += letter;
//           } else if (letter == '[') {
//             read_letters = true;
//           } else if (letter == ']') {
//             read_letters = false;
//             int repeat_count_int = atoi(repeat_count.c_str());
//             for (int i = 0; i < repeat_count_int; i++) {
//               output += letters_to_repeat;
//             }
//             letters_to_repeat = "";
//             read_letters = false;
//             repeat_count = "0";
//           } else if (read_letters) {
//             letters_to_repeat += letter; 
//           }
//           else {
//             output += letter;
//           }
//         }
//         return output;
//       }
//   };

class StackLayer {
  public:
    string repeat_count = "0";
    string letters_to_repeat = "";
};


class Solution {
  public:
    string decodeString(string s) {
      string output = "";
      stack<StackLayer> instructions;

      bool read_letters = false;
      StackLayer new_stack_layer = StackLayer();
      instructions.push(new_stack_layer);


      for (auto letter : s) {
        if (isdigit(letter)) {
          new_stack_layer.repeat_count += letter;
        } else if (letter == '[') {
          instructions.push(new_stack_layer);
          new_stack_layer = StackLayer();
        } else if (letter == ']') {
          // Assemble stack layer output
          StackLayer curr = instructions.top();
          int repeat_count_int = atoi(curr.repeat_count.c_str());
          string layer_letters = "";
          for (int i = 0; i < repeat_count_int; i++) {
            layer_letters += curr.letters_to_repeat;
          }

          // Pass data down the stack
          instructions.pop();
          instructions.top().letters_to_repeat += layer_letters;

        } else {
          instructions.top().letters_to_repeat += letter; 
        }
      }
      return instructions.top().letters_to_repeat;
    }
  };

int main() {
  Solution solution;

  // Example test cases with different inputs
  vector<string> test_cases = {
    "3[a]2[bc]",
    "3[a2[c]]",
    "2[abc]3[cd]ef"
  };

  // Process each test case
  for (auto& test_case : test_cases) {
      string result = solution.decodeString(test_case);

      // Output the result for the current test case
      cout << "Input: ";
      for (char num : test_case) {
          cout << num << "";
      }
      cout << "\nResult: ";
      cout << result << " ";
      cout << "\n\n";
  }

  return 0;
};