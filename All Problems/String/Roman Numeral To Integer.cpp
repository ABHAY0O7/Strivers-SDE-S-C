int romanToInt(string s) {
    unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int n = s.size();
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(i != n - 1 && m[s[i+1]] > m[s[i]]) ans -= m[s[i]];
        else ans += m[s[i]];
    }
    return ans;
}
