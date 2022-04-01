#include "question/718_Maximum_Length_of_Repeated_Subarray.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[1,2,3,2,1]\",\"[3,2,1,4,7]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      vector<int> arg1 = parseIntegerArr(args[1]);
      int result=s->findLength(arg0,arg1);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}