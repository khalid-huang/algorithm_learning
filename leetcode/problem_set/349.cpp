#include <iostream>
#include <set>
#include <vector>

using namespace std;

void print(vector<int> rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << " ";
    }
    cout << endl;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> bucket;
    set<int> rslSet;
    int size1 = nums1.size();
    for(int i = 0; i < size1; i++) {
        bucket.insert(nums1[i]);
    }

    int size2 = nums2.size();
    for(int i = 0; i < size2; i++) {
        if(bucket.find(nums2[i]) != bucket.end()) {
            rslSet.insert(nums2[i]);
        }
    }
    vector<int> rsl;
    set<int>::iterator it;
    for(it = rslSet.begin(); it != rslSet.end(); ++it) {
        rsl.push_back(*it);
    }
    return rsl;
}

int main() {
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(1);

    nums2.push_back(2);
    nums2.push_back(4);
    nums2.push_back(3);
    nums2.push_back(0);

    print(intersection(nums1, nums2));


}