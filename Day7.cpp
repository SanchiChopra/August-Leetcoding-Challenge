/* QUESTION: Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

 

Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation: 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "[1,5,6]", the node value of 5 comes first since 5 is smaller than 6.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        
        map<pair<int, int>, set<int>> map;
        int maxValue = INT_MIN;
        int minValue = INT_MAX;
        dfs(map, root, 0, 0, maxValue, minValue);
        vector<vector<int>> result(maxValue - minValue + 1);
        for (const auto& pair : map) {
            int index = pair.first.first - minValue;
            result[index].insert(result[index].end(), pair.second.begin(), pair.second.end());
        }
        return result;
    }
    
    void dfs(map<pair<int, int>, set<int>>& map, TreeNode* root, int x, int y, int& maxValue, int& minValue) {
        if (root == NULL) {
            return;
        }
        map[{x, y}].insert(root->val);
        maxValue = max(maxValue, x);
        minValue = min(minValue, x);
        dfs(map, root->left, x - 1, y + 1, maxValue, minValue);
        dfs(map, root->right, x + 1, y + 1, maxValue, minValue);
    }

};
