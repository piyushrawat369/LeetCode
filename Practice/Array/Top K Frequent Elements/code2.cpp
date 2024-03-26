class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]] = map[arr[i]] + 1;
        }

        vector<int> list;
        for (const auto& entry : map) {
            list.push_back(entry.second);
        }

        sort(list.begin(), list.end(), greater<int>());

        vector<int> list2(list.begin(), list.begin() + k);

        vector<int> ans(list2.size(), 0);
        int j = 0;
        for (const auto& entry : map) {
            if (find(list2.begin(), list2.end(), entry.second) != list2.end()) {
                ans[j++] = entry.first;
            }
        }

        return ans;
    }
};
