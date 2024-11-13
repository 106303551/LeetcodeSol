class Solution {
private:
    vector<vector<string>> results;
    vector<string> result;
    string candidate;
    //判斷回文
    bool isPalindrome(string s){
        if(s.size()==1)return true;
        for(int i = 0; i<s.size()/2 ; i++){
            if(s[i]!=s[s.size()-i-1]){
                return false;
            }
        }        
        return true;
    }
    void backtracking(string s, int startIndex){
        //判斷是否到最後
        if(startIndex == s.size()){
            results.push_back(result);
            return;
        }
        for(int i = startIndex;i<s.size();i++){
            //從start位置到i形成candidate
            candidate = s.substr(startIndex,i-startIndex+1);
            if(!isPalindrome(candidate)){
                continue;
            }
            result.push_back(candidate);
            backtracking(s,i+1);
            result.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return results;
    }
};