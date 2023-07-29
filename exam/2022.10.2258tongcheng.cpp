#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
   int val;
    TreeNode* left;
    TreeNode* mid;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), mid(nullptr), right(nullptr) {};
};

TreeNode* BuildTree(vector<int>& nums) {
    if (nums.size() == 0) return nullptr;
    vector<TreeNode*> vectree(nums.size(), nullptr);
    TreeNode* root = nullptr;
    for (int i = 0; i < nums.size(); ++i) {
        TreeNode* node = nullptr;
        if (nums[i] != -1) node = new TreeNode(nums[i]);
        vectree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 3 + 3 < nums.size(); ++i) {
        if (vectree[i] != nullptr) {
            vectree[i]->left = vectree[i * 3 + 1];
            vectree[i]->mid = vectree[i * 3 + 2];
            vectree[i]->right = vectree[i * 3 + 3];
        }
    }
    return root;
}

int check(TreeNode* root) {
    if (!root) return 0;
    int sum = 0;
    queue<TreeNode*> qu;
    qu.push(root);
    int level = 1;
    while (!qu.empty()) {
        int len_size = qu.size();
        for (int i = 0; i < len_size; ++i) {
            TreeNode* p = qu.front();
            qu.pop();
            if (level & 1) sum += p->val;
            if (p->left) qu.push(p->left);
            if (p->mid) qu.push(p->mid);
            if (p->right) qu.push(p->right);
        }
        level++;
    }
    return sum;
}

int main() {
    string s;
    getline(cin, s);
    vector<int> nums;
    string t;
    for (auto& c : s) {
        if (c == ',') {
            if (t[0] != 'N') nums.push_back(stoi(t));
            else nums.push_back(-1);
            t = "";
        }
        else t.push_back(c);
    }
    if (t[0] != 'N') nums.push_back(stoi(t));
    else nums.push_back(-1);
    TreeNode* root = BuildTree(nums);
    cout << check(root) << endl;
    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int N;
//     cin >> N;
//     vector<int> nums(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> nums[i];
//     }
//     vector<int> dp(nums.size());
//     dp[0] = nums[0];
//     dp[1] = max(nums[0], nums[1]);
//     for (int i = 2; i < nums.size(); ++i) {
//         dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
//     }
//     cout << dp[nums.size() - 1] << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// int check(vector<int>& nums) {
//     int sum = 0;
//     vector<int> dp(20001, 0);
//     for (int i = 0; i < nums.size(); ++i) {
//         sum += nums[i];
//     }
//     if (sum % 2 == 1) return 0;
//     int target = sum / 2;
//     for (int i = 0; i < nums.size(); ++i) {
//         for (int j = target; j >= nums[i]; --j) {
//             dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//         }
//     }
//     if (dp[target] == target) return target;
//     else return 0;
// }

// int main() {
//     int N;
//     cin >> N;
//     vector<int> nums(N);
//     for (int i = 0; i < N; ++i) {
//         cin >> nums[i];
//     }
//     cout << check(nums) << endl;
//     return 0;
// }