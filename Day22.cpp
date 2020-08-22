/* QUESTION: Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Note:

An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.
Example 1:

Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]
Example 2:

Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
*/

class Solution {
public:
    vector<int> np;
    vector<vector<int>> Rects;
    Solution(vector<vector<int>>& rects) {
        Rects = rects;
        for(auto rect : rects){
            int l1 = rect[2] - rect[0] + 1;
            int l2 = rect[3] - rect[1] + 1;
            int val = np.size() ? np.back() + (l1*l2) : l1*l2; 
            np.push_back(val);
        }
    }
    
    vector<int> pick() {
        int m = np.back();
        int r = rand() % m;
        auto it = upper_bound(np.begin(), np.end(), r);
        int rect = it - np.begin();  //end of step 1
		//step 2 begins
        vector<int> R = Rects[rect];
        int x = rand() % (R[2]-R[0]+1) + R[0];
        int y = rand() % (R[3]-R[1]+1) + R[1];
        return {x, y};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
