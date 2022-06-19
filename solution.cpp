#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm> //lower_bound
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol300;
using namespace std;

/*takeaways
 - DP
  - time complexity: O(n^2)
  - you need to find a max from the dp as dp[i]
    only stores the length of the longest subsequence
    ends at nums[i]
*/

int Solution::lengthOfLIS(vector<int> &nums)
{
  int n = nums.size();
  /*
     - dp[i] store the length of the longest
       subsequence ends at nums[i]
     - edge case: a signle number is a sorted
       subsequence
  */
  auto dp = vector<int>(n, 1);

  for (auto i = 1; i < n; i++)
    /* look at all subsequences that end before nums[i]
     */
    for (auto j = 0; j < i; j++)
      /* the subsequence needs to remain sorted after adding nums[i] */
      if (nums[i] >= nums[j])
        dp[i] = max(dp[i], dp[j] + 1);

  /* need to find the max */
  return *max_element(begin(dp), end(dp));
}

/* DP
   - time complexity O(nlogn)
   - you need a sorted array that maintains
     a list of smaller numbers
*/
int Solution::lengthOfLIS2(vector<int> &nums)
{
  /* maintain the sorted sequence  */
  auto dp = vector<int>();
  /* you can't change the order of any number
     in relation to others. You need to scan
     the input from the left to the right
  */
  for (auto i = 0; i < nums.size(); i++)
  {
    /* the first occurrence that is bigger than nums[i]
       - time complexity O(logn)
    */
    auto bigger = lower_bound(begin(dp), end(dp), nums[i]);
    if (bigger == end(dp))
      /* still sorted as I am adding
         a number bigger than anyone  */
      dp.push_back(nums[i]);
    else
      /* replace it with a smaller number
         - since we are replacing the first
           occurrence of the number that
           is bigger than the incoming
           number so the subsequence is
           still sorted
         - this keeps smaller numbers
           in dp, which increases the chance
           of accepting more numbers into
           dp
      */
      *bigger = nums[i];
  }
  return dp.size();
}
