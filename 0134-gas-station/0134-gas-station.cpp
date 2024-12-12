class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff;
        int total_gas;
        //total gas >= total cost
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)){
            return -1;
        }
        //選擇start Pos
        for(int i =0;i<gas.size();i++){
            total_gas = 0;
            if(gas[i]<cost[i]){
                continue;
            }
            for(int j = i;j<i+gas.size();j++){
                int nowIndex = j%gas.size();
                diff = gas[nowIndex]-cost[nowIndex];
                total_gas+=diff;
                if(total_gas<0){
                    i = j;
                    break;
                }
                if(nowIndex+1 == i){
                    return i;
                }
            }
        }
        return -1;
    }
};