//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    unordered_map<string, unordered_set<string>> adj;
    unordered_map<string, int> visited;
    vector<vector<string>> ans;
    
    vector<string> path;
    
    void dfs(string &startWord, string &endWord){
        if(startWord == endWord){
            path.push_back(endWord);
            reverse(begin(path), end(path));
            ans.push_back(path);
            reverse(begin(path), end(path));
            path.pop_back();
            return;
        }
        
        path.push_back(startWord);
        for(string child: adj[startWord]){
            dfs(child, endWord);
        }
        path.pop_back();
    }

    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wl(begin(wordList), end(wordList));
        
        visited[beginWord] = 0;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            
            for(int i=0; i<cur.size(); i++){
                string temp = cur;
                
                for(int ch='a'; ch <= 'z'; ch++){
                    temp[i] = ch;
                    if(temp == cur) continue;
                    
                    if(wl.count(temp)){
                        if(!visited.count(temp)){
                            visited[temp] = 1 + visited[cur];
                            adj[temp].insert(cur);
                            q.push(temp);
                        }
                        else if(visited[temp] == 1 + visited[cur]){
                            adj[temp].insert(cur);
                        }
                    }
                }
            }
        }
        dfs(endWord, beginWord);
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends
