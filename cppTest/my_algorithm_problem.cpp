// #include <iostream>
// #include <vector>
// #include <string>
// #include <stack>
// #include <queue>

// using namespace std;

// class myStack {
// private:
//     vector<int> temp;
//     int index;
// public:
//     myStack(int cap) {
//         temp = vector<int>(cap);
//         index = 0;
//     }
//     void push(int x) {
//         if (index >= temp.size()) {
//             cout << "栈满，不可push" << endl;
//         }
//         else temp[index++] = x;
//     }
//     int pop() {
//         if (index == 0) {
//             cout << "栈空， 不可pop" << endl;
//             return -1;
//         }
//         else return temp[--index];
//     }
// };

// class myQueue {
// private:
//     vector<int> temp;
//     int begin;
//     int end;
//     int size;
// public:
//     myQueue(int cap) {
//         temp = vector<int>(cap);
//         begin = 0;
//         end = 0;
//         size = 0;
//     }
//     //将元素 x 推到队列的末尾
//     void push(int x) {
//         if ((size + 1) > temp.size()) {
//             cout << "队列已满，不可push" << endl;
//         }
//         else {
//             size++;
//             temp[end++] = x;
//             if (end == temp.size()) end = 0;
//         }
//     }
//     //从队列的开头移除并返回元素
//     int pop() {
//         if ((size - 1) < 0) {
//             cout << "队列空，不可pop" << endl;
//             return -1;
//         }
//         else {
//             size--;
//             int res = temp[begin++];
//             if (begin == temp.size()) begin = 0;
//             return res;
//         }
//     }
//     //返回队列开头的元素
//     int peek() {
//         if ((size - 1) < 0) {
//             cout << "队列空，不可peek" << endl;
//             return -1;
//         }
//         else return temp[begin];
//     }
//     //如果队列为空，返回 `true` ；否则，返回 `false`
//     bool isEmpty() {
//         if (size == 0) return true;
//         else return false;
//     }
// };

// int findFirstNum(vector<int>& a, vector<int>& b) {
//     int n = a.size();
//     a.insert(a.end(), b.begin(), b.end());
//     stack<int> st;
//     int maxnum = INT_MIN;
//     int res = -1;
//     int index;
//     for (int i = 0; i < a.size(); ++i) {
//         while (!st.empty() && a[st.top()] < a[i]) { //按条件出栈
//             if (st.top() < n && maxnum < a[st.top()]) {
//                 maxnum = a[st.top()];
//                 st.pop();
//                 res = a[i];
//                 index = i;
//             }
//             else {
//                 st.pop();
//             }
//         }
//         st.push(i); //入栈
//     }
//     return index >= n ? res : -1;
// }

// int main() {
//     /*
//     数组实现栈
//     */
//     // myStack st(3);
//     // //入栈
//     // st.push(8);
//     // st.push(7);
//     // st.push(6);
//     // st.push(0);
//     // cout << st.pop() << endl;

//     /*
//     数组实现队列
//     */
//     // myQueue qu(3);
//     // //入队
//     // qu.push(2);
//     // qu.push(3);
//     // qu.push(4);
//     // qu.push(6);
//     // cout << qu.pop() << endl;
//     // cout << qu.peek() << endl;
//     // cout << qu.isEmpty() << endl;
//     /*
//     给定两个数组,在第二个数组中,找出比第一个数组每个位置大的数。
//     方法一：将两个数组排序，再遍历第二个数组，找到第一个 nums2[i] > nums1[nums1.size() - 1] 的元素返回。时间复杂度O(NlogN)。
//     方法二：将两个数组拼接起来，利用单调栈寻找右边第一个比自己最大元素大的元素。时间复杂度O(N)。
//     */
//     vector<int> nums1 = {2,3,5};
//     vector<int> nums2 = {8,1,4};
//     cout << findFirstNum(nums1, nums2) << endl;

//     /*
    
//     */

//     /*
    
//     */
//     return 0;
// }

/*
手撕：给你一个字符串 s 和一个整数 m ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 m 。返回这一子串的长度。
*/

#include <iostream>
#include <string>

using namespace std;

void check(string& s, int m) {
    
}

int main() {
    int m = 2;
    string s = "aabba";
    check(s, m);
    return 0;
}