#include "question/236_Lowest_Common_Ancestor_of_a_Binary_Tree.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[3,5,1,6,2,0,8,null,null,7,4]\",\"5\",\"1\"],[\"[3,5,1,6,2,0,8,null,null,7,4]\",\"5\",\"4\"],[\"[1,2]\",\"1\",\"2\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      TreeNode * arg0 = parseTreeNode(args[0]);
      int arg1 = parseInteger(args[1]);
      int arg2 = parseInteger(args[2]);
      TreeNode * result=s->lowestCommonAncestor(arg0,arg1,arg2);
      string resultabc =serializeTreeNode(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}