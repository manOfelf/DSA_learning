class Solution {
public:
    char findTheDifference(string s, string t) {
        int diff = 0;
        for(int i = 0; i < s.length() ; i++)
        {
            diff = diff + s[i] - t[i];
        }
        diff = diff + t[ s.length() ];
        
        char c = ( char ) diff;
        return c;
        
    }
};
