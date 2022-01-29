#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
面试题3：数组中的重复数字
题目一：找出数组中重复的数字
*/

void DuplicationInArray1(vector<int> &nums) {
    /*
    方案一：
    先排序，再遍历一遍
    时间复杂度：nlogn
    空间复杂度：1
    */
   int res;
   sort(nums.begin(),nums.end());
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] == nums[i]) res = nums[i];
    }
    cout << "方案一：第一个重复的数字为：" << res << endl;
}

void DuplicationInArray2(vector<int> &nums) {
    /*
    方案二：
    遍历一遍数组，将数字存入哈希表中，如果包含了该数字就返回结果。
    时间复杂度：n
    空间复杂度：n
    */
   int res;
   unordered_set<int> temp;
   for (int i = 0; i < nums.size(); ++i) {
       if (temp.find(nums[i]) == temp.end()) temp.insert(nums[i]);
       else {
           res = nums[i]; 
           break;
       }
   }
   cout << "方案二：第一个重复的数字为：" << res << endl;
}

void DuplicationInArray3(vector<int> &nums) {
    /*
    重排这个数组。先遍历扫描到下标为i的数字时，首先比较这个数字m是不是等于i；如果是，就接着扫描下一个数字；如果不是，
    则拿它和第m个数字比较。如果它和第m个数字相等，就找到了一个重复的数字；如果它和第m个数字不想等，就把第i个数字和第m个数字交换，
    把m放到属于它的位置。接下来重复这个过程。
    时间复杂度：n
    空间复杂度：1
    */
   int res;
   for (int i = 0; i < nums.size(); ++i) {
       if (nums[i] == i) continue;
       else {
           if (nums[i] == nums[nums[i]]) {
               res = nums[i];
               break;
           }
           else {
               int temp = nums[i];
               nums[i] = nums[nums[i]];
               nums[nums[i]] = temp;
           }
       }
   }
   cout << "方案三：第一个重复的数字为：" << res << endl;

}

int main() {
    //建立测试用例
    vector<int> nums = {1, 2, 3, 2};
    //函数入口
        //方案一
    DuplicationInArray1(nums);
        //方案二
    DuplicationInArray2(nums);
        //方案三
    DuplicationInArray3(nums);

    //按任意键暂停
    system("pause");
    //主函数返回值
    return 0;
}