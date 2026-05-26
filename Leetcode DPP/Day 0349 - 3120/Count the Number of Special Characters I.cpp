class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> arr(100, 0);
        for(int i=0; i<word.size(); i++) {
            arr[word[i]-'A']++;
        }   
        int c=0;
        for(int i=0; i<26; i++) {
            if(arr[i]&&arr[i-'A'+'a']) c++;
        }
        return c;
    }
};