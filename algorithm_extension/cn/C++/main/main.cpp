#include "question/___Offer_19_________LCOF.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"\\\"ab\\\"\",\"\\\".*\\\"\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      string arg0 = parseString(args[0]);
      string arg1 = parseString(args[1]);
      bool result=s->isMatch(arg0,arg1);
      string resultabc =serializeBool(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}