#include "question/64_Minimum_Path_Sum.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[[1,3,1],[1,5,1],[4,2,1]]\"],[\"[[1,2,3],[4,5,6]]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<vector<int>> arg0 = parseIntegerArrArr(args[0]);
      int result=s->minPathSum(arg0);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}