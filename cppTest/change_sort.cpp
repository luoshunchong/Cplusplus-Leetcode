#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

void printArray(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] ;
    }
    cout << endl;
}

void printArray2(vector<vector<int>> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << "(" ;
        for (int j = 0; j < nums[0].size(); ++j) {
            cout << nums[i][j] ;
        }
        cout << ")" ;
    }
    cout << endl;
}

static bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    else return a[0] < b[0];
}

void Sort(vector<int> nums) {
    cout << "sort默认升序" << endl;
    sort(nums.begin(), nums.end());
    printArray(nums);

    cout << "sort默认升序less<int>()" << endl;
    sort(nums.begin(), nums.end(), less<int>() );
    printArray(nums);

    cout << "sort更改降序greater<int>()" << endl;
    sort(nums.begin(), nums.end(), greater<int>() );
    printArray(nums);

    cout << "sort自定义排序方式" << endl;
    vector<vector<int>> temp = {{2,3}, {5,6}, {0,2}, {2,4}};
    sort(temp.begin(), temp.end(), cmp);
    printArray2(temp);
}

struct cmp1 {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) { // 注意这个地方必须加const
        if (a.first == b.first) return a.second < b.second;
        else return a.first < b.first; 
    }
};

void Set() {
    cout << "set默认升序" << endl;
    set<int> set1;

    for(int i = 0; i < 10; ++i) {
		set1.insert(rand() % 10); //插入随机元素
	}

    for (auto a : set1) {
        cout << a ;
    }
    cout << endl;

    cout << "set默认升序less<int>" << endl;
    set<int, less<int> > set2;

    for(int i = 0; i < 10; ++i) {
		set2.insert(rand() % 10); //插入随机元素
	}

    for (auto a : set2) {
        cout << a ;
    }
    cout << endl;

    cout << "set更改降序greater<int>" << endl;
    set<int, greater<int> > set3;

    for(int i = 0; i < 10; ++i) {
		set3.insert(rand() % 10); //插入随机元素
	}

    for (auto a : set3) {
        cout << a ;
    }
    cout << endl;

    cout << "set自定义排序" << endl;
    set<pair<int, int>, cmp1> set4;
    set4.insert(pair<int, int>(2, 3));
    set4.insert(pair<int, int>(5, 2));
    set4.insert(pair<int, int>(9, 0));
    set4.insert(pair<int, int>(5, 7));

    for (auto a : set4) {
        cout << "(" << a.first << "," << a.second << ")" ;
    }
    cout << endl;
}

struct cmp3 {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second > b.second; //注意方向，< 大顶堆（降序）；> 小顶堆（升序）。
        return a.first > b.first;
    }
};


void P_ueue() {
    cout << "优先队列默认大顶堆" << endl;
    priority_queue<int> p1;

    for(int i = 0; i < 10; ++i) {
		p1.push(rand() % 10); //插入随机元素
	}

    while (!p1.empty()) {
        cout << p1.top() ;
        p1.pop();
    } 
    cout << endl;

    cout << "优先队列默认大顶堆less<int>" << endl;
    priority_queue<int, vector<int>, less<int> > p2;

    for(int i = 0; i < 10; ++i) {
		p2.push(rand() % 10); //插入随机元素
	}

    while (!p2.empty()) {
        cout << p2.top() ;
        p2.pop();
    } 
    cout << endl;

    cout << "优先队列更改小顶堆greater<int>" << endl;
    priority_queue<int, vector<int>, greater<int> > p3;

    for(int i = 0; i < 10; ++i) {
		p3.push(rand() % 10); //插入随机元素
	}

    while (!p3.empty()) {
        cout << p3.top() ;
        p3.pop();
    } 
    cout << endl;

    cout << "优先队列自定义排序" << endl;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp3> p4;

    p4.push(pair<int, int>(2, 4));
    p4.push(pair<int, int>(4, 8));
    p4.push(pair<int, int>(4, 3));
    p4.push(pair<int, int>(9, 8));

    while (!p4.empty()) {
        cout << "(" << p4.top().first << "," << p4.top().second << ")" ;
        p4.pop();
    } 
    cout << endl;

}

int main() {
    vector<int> nums = {2, 4, 1, 8, 5};
    //sort方法
    Sort(nums);

    cout << "---------------------------" << endl;

    //set方法
    Set();

    cout << "---------------------------" << endl;

    //优先队列
    P_ueue();

}

