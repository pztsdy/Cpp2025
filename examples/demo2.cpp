#include <iostream>
#include <algorithm>
#include "..\sortcmp.hpp"
#include "..\wapi.hpp"
using namespace std;
int main(){
    cout << "A demo program using sortcmp.hpp" << endl;
    int a[] = {1, 3, 2, 5, 4};
    cout  << "Before sort: ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
    sort(a, a + 5, int_small_to_big);
    cout << "After sort (small to big): ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
    sort(a, a + 5, int_big_to_small);
    cout << "After sort (big to small): ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
    sort(a, a + 5, int_jFOS);
    cout << "After sort (oFjS): ";
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Press Enter to continue...";
    pause();
    exit(0);

    return 0;
}