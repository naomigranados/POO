#include <iostream>
using namespace std;
#include <string>

int main () {
    int *v1 = nullptr;
    int value = 42;
    v1 = &value;
    cout<< v1 << endl;
    cout <<*v1 << endl;
    
    (*v1)++;
    cout << *v1 << endl;
    cout << value << endl;
    int *v2 = new int(100);
    cout << *v2 << endl;
    return 0;
}
