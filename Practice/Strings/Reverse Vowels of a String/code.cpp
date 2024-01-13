class Solution {
public:
    string reverseVowels(string s) {
        int i=0; 
        int j=s.length();
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while(i < j){
            if(st.find(s[i]) != st.end()){
                if(st.find(s[j]) != st.end()){
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
                else{
                    j--;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};
