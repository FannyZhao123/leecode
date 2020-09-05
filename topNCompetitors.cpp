// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <bits/stdc++.h>

using namespace std; 

typedef pair<int,string> pis;

struct compare{
    bool operator()(const pis& a, const pis& b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

vector<string> topNCompetitors(int numCompetitors, int topNCompetitors, 
							   vector<string> competitors, 
							   int numReviews,
							   vector<string> reviews)
{
    /*
    1.num of competitors -- sizeof competitors
    2.top x competitors
    3.competitors list
    4.num of reviews -- sizeof reviews
    5.list of reviews
    */
    /*
    1. case-insensitive
    2. result only contain the competitors in reviews
    3. mutil in one review --> one review 
    4. same count, alphabetically
    */
    unordered_set<string>competitor (competitors.begin(), competitors.end());
    unordered_map<string, int> count;
    vector<string> result;
    priority_queue<pis,vector<pis>,compare> pq;
    for(string review :reviews){
        unordered_set<string> words;
        string s;
        stringstream ss (review);
        while(getline(ss,s,' ')){
            transform(s.begin(),s.end(),s.begin(),::tolower);
            if(competitor.find(s) != competitor.end()){
                words.insert(s);
            }
        }
        for (auto w:words){
            count[w]++;
        }
    }
    for (auto i:count){
        pq.push(make_pair(i.second, i.first));
        if(pq.size() > topNCompetitors) pq.pop();
    }
    while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }
    reverse (result.begin(), result.end());
    return result;
    
}
// FUNCTION SIGNATURE ENDS