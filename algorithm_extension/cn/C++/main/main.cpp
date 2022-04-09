#include "question/___Offer_25____________LCOF.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[1,2,4]\",\"[1,3,4]\"],[\"[]\",\"[]\"],[\"[]\",\"[0]\"],[\"[-9,3]\",\"[5,7]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      ListNode * arg0 = parseListNode(args[0]);
      ListNode * arg1 = parseListNode(args[1]);
      ListNode * result=s->mergeTwoLists(arg0,arg1);
      string resultabc =serializeListNode(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}