#include "question/1122_Relative_Sort_Array.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[2,3,1,3,2,4,6,7,9,2,19]\",\"[2,1,4,3,9,6]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      vector<int> arg1 = parseIntegerArr(args[1]);
      vector<int> result=s->relativeSortArray(arg0,arg1);
      string resultabc =serializeIntegerArr(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}