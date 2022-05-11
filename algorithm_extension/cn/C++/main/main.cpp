#include "question/113_Path_Sum_II.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[5,4,8,11,null,13,4,7,2,null,null,5,1]\",\"22\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      TreeNode * arg0 = parseTreeNode(args[0]);
      int arg1 = parseInteger(args[1]);
      vector<vector<int>> result=s->pathSum(arg0,arg1);
      string resultabc =serializeIntegerArrArr(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}