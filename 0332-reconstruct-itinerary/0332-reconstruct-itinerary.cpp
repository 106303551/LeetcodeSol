class Solution {
private:
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result){
        if(result.size() == ticketNum+1){
            return true;
        }
        string nowPos = result.back();
        for(pair<const string, int>& target : targets[nowPos]){
            if(target.second > 0){
                result.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum, result))return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int ticketNum = tickets.size();
        vector<string> result;
        result.push_back("JFK");
        //init 機票轉換成記錄次數
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++; // 紀錄關係
        }
        backtracking(ticketNum, result);
        return result;
    }
};