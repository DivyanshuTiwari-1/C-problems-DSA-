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
void removedupli(char input[])

{
    int l = length(input);
    char arr[l];
    int i = 0, j = 0;
    while (i < l)
    {
        if (input[i] == input[i + 1])
        {
            i++;
        }
        else
        {
            arr[j] = input[i];
            j++;
            i++;
        }
        
    }
    int k = 0;
    while (k <= j)

    {
        cout << arr[k];
        k++;
    }
}

int main()
{
    char input[100];
    cout << "enterstring" << endl;
    cin >> input;
    removedupli(input);
    return 0;
}