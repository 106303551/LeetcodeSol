class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //三種幣值 5,10,20
        vector<int> moneys(3,0);
        for(int i = 0 ;i<bills.size();i++){
            if(bills[i] == 5){
                moneys[0]++;
            }else if (bills[i] == 10){
                if(moneys[0]>0){
                    moneys[0]--;
                    moneys[1]++;
                }else{
                    return false;
                }
            }else if (bills[i] == 20){
                if(moneys[0]>0 && moneys[1]>0){
                    moneys[0]--;
                    moneys[1]--;
                    moneys[2]++;
                }else if (moneys[0]>2){
                    moneys[0]-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};