/* QUESTION: Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
*/

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.size();
        int numCombinations = 1 << n;

        for ( int i = numCombinations - 1; i >= 0; --i ) {
            // Get combination string when number of bits is same as <combinationLength>
            if ( countBits( i ) == combinationLength ) {
                string str = getCombination( i, characters );
                l.push_front( str );
            }
        }
    }
    
    string next() {
        string res = l.back();
        l.pop_back();
        return res;
    }
    
    bool hasNext() {
        return l.size() > 0;
    }
    
    int countBits( int num ) {
        int res = 0;
        while ( num ) {
            num = num & ( num - 1 );
            res++;
        }
        return res;
    }
    
    string getCombination( int mask, string characters ) {
        int charIndex = characters.size() - 1;
        string res;
        
        while ( mask ) {
            if ( mask & 1 ) {
                res.insert( res.begin(), characters[charIndex] );
            }
            mask = mask >> 1;
            --charIndex;
        }
        
        return res;
    }
private:
    list<string> l;
};
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
