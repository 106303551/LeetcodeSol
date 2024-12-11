class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int count = nums[0];
        if(nums.size() == 1) return result;

        for(int i = 1; i<nums.size(); i++){
            //如果過去count<0 不使用
            if(count<0){
                count = 0;
            }

            count+=nums[i];
            if(result<count){
                result = count;
            }
        }
        return result;
    }
};