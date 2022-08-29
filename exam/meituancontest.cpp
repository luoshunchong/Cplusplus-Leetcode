#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool check(int num) {
  int count = 0;
  while (num) {
    int t = num % 10;
    if (t == 1) count++;
    num /= 10;
  }
  if (count == 2)
    return true;
  else
    return false;
}

void firstTitle(int num) {
  if (num % 11 == 0)
    cout << "yes" << endl;
  else if (check(num))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}

bool check1(string s) {
  int count = 0;
  for (auto t : s) {
    if (t == 'b') count++;
  }
  if (count & 1) return false;
  else return true;
}
void secondTitle(vector<int>& nums) {
  int res = 0;
  for (int i = 0; i < nums.size(); ++i) {
    string s = "";
    for (int j = i; j < nums.size(); ++j) {
      s += nums[j] > 0 ? 'a' : 'b';
      if (check1(s)) res++;
    }
  }
  cout << res << endl;
}

int main() {
  /*
  第一题：小美的幸运数字（20分） 难度： easy
  输入一组数，判断每个数字是否满足以下条件之一：

  是11的倍数
  含有至少两个1
  满足输出yes，否则输出no

  例子：输入132 输出yes; 输入1001 输出yes; 输入100输出no
  */
  // int num = 100;
  // firstTitle(num);

  /*
  给定一组全为1或者-1的序列，判断有多少个连续子序列乘积为正数。难度：medium
  例子：
  输入：[1, 1, -1, -1]
  输出： 6
  说明：连续子序列有[1],[1],[1,1],[-1,-1],[1,-1,-1],[1,1,-1,-1]
  */
  vector<int> nums = {1, 1, -1, -1};
  secondTitle(nums);

  /*
  求解最大满足顾客数。难度：hard
  小美有m个菜（编号为1,2,...,m），n个顾客，每个顾客都会点两个菜（给定编号）。求最多能满足多少个顾客。
  例子：
  输入：
  n = 3, m = 4
  顾客1： 1，2
  顾客2： 2，3
  顾客3： 3，4
  输出：2
  说明：最多满足两个顾客，顾客1和顾客3。
  */

  /*
  求解最少消耗能量。 难度：hard
  小美在玩游戏，有n个房间，m秒。小美第一秒指向1号房间，同时每秒都有一个房间爆炸（第一秒时，1号房间不爆炸）。每秒结束时，小美都会通过魔法指向其他房间，每次转移指向都会消耗1点魔法。求小美在无伤的情况下消耗的最小魔法数。
  例子1：
  输入：
  n = 2, m = 4
  [2, 1, 1, 2]
  输出：2
  说明：第一秒结束转移到2号房间，第三秒结束转移到1号房间，共消耗2点魔法。
  例子2：
  输入：
  n = 3, m = 10
  [2, 3, 1, 3, 2, 1, 1, 2, 3, 1]
  输出：3
  说明：第2秒结束转移到2号房间，第3秒结束转移到3号房间，第8秒结束转移到2号房间, 共消耗3点魔法。
  */

  return 0;
}