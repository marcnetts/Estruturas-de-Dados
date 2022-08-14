//Pilhas Recursivas por Marcos Henrique Ribeiro Zanetti
#include <iostream>
using namespace std;

int mt(int a, int b) {
    if (b == 1)
        return a;
    else if (b > 1)
        return (mt(a,b-1) + 1);
}

int main()
{
    cout<<"mt(2, 5): "<<mt(2, 5)<<endl;
    return 0;
}
