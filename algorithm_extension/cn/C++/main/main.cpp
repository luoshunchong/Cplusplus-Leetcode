#include "question/___Offer_06__________LCOF.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[1,3,2]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      ListNode * arg0 = parseListNode(args[0]);
      vector<int> result=s->reversePrint(arg0);
      string resultabc =serializeIntegerArr(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}