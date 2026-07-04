class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map <int,int>mp ;
        for (int i = 0 ; i < n; i++){
            int more_needed = target - nums[i];
            if(mp.find(more_needed) != mp.end()){
                return {mp[more_needed],i};
            }
            mp[nums[i]] = i;
        }
        return{};
    }   
};