/* QUESTION: Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.length()-1,i=0;
        while(i<=j){
            while(i<j&&!isalpha(s[i])&&!isdigit(s[i]))i++;
            while(i<j&&!isalpha(s[j])&&!isdigit(s[j]))j--;
            if(tolower(s[i])==tolower(s[j]))i++,j--;
            else return false;
        }
        return true;
    }
};
