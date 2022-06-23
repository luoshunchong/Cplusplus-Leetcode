#include "question/93_Restore_IP_Addresses.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"\\\"255255255255\\\"\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      string arg0 = parseString(args[0]);
      vector<string> result=s->restoreIpAddresses(arg0);
      string resultabc =serializeStringArr(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}