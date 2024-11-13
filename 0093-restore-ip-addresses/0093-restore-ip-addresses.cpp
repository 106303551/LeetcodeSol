class Solution {
private:
    vector<string> results;
    vector<string> vec_result;
    string result;
    string candidate;
    int candidateNum;
    void backtracking(string s, int startIndex){
        //已經分成四段
        if(vec_result.size() == 4){
            if(startIndex == s.size()){
                result = "";
                for(int i = 0;i<vec_result.size();i++){
                    result+=vec_result[i];
                    result+=".";
                }
                //最後的點去掉
                result.pop_back();
                results.push_back(result);
            }
            return;
        }
        for(int i = startIndex;i<s.size() && i+1-startIndex<=3;i++){
            //長度為2之後check是否開頭為0
            if(i+1-startIndex>1 && s[startIndex]=='0'){
                break;
            }
            candidate = s.substr(startIndex,i+1-startIndex);
            candidateNum = std::stoi(candidate);
            //candidate過大
            if(candidateNum>255){
                continue;
            }
            vec_result.push_back(candidate);
            backtracking(s,i+1);
            vec_result.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0);
        return results;
        
    }
};