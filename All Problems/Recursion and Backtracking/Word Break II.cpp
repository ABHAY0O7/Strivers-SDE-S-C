#include <bits/stdc++.h> 

void f(int i, string & s, string & temp, vector<string>& ans, unordered_map<string,bool>& m){
    if(i==s.length()){
        ans.push_back(temp);
        return;
    }
    for(int ind = i; ind<s.length(); ind++){
            int sz = temp.size();
            if(m[s.substr(i,(ind-i+1))]){
            temp.append(s.substr(i,(ind-i+1)));
            temp.push_back(' ');
            f(ind+1,s,temp,ans,m);
            int szn = temp.size();
            while(szn!=sz) {
                temp.pop_back();
                szn--;
            }
        }
    }

}

vector<string> wordBreak(string &s, vector<string> &dic)

{
    unordered_map<string,bool> m;
    for(auto i: dic) m[i] = true;
    vector<string> ans;
    string temp;
    f(0,s,temp,ans,m);
    return ans;

 

}


