// @algorithm @lc id=100303 lang=cpp 
// @title shu-ju-liu-zhong-de-zhong-wei-shu-lcof

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int> > A; //大顶堆
    priority_queue<int, vector<int>, greater<int> > B; //小顶堆
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (A.size() == B.size()) {
            A.push(num);
            B.push(A.top());
            A.pop();
        }
        else {
            B.push(num);
            A.push(B.top());
            B.pop();
        }
    }
    
    double findMedian() {
        if (A.size() == B.size()) {
            return double(A.top() + B.top()) / 2;
        }
        else return double(B.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */