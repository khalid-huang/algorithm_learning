#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> small, large; // small store the small half; and largestore the large half; use the negative to store the large half; 
public:
    MedianFinder() {

    }
    void addNum(int num) {
        //sure that the small has the small half and the large has the large half
        small.push(num);
        large.push(-small.top());
        small.pop();
        // sure that the size of this tow queue
        if(large.size() > small.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() * 1.0 : (small.top() * 1.0 - large.top() * 1.0) / 2;
    }
};

int main() {
    MedianFinder obj;
    obj.addNum(1);
    obj.addNum(2);
    cout << obj.findMedian() << endl;
    obj.addNum(3);
    cout<< obj.findMedian() << endl;
}