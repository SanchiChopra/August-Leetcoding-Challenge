/* QUESTION: Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long dp[rowIndex+1][rowIndex+1];
        int i,j;
        for(i=0; i<=rowIndex; i++)
            dp[0][i]=1;
        for(i=0; i<=rowIndex; i++)
            dp[i][0]=1;
        for(i=1; i<=rowIndex; i++) {
            for(j=1; j<=rowIndex; j++) 
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        i = rowIndex;
        j=0;
        vector<int> ans;
        while(i>=0 && j<=rowIndex) {
            ans.push_back(dp[i][j]);
            i--;
            j++;
        }
        return ans;
    }
};
