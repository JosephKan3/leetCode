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

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Layer {
  TreeNode* LCA = nullptr;
  bool found_p = false;
  bool found_q = false;
};

class DFS {
  public:
    Layer traverse(TreeNode* curr, TreeNode* p, TreeNode* q) {
      Layer output = Layer();

      if (curr == nullptr) {
        return output;
      }

      Layer left_output = traverse(curr->left, p, q);
      Layer right_output = traverse(curr->right, p, q);

      if (left_output.LCA) {
        output.LCA = left_output.LCA;
        output.found_p = true;
        output.found_q = true;
        return output;
      }
      if (right_output.LCA) {
        output.LCA = right_output.LCA;
        output.found_p = true;
        output.found_q = true;
        return output;
      }

      if (left_output.found_p | right_output.found_p | curr == p) {
        output.found_p = true;
      }
      if (left_output.found_q | right_output.found_q | curr == q) {
        output.found_q = true;
      }

      if (output.found_p & output.found_q) {
        output.LCA = curr;
      }

      return output;
    }
};

class Solution {
  public:
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        DFS dfs = DFS();
        Layer output = dfs.traverse(root, p, q);
        return output.LCA;
      }
  };


// Function to construct a tree from a level-order list representation
TreeNode *constructTree(const vector<string> &nodes)
{
  if (nodes.empty() || nodes[0] == "null")
    return nullptr;

  TreeNode *root = new TreeNode(stoi(nodes[0]));
  queue<TreeNode *> q;
  q.push(root);
  int i = 1;

  while (!q.empty() && i < nodes.size())
  {
    TreeNode *current = q.front();
    q.pop();

    if (i < nodes.size() && nodes[i] != "null")
    {
      current->left = new TreeNode(stoi(nodes[i]));
      q.push(current->left);
    }
    i++;

    if (i < nodes.size() && nodes[i] != "null")
    {
      current->right = new TreeNode(stoi(nodes[i]));
      q.push(current->right);
    }
    i++;
  }

  return root;
}

// Convert string input to vector<string>
vector<string> parseTreeInput(const string &input)
{
  vector<string> result;
  stringstream ss(input.substr(1, input.size() - 2)); // Remove brackets
  string token;
  while (getline(ss, token, ','))
  {
    result.push_back(token);
  }
  return result;
}

struct TestCase
{
  string treeInput;
  TreeNode* p;
  TreeNode* q;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
      {"[3,5,1,6,2,0,8,null,null,7,4]", new TreeNode(5), new TreeNode(1)},
      {"[3,5,1,6,2,0,8,null,null,7,4]", new TreeNode(5), new TreeNode(4)},
      {"[1,2]", new TreeNode(1), new TreeNode(2)},
  };

  for (const auto &test_case : test_cases) {
    vector<string> nodes = parseTreeInput(test_case.treeInput);
    TreeNode* root = constructTree(nodes);

    TreeNode* result = solution.lowestCommonAncestor(root, test_case.p, test_case.q);
    cout << "Input: " << test_case.treeInput << ", p: " << test_case.p->val << ", q: " << test_case.q->val;
    cout << "\nResult: " << result->val << "\n\n";
  }

  return 0;
}