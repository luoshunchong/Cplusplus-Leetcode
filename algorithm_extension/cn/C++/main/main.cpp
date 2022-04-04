#include "question/106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[9,3,15,20,7]\",\"[9,15,7,20,3]\"],[\"[-1]\",\"[-1]\"],[\"[2,1]\",\"[2,1]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      vector<int> arg1 = parseIntegerArr(args[1]);
      TreeNode * result=s->buildTree(arg0,arg1);
      string resultabc =serializeTreeNode(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}