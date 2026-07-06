class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        sort(nums1.begin(),nums1.end());
        int j = 0;
        sort(nums2.begin(),nums2.end());
        vector<int>vec;
        while( i < nums1.size() && j < nums2.size()){
            if ( nums1[i] < nums2[j] ){
                i++;
            }
            else if (nums2[j] < nums1[i]){
                j++;
            }
            else{
                if(vec.empty () || vec.back() != nums1[i]){
                    vec.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return vec;
        
    }
};