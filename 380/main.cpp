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
#include <random>

using namespace std;


class RandomizedSet {
  unordered_map<int, int> val_index_map;
  vector<int> nums;
  int size = 0;
  random_device rd;
  mt19937 gen;

  public:
      RandomizedSet() {
        gen = mt19937(rd());
      }

      bool in_set(int val) {
        return val_index_map.count(val) && val_index_map[val] != -1;
      }
      
      bool insert(int val) {
        if (in_set(val)) {
          return false;
        }

        if (nums.size() == size) {
          nums.push_back(val);
          size++;
          val_index_map[val] = size - 1;
        } else {
          nums[size] = val;
          val_index_map[val] = size;
          size++;
        }

        return true;
      }
      
      bool remove(int val) {
        if (!in_set(val)) {
          return false;
        }

        if (size - 1 != val_index_map[val]) {
          val_index_map[nums[size - 1]] = val_index_map[val];
          swap(nums[val_index_map[val]], nums[size - 1]);
      }

        val_index_map[val] = -1;
        size--;
        return true;
      }
      
      int getRandom() {

        uniform_int_distribution<int> dist(0, size - 1);

        return nums[dist(gen)];
      }
  };


//   /**
//    * Your RandomizedSet object will be instantiated and called as such:
//    * RandomizedSet* obj = new RandomizedSet();
//    * bool param_1 = obj->insert(val);
//    * bool param_2 = obj->remove(val);
//    * int param_3 = obj->getRandom();
//    */



struct TestCase
{
  vector<int> nums;
};

int main()
{
  RandomizedSet* test = new RandomizedSet();
  test->insert(0);
  test->insert(1);
  test->remove(0);
  test->insert(2);
  test->remove(1);
  test->getRandom();

  return 0;
}