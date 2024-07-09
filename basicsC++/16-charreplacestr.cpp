#include <iostream>
using namespace std;

void replacechar(char name[], char c1, char c2)
{
    int count = 0;
    for (int j = 0; name[j] != '\0'; j++)
    {
        count++;
    }
    int n = count;
    int i = 0;
    while (i < n)
    {
        if (name[i] == c1)
        {
            name[i] = c2;
        }
       i++;
    }
     cout << "newnameis:" << name << endl;
}

int main()
{
cout<<"enter a name:"<<endl;

    char name[20];
    cin >> name;
    char c1, c2;
    cin >> c1 >> c2;
    replacechar(name, c1, c2);
    return 0;
}