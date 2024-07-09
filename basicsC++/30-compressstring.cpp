#include <iostream>
using namespace std;

int length(char input[])
{

  int count = 0;
  for (int j = 0; input[j] != '\0'; j++)
  {
    count++;
  }
  return count;
}
/* void compress(char input[])
{
  int l = length(input);
  int i = 0, j = 0;
  int count = 1;
  char arr[l];
  for (int i = 0; i < l; i++)
  {
    arr[i] = 'a';
  }

  while (i < l)
  {

    if (input[i + 1] = input[i])
    {
      count++;
      i++;
    }
    else
    {
      arr[j] = input[i];
      char c = count;
      arr[j + 1] = int(c);
      count = 1;
      j++;
      i++;
    }
  }
  arr[j] = '\0';
  cout << input;
}
*/

void compress(string s)
{
  
  int l = s.length()-1;

  
  for(int i=0;i<=l;i++){
    int count = 1;
    while(i<l&&s.at(i + 1) == s.at(i))
    {
      count++;
      i++;
    }
    if (count == 1)
    {
      cout << s[i];
      
    }
    else
    {
      cout << s[i] << count;
      
    }
  }
}

int main()
{
  char input[100];
  cout << "enter string:" << endl;
  cin >> input;
  compress(input);

  return 0;
}