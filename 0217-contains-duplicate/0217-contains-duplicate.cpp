class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int x = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int y = nums.size();
        if (x != y){
            return true;
        }
        else{
            return false;
        }

    }
};