#include <iostream>
using namespace std;

int check(string s)


int main()
{
  string s;
  cin >> s;
  int k = check(s);
  if (k == 1)
    cout << "true" << endl;
  else
    cout << "false" << endl;

  return 0;
}