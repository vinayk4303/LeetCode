class Solution {
public:
    bool isPalindrome(int x) {
        long long y = x;
        long long rev = 0;
        while(x > 0){
            
            rev = rev * 10 + x % 10;
            x/=10;
        }
        if (rev == y){
            return true;
        }
        else{
            return false;
        }
    }
    
};