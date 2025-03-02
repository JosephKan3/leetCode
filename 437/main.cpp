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

class DFS {
  public:
    int match_count = 0;
    DFS() {};
    void traverse(TreeNode* curr, stack<TreeNode*> traversed_stack, vector<int> path_vals, long full_sum, int targetSum) {
      if (curr == nullptr) {
        return;
      }

      long curr_path_sum = full_sum;
      for (auto path_val : path_vals) {
        if (curr_path_sum + curr->val == targetSum) {
          match_count++;
        }
        curr_path_sum -= path_val;
      }
      if (curr_path_sum + curr->val == targetSum) {
        match_count++;
      }


      full_sum += curr->val;
      path_vals.push_back(curr->val);
      traversed_stack.push(curr);

      traverse(curr->left, traversed_stack, path_vals, full_sum, targetSum);
      traverse(curr->right, traversed_stack, path_vals, full_sum, targetSum);

      traversed_stack.pop();
      path_vals.pop_back();
      return;
    }
};

class Solution
{
public:
  int pathSum(TreeNode *root, int targetSum)
  {
    stack<TreeNode*> traversed_stack;
    DFS dfs = DFS();
    dfs.traverse(root, traversed_stack, {}, 0, targetSum);
    return dfs.match_count;
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
  int targetSum;
};

int main()
{
  Solution solution;
  vector<TestCase> test_cases = {
      {"[10,5,-3,3,2,null,11,3,-2,null,1]", 8},
      {"[5,4,8,11,null,13,4,7,2,null,null,5,1]", 22},
  };

  for (const auto &test_case : test_cases) {
    vector<string> nodes = parseTreeInput(test_case.treeInput);
    TreeNode *root = constructTree(nodes);

    int result = solution.pathSum(root, test_case.targetSum);
    cout << "Input: " << test_case.treeInput << ", TargetSum: " << test_case.targetSum;
    cout << "\nResult: " << result << "\n\n";
  }

  return 0;
}