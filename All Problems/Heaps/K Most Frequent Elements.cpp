vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto it : m) {
        if(pq.size() < k) pq.push({it.second, it.first});
        else if(it.second > pq.top().first) {
            pq.pop();
            pq.push({it.second, it.first});
        }
    }
    vector<int> ans;
    while(!pq.empty()) ans.push_back(pq.top().second), pq.pop();
    return ans;
}
