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

char *replace(char input[], int n, int m)
{
    int i = n, j = m;
    while (i < j)
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }
    return input;
}

char *reversewordwise(char input[])
{
    int i = 0;
    int j = length(input);
    int k = 0;
    while (i < j)
    {
    
        if (input[i] != ' ')
        {
            i++;
        }
        else{
            replace(input, k, i);
            i++;
            k=i;
        }
    }
    return input;
}

int main()
{
    char input[100];
    cout << "enter charcter arr" << endl;
    cin.getline(input, 100);
    int l = length(input);
    cout << reversewordwise(input);

    return 0;
}