//就是一个简单的浓度优先搜索; 使用java的优先级队列来做会好(因为c++的优先级队列是降序的)
#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

map<string, priority_queue<string> routes;
vector<string> path;

void print(vector<string> itinerary) {
    int size = itinerary.size();
    for(int i = 0; i < size; i++) {
        cout << itinerary[i] << " ";
    }
    cout << endl;
}

void printQueue(priority_queue<string> q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}


void dfs(string position) {
    cout << position << endl;
    path.push_back(position);
    priority_queue<string>* arrival = &routes[position]; //这里要取指针
    while(!arrival->empty()) {
        string tmp = arrival->top();
        arrival->pop();
        dfs(tmp);
    }
}

vector<string> findItinerary(vector<pair<string, string> > tickets) {
    int size = tickets.size();
    for(int i = 0; i < size; i++) {
        if(routes.find(tickets[i].first) == routes.end()) {
            routes.insert(pair<string, priority_queue<string> >(tickets[i].first, priority_queue<string>()));
        }
        routes[tickets[i].first].push(tickets[i].second);
    }
    printQueue(routes["JFK"]);
    cout << "dfs" << endl;
    // dfs("JFK");
    return path;
}


int main() {
    vector<pair<string, string> > tickets;
    tickets.push_back(make_pair("JFK", "SFO"));
    tickets.push_back(make_pair("JFK", "ATL"));
    tickets.push_back(make_pair("SFO", "ATL"));
    tickets.push_back(make_pair("ATL", "JFK"));
    tickets.push_back(make_pair("ATL", "SFO"));
    print(findItinerary(tickets));
}