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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* top = l1;
        ListNode* bottom = l2;


        ListNode* curr = new ListNode();
        ListNode* prev = curr;
        ListNode* head = curr;
        bool carry = 0;
        while (top != nullptr || bottom != nullptr || carry) {
          int sum = 0;
          if (top) {
            sum += top->val;
            top = top->next;
          }
          if (bottom) {
            sum += bottom->val;
            bottom = bottom->next;
          }
          sum += carry;

          if (sum < 10) {
            carry = false;
          } else {
            carry = true;
          }

          curr->val = sum % 10;
          curr->next = new ListNode();
          prev = curr;
          curr = curr->next;
          
        }
        prev->next = nullptr;

        return head;
      }
  };

// Function to construct a tree from a level-order list representation
ListNode *constructLL(const vector<int> &nodes)
{
  if (nodes.empty())
    return nullptr;

  ListNode *root = new ListNode(nodes[0]);
  queue<ListNode *> q;
  q.push(root);
  int i = 1;

  while (!q.empty() && i < nodes.size())
  {
    ListNode *current = q.front();
    q.pop();

    if (i < nodes.size())
    {
      current->next = new ListNode(nodes[i]);
      q.push(current->next);
    }
    i++;

  }

  return root;
}

string linkedListToString(ListNode* head) {
  ostringstream oss;
  ListNode* current = head;
  while (current) {
      oss << current->val;
      if (current->next) {
          oss << " -> ";
      }
      current = current->next;
  }
  return oss.str();
}

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
  vector<int> l1;
  vector<int> l2;
};


int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
      {{2,4,3}, {5,6,4}},
      {{0}, {0}},
      {{9,9,9,9,9,9,9}, {9,9,9,9}},
  };

  for (const auto &test_case : test_cases) {
    ListNode *root1 = constructLL(test_case.l1);
    ListNode *root2 = constructLL(test_case.l2);

    ListNode* result = solution.addTwoNumbers(root1, root2);
    cout << "Input: " << "l1: " << linkedListToString(root1) << ", l2: " << linkedListToString(root2) << endl;
    cout << "\nResult: " << linkedListToString(result) << "\n\n";
  }

  return 0;
}