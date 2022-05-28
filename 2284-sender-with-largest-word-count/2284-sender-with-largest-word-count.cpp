class Solution {
public:
     int countWords(string &str){
        int count = 0;
        for(char ch:str){
            if(ch == ' ') ++count;
        }
        return count+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders){
        map<string, int> mp;
        for(int i = 0; i<messages.size(); ++i){
            int count = countWords(messages[i]);
            mp[senders[i]]+=count;
        }
        string ans = "";
        int count = 0;
        for(auto it = mp.begin(); it!=mp.end(); ++it){
            if(it->second >= count){
                count = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};