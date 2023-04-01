//Approach-3: BFS

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> q;
        q.push(0);

        unordered_set<string> myset;
        unordered_set<int> visited;

        for(auto word: wordDict)
            myset.insert(word);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(!visited.count(curr)){
                visited.insert(curr);
                string temp = "";

                for(int start=curr; start<s.size(); start++){
                    temp.push_back(s[start]);
                    if(myset.count(temp)){
                        q.push(start+1);
                        if(start == s.size()-1)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
