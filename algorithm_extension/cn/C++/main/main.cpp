#include "question/593_Valid_Square.cpp"
#include "regex"
#include "algm/parse.h"
int main(int argc, char *argv[])
{
    string str = "[[\"[0,0]\",\"[1,1]\",\"[1,0]\",\"[0,1]\"],[\"[0,0]\",\"[1,1]\",\"[1,0]\",\"[0,12]\"],[\"[1,0]\",\"[-1,0]\",\"[0,1]\",\"[0,-1]\"]]";
    vector<vector<string>> arr = parseStringArrArr(str);
    for (int i = 0; i < arr.size(); i++)
    {
      vector<string> args = arr[i];
      Solution *s = new Solution();
      vector<int> arg0 = parseIntegerArr(args[0]);
      vector<int> arg1 = parseIntegerArr(args[1]);
      vector<int> arg2 = parseIntegerArr(args[2]);
      vector<int> arg3 = parseIntegerArr(args[3]);
      bool result=s->validSquare(arg0,arg1,arg2,arg3);
      string resultabc =serializeBool(result);
      cout << "resultabc"+to_string(i)+":" << resultabc <<"resultend"<< endl;
    }
    return 0;
}