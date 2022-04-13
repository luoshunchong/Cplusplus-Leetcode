#include "question/___Offer_48_______________LCOF.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"\\\"abcabcbb\\\"\"],[\"\\\"bbbbb\\\"\"],[\"\\\"pwwkew\\\"\"],[\"\\\" \\\"\"],[\"\\\"au\\\"\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      string arg0 = parseString(args[0]);
      int result=s->lengthOfLongestSubstring(arg0);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}