#include "question/814_Binary_Tree_Pruning.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[1,null,0,0,1]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      TreeNode * arg0 = parseTreeNode(args[0]);
      TreeNode * result=s->pruneTree(arg0);
      string resultabc =serializeTreeNode(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}