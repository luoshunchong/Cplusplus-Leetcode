#include "question/752_Open_the_Lock.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[\\\"0201\\\",\\\"0101\\\",\\\"0102\\\",\\\"1212\\\",\\\"2002\\\"]\",\"\\\"0202\\\"\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<string> arg0 = parseStringArr(args[0]);
      string arg1 = parseString(args[1]);
      int result=s->openLock(arg0,arg1);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}