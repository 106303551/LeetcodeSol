class Solution {
public:
    //思路：掌握每一段上漲
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if(prices.size() == 1)return result;

        for(int i = 0;i<prices.size()-1;i++){
            if(prices[i+1]-prices[i]>0){
                result+=(prices[i+1]-prices[i]);
            }
        }
        return result;
    }
};