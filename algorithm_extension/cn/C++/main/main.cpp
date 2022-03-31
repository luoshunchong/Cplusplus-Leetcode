#include "question/862_Shortest_Subarray_with_Sum_at_Least_K.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[1]\",\"1\"],[\"[1,2]\",\"4\"],[\"[2,-1,2]\",\"3\"],[\"[48,99,37,4,-31]\",\"140\"],[\"[17,85,93,-45,-21]\",\"150\"],[\"[84,-37,32,40,95]\",\"167\"],[\"[-28,81,-20,28,-29]\",\"89\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      int arg1 = parseInteger(args[1]);
      int result=s->shortestSubarray(arg0,arg1);
      string resultabc =serializeInteger(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}