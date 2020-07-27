//This an example of a hash table, also know as a map
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

    map<int, string> name_map;

    name_map[0] = "Bob";
    name_map[3] = "Stacey";
    name_map[7] = "Liam";
    name_map[5] = "Archie";
    name_map[2] = "Veronica";

    cout << name_map[5] << endl;

    return 0;
}