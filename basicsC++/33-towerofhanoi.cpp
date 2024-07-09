#include <iostream>
using namespace std;

void towerofhanoi(int n, char s, char a, char d)
{
    if (n == 0)
    {

        return;
    }
    towerofhanoi(n - 1, s, d, a);
    cout << s << " " << d<<endl;
    towerofhanoi(n - 1, a, s, d);
}

int main()
{
    int n;
    cout << "enterno disk" << endl;
    cin >> n;

    towerofhanoi(n, 'a', 'b', 'c');

    return 0;
}