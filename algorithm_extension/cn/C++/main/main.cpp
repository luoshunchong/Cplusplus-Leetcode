#include "question/98_Validate_Binary_Search_Tree.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[5,4,6,null,null,3,7]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      TreeNode * arg0 = parseTreeNode(args[0]);
      bool result=s->isValidBST(arg0);
      string resultabc =serializeBool(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}