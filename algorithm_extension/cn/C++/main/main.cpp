#include "question/84_Largest_Rectangle_in_Histogram.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[2,1,5,6,2,3]\"],[\"[2,4]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      int result=s->largestRectangleArea(arg0);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}