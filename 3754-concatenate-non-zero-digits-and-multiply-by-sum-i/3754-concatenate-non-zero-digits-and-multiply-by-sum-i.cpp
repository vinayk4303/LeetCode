class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long place = 1;
        long long number = 0;
        while(n > 0){
            int digit = n % 10;
            if (digit != 0 ){
                number += digit * place;
                place *= 10;
                sum += digit;
            }
            n /= 10;
        }
        return number * sum;
    }
};