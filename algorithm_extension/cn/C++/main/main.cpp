#include "question/___Offer_56___II____________II_LCOF.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[3,4,3,3]\"],[\"[9,1,7,9,7,9,7]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      int result=s->singleNumber(arg0);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}