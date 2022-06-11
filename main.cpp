#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol300;

/* Example 1:
Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101],
therefore the length is 4.

*/
tuple<vector<int>, int>
testFixture1()
{
  auto input = vector<int>{10, 9, 2, 5, 3, 7, 101, 18};
  return make_tuple(input, 4);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.lengthOfLIS(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture1();
  cout << "Test 2 - exepct to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.lengthOfLIS2(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}