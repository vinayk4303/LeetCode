class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        while ( left < right){
            int current = numbers[left] + numbers[right];
            if (current == target){
                return{left + 1, right + 1};
            }
            else if ( current < target ){
                left ++;
            }
            else{
                right--;
            }
        }
        return{};
    }
};