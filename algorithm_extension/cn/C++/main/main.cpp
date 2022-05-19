#include "question/139_Word_Break.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"\\\"dogs\\\"\",\"[\\\"dog\\\",\\\"s\\\",\\\"gs\\\"]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      string arg0 = parseString(args[0]);
      vector<string> arg1 = parseStringArr(args[1]);
      bool result=s->wordBreak(arg0,arg1);
      string resultabc =serializeBool(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}