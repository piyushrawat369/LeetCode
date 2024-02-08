class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ch: s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto [ch, freq] : mp){
            pq.push({freq, ch});
        }

        string res;
        pair<int, char> cur;
        while(!pq.empty()){
            cur = pq.top();
            pq.pop();
            res += string(cur.first, cur.second);
        }
        return res;
    }
};
