#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int> rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << " ";
    }
    cout << endl;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> count;
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        if(count.find(nums[i]) != count.end()) {
            count[nums[i]]++;
        } else {
            count[nums[i]] = 0;
        }
    }
    vector<int> rsl;
    priority_queue<pair<int, int> > pq;
    map<int, int>::iterator it;
    for(it = count.begin(); it != count.end(); it++) {
        pq.push(make_pair(it->second, it->first));
        if(pq.size() > count.size() - k) {
            rsl.push_back(pq.top().second);
            pq.pop();
        }
    }
    return rsl;
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(4);
    int k = 2;
    print(topKFrequent(nums, k));
}