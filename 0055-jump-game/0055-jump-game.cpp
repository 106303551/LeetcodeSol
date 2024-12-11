class Solution {
public:
    bool canJump(vector<int>& nums) {
        int Des = nums[0];
        int NowIndex = 0;
        int farDes = 0;
        if(nums.size() == 1)return true;

        while(Des<nums.size()-1){
            if(nums[NowIndex]==0)return false;
            for(int i =NowIndex;i<=Des;i++){
                //更新最遠距離
                if(Des<=i+nums[i]){
                    Des = i+nums[i];
                    NowIndex = i;
                    if(Des>=nums.size())return true;
                }
            }
        }
        return true;
    }
};