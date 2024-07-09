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
/*char* removespace(char input[])
{
   int len = length(input);
   int i = 0;
   while (i < len)
   {
       if (input[i] ==' ')
       { int j=i;
          while(input[j+1]!=' ')
            input[j]= input[j+1];//i tried this method but it not worked
            j++;

       }
       i++;
   }

   return input;
}*/

void removespace(char input[])
{
    int len = length(input);
    int i = 0, j = 0;
    while (i < len)
    {
        if (input[i] != ' ')
        {
            input[j] = input[i];
            j++;
        }
        i++;
    }
    input[j] = '\0';
    cout << input;
}

int main()
{
    char input[100];
    cout << "the name" << endl;
    cin.getline(input, 100);
    removespace(input);
    return 0;
}