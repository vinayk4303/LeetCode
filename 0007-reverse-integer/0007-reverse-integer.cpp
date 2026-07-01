class Solution {
public:
    int reverse(int x) {
       
        long long n = abs(static_cast<long long>(x));
        
        
        long long rev = 0; 
        
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        
        
        if (rev > INT_MAX) {
            return 0;
        }
        
        
        if (x < 0) {
            rev = -rev;
        }
        
        return rev;
    }
};