class Solution {
public:
    //思路：
    //      1.相較於左邊的小孩一定符合規則
    //      2.相較於右邊的小孩一定符合規則(同時確保一定大於1.得到的數量)
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        int result = 0;
        for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
        return result;
    }
};