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
void remove(char input[])

{
    int l = length(input);
    int i = 0;
    int a[256];
    for (int i = 0; i < 256; i++)
    {
        a[i] = 0;
    }

    while (i < l)
    {
        char c = input[i];
        int k = int(c);
        a[k] = a[k] + 1;
        i++;
    }
   /* char ans = input[0];
    int k = int(ans);
    int count = a[k];
    int q = 1,p=k;
    while (q < l)
    {
                                //method by coding ninjas
        char ans1 = input[q];
        int k1 = int(ans1);
        int count1 = a[k1];
        if(count1>count){
            count=count1;
            p=k1;
        }
        q++;

    }
    */
   int p=0;
   int max=a[0];
   for(int i=1;i<256;i++)
   {
      if(a[i]>max)
      {              //method by me
        max=a[i];
        p=i;
      }
   }
    char c=int(p);
    cout << c;
}

int main()
{
    char arr[100];
    cout << "enter string" << endl;
    cin >> arr;
    remove(arr);

    return 0;
}