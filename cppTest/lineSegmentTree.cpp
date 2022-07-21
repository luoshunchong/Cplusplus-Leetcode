#include <iostream>
#include <vector>

using namespace std;

void build_tree(vector<int>& arr, vector<int>& tree, int start, int end, int node) {
    //递归的出口，也就是找到了叶子结点
    if (start == end) tree[node] = arr[start];
    else {
        //找到树的左子节点（2 * node)
        //找到树的右子节点（2 * node + 1)
        int left_node = 2 * node, right_node = 2 * node + 1;
        //将树进行分割然后左右递归建树
        int mid = (start + end) / 2;
        build_tree(arr, tree, start, mid, left_node);
        build_tree(arr, tree, mid + 1, end, right_node);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query(vector<int>& arr, vector<int>& tree, int start, int end, int l, int r, int node) {
    //情况一：
    if (l > end || r < start) return 0;
    if (l <= start && r >= end) return tree[node]; //情况二：
    else {
        //递归查询
        //找到树的左子节点（2 * node)
        //找到树的右子节点（2 * node + 1)
        int left_node = 2 * node, right_node = 2 * node + 1;
        int mid = (start + end) / 2;
        //将树进行分割，然后左右递归查询
        int left_num = query(arr, tree, start, mid, l, r, left_node);
        int right_num = query(arr, tree, mid + 1, end, l, r, right_node);
        return left_num + right_num;
    }
}

void update(vector<int>& arr, vector<int>& tree, int start, int end, int node, int update_idx, int val) {
    //递归出口，也就是到了叶子结点，更新其值
    if (start == end) tree[node] = arr[start] = val;
    else {
        //找到树的左子节点（2 * node)
        //找到树的右子节点（2 * node + 1)
        int left_node = 2 * node, right_node = 2 * node + 1;
        int mid = (start + end) / 2;
        //如果要更新的节点在左边
        if (update_idx <= mid) {
            update(arr, tree, start, mid, left_node, update_idx, val);
        }
        //如果要更新的节点在右边
        else {
            update(arr, tree, mid + 1, end, right_node, update_idx, val);
        }
        //注意更新当前节点
        tree[node] = tree[left_node] + tree[right_node];
    }
}

int main() {
    vector<int> arr = {93, 90, 50, 50, 1};
    vector<int> tree(2 * arr.size());
    build_tree(arr, tree, 0, arr.size() - 1, 1);
    cout << "更新前的树" ;
    for (auto t : tree) cout << t << " ";
    cout << endl;
    //更新idx = 4的值为2
    update(arr, tree, 0, arr.size() - 1, 1, 4, 2);
    cout << "更新后的树" ;
    for (auto t : tree) cout << t << " ";
    cout << endl;
    cout << "查询区间[2,4]的和为：" << query(arr, tree, 0, arr.size() - 1, 2, 4, 1);    
    return 0;
}