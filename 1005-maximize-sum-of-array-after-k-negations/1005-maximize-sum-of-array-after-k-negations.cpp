class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size() && k>0;i++){
            if(nums[i]<=0){
                nums[i] = -nums[i];
                k--;
            }else{
                break;
            }
        }
        //如果還有次數
        if(k%2==1){
            std::sort(nums.begin(),nums.end());
            nums[0] = -nums[0];
        }
        return std::accumulate(nums.begin(),nums.end(),0);
    }
};