/* QUESTION: A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
 
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
 
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

 

Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
*/

class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='A'|| c=='I' || c=='E' || c=='O' || c=='U' || c=='a' || c=='i' || c=='o' || c=='u' || c=='e')
        {
            return true;
        }
        return false;
    }
    string toGoatLatin(string S) {
        stringstream s(S); 
        string word,ans;
        int i=1; // to keep count of index
        while(s>>word)   // read word by word
        {
             if(isvowel(word[0]))  // if vowel just add ma to the word
             {
                 word+="ma";
             }
            else  // else add 1st char and ma
            {
                char ch=word[0];
                word=word.substr(1) + ch + "ma";
            }
            for(int j=0;j<i;j++)  // adding a = no of index
            {
                word+='a';
            }
        i++;
            ans+= word+" ";  // add  every word to the ans
            
        }
        ans.pop_back();  // pop the last char as it will be an extra space
        return ans;
        
    }
};
