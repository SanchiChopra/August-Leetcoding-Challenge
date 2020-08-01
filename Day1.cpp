/* QUESTION: Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int comp = (int)(word[1]);
        if(comp >= 65 && comp <= 90) {
            if(word[0] < 65 || word[0] > 90)
                return false;
            for(int i=2; i< n; i++) {
                if(word[i] < 65 || word[i] > 90)
                    return false;
            }
        }
        else {
            for(int i=2; i<n; i++) {
                if(word[i] < 97 || word[i] >122)
                    return false;
            }
        }
        return true;
    }
};
