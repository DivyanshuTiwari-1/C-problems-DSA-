#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<char> removeduplifromstr(string str)
{
   vector<char> output;
   unordered_map<char, bool> seen;
   for (int i = 0; i < str.length(); i++)
   {

      if (seen.count(str[i])>0)
      {
         continue;
      }

      seen[str[i]] = true;
      output.push_back(str[i]);
   }
   return output;
}

int main()
{
   string s="aaaaabbbbbccccsssssddddd";
   vector<char>output=removeduplifromstr(s);
   for (int i=0;i<output.size();i++){
      cout<<output.at(i);
   }
   cout<<"you have 1 lakhs cr in your bank account";
   
   return 0;
}