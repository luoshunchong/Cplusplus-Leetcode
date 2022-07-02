#include "question/437_Path_Sum_III.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[10,5,-3,3,2,null,11,3,-2,null,1]\",\"8\"],[\"[5,4,8,11,null,13,4,7,2,null,null,5,1]\",\"22\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      TreeNode * arg0 = parseTreeNode(args[0]);
      int arg1 = parseInteger(args[1]);
      int result=s->pathSum(arg0,arg1);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}