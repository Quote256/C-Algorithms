//This is an example of a recursive function
#include <iostream>

using namespace std;

int countdown(int num);
int sumRange(int num);

int main()
{
    int a = 10;
    countdown(a);

    int b = 3;
    cout << sumRange(b) << endl;

    return 0;
}

int countdown(int num)
{
    if (num <= 0)
    {
        cout << "Finished!\n";
        return 0;
    }
    cout << num << endl;
    num--;
    return countdown(num);
}

int sumRange(int num)
{
    if (num == 1)
    {
        cout << "Finished!\n";
        return 1;
    }
    cout << num << endl;
    return num + sumRange(num - 1);
}
