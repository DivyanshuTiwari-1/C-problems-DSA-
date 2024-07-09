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

char *replace(char input[], int i, int j)

{

    while (i < j)
    {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;

        i++;
        j--;
    }
    return input;
}

void replaceww(char input[])
{
    int i = 0;
    int j = (length(input) - 1);
   cout<< replace(input, i, j)<<endl;

    int k = 0;
    while (i < j)

    {
        if (input[i] != ' ')
        {
            i++;
        }
        
       else{
        replace(input, k, i - 1);
        i++;
        k = i;
    }
    }
     replace(input, k, i - 1);
    cout << input;
}

int main()
{

    char input[100];

    cout << "enter string" << endl;
    cin.getline(input, 100);
    
    replaceww(input);
    return 0;
}