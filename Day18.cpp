/* QUESTION: Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
*/

class Solution {
public:
    void dfs(int num, int n, int K, vector<int> &res) {
      if (n == 0) res.push_back(num);
      else {
        auto dig = num % 10;
        if (dig + K <= 9) dfs(num * 10 + dig + K, n - 1, K, res);
        if (K != 0 && dig - K >= 0) dfs(num * 10 + dig - K, n - 1, K, res);
      }
    }
vector<int> numsSameConsecDiff(int N, int K) {
      if (N == 1) return { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
      vector<int> res;
      for (auto num = 1; num <= 9; ++num) dfs(num, N - 1, K, res);
      return res;
    }
};
