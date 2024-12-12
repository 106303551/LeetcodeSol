class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff;
        int total_gas = 0;
        int cur_gas = 0;
        int start = 0;

        for(int i =0;i<gas.size();i++){
            diff = gas[i]-cost[i];
            total_gas+=diff;
            cur_gas+=diff;
            if(cur_gas<0){
                start = i+1;
                cur_gas = 0;
            }
        }
        if(total_gas>=0)return start;
        return -1;
    }
};