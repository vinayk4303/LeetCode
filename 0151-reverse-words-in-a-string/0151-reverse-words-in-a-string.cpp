class Solution {
public:
    string reverseWords(string s) {
        string s2 = "";
        string s3 = "";
        int n = s.size();
        for(int i = n -1; i >=0; --i){

            if (s[i] != ' '){
                s2.push_back(s[i]);

            }
            else if ( !s2.empty()) {
                reverse(s2.begin(),s2.end());

                if ( !s3.empty()){
                    s3.push_back(' ');
                }
                s3 += s2;
                s2.clear();
            }
            
        }
        if (!s2.empty()) {
            reverse(s2.begin(), s2.end());
            if(!s3.empty()){
                s3.push_back(' ');
            }
            s3 += s2;
        }
        return s3;
    }
};