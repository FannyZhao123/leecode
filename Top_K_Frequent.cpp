typedef pair<int,string> pis;

struct mycompare {
    bool operator() (const pis& a, const pis& b) {
        if(a.first==b.first) {
            return a.second < b.second;
        }
            return a.first > b.first;
        }
};

vector<string> topKFrequent(vector<string>& reviews, vector<string>&keywords, int k) {
    unordered_set<string> keyword(keywords.begin(), keywords.end());
    unordered_map<string,int> count;
    priority_queue<pis,vector<pis>,mycompare> pq;
    vector<string> result;
    
    for(string review : reviews) {
        string s;
        stringstream ss(review);
        unordered_set<string> words;
        while(getline(ss,s,' ')) {
            transform(s.begin(),s.end(),s.begin(),::tolower);
            if(keyword.find(s) != keyword.end()) {
                words.insert(s);
            }
        }
        for(auto it : words) {
            count[it]++;
        }
    }
    
    for(auto it : count) {
        pq.push(make_pair(it.second, it.first));
        if(pq.size() > k) {
            pq.pop();
        }
    }
    while(!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    
    reverse(result.begin(),result.end());
    return result;
}