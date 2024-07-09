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
bool cheackpermutation(char input1[], char input2[])
{
    int l1 = length(input1);
    int l2 = length(input2);
    int arr[256];
    for (int i = 0; i < 256; i++)
    {
        arr[i] = 0;
    }

    if (l1 == l2)
    {
        int i = 0, j = 0;
        while (i < l1)
        {
            char c = input1[i];
            int k = int(c);
            arr[k] = arr[k] + 1;
            i++;
        }
        while (j < l2)
        {
            char c = input2[j];
            int k = int(c);
            arr[k] = arr[k] - 1;
            j++;
        }
        int p = 0;
        while (p < 256)
        {
            if (arr[p] != 0)
            {
                return false;
            }
            p++;
        }
        return true;
    }
        return false;
    
    
 
}

int main()
{

    char input1[100], input2[100];
    cout << "enter the two string" << endl;
    cin >> input1;
    cout << endl;
    cin >> input2;
    cout << endl;

    cout << cheackpermutation(input1, input2);

    return 0;
}