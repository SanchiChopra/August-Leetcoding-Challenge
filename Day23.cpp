/* QUESTION: Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
*/

class StreamChecker {
public:
    struct TreeNode{
        vector<TreeNode *> nodes;
        bool isword;
        TreeNode(){
            nodes = vector<TreeNode *>(26,NULL);
            isword = false;
        }
    };
    
    TreeNode *root;
    string build;
    
    void insert(vector<string>& words)
    {
        for(string &s : words)
        {
            reverse(s.begin(),s.end());
            TreeNode *temp = root;
            for(char c : s)
            {
                if(!temp->nodes[c-'a']) temp->nodes[c-'a'] = new TreeNode();
                temp = temp->nodes[c-'a'];
            }
            temp->isword = true;
        }
    }
    
    StreamChecker(vector<string>& words) {
        root = new TreeNode();
        build = "";
        insert(words);
    }
    
    bool query(char letter) {
        build += letter;
        TreeNode *temp = root;
        for(int i=build.size()-1; i>=0 && temp; i--)
        {
            temp = temp->nodes[build[i]-'a'];
            if(temp && temp->isword)
            {
                return true;
            }
        }
        return false;
    }
};
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
