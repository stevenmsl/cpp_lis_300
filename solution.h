#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol300
{

  class Solution
  {
  private:
  public:
    int lengthOfLIS(vector<int> &nums);
    int lengthOfLIS2(vector<int> &nums);
  };
}
#endif