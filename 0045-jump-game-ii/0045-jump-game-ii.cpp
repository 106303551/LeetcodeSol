class Solution {
public:
    //思路：跳到能到達最遠位置的格子
    int jump(vector<int>& nums) {
        int Des = nums[0];
        int NewDes = nums[0];
        int NowIndex = 0;
        int result = 1;
        if(nums.size() == 1)return 0;

        while(Des<nums.size()-1){
            result++;
            for(int i = NowIndex;i<=Des;i++){
                if(NewDes<i+nums[i]){
                    NewDes = i+nums[i];
                    NowIndex = i;
                }
            }
            Des = NewDes;
        }

        return result;
    }
};