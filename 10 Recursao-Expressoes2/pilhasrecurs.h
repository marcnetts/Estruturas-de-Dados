#include <iostream>
#include <cmath>
//Pilhas Recursivas por Marcos Henrique Ribeiro Zanetti
using namespace std;

#ifndef PILHASRECURS_H_INCLUDED
#define PILHASRECURS_H_INCLUDED


int fib(int n) {
    if (n <= 2)
        return 1;

    return (fib(n-1) + fib (n-2));
}

int mdc(int x, int y) {
    if (x == y)
        return x;
    else if (x < y)
        return (mdc(y,x));

    return (mdc(x-y,y));
}

int s(int m, int n) {
    if (m == n)
        return m;
    else if (m < n)
        return (s(m,n-1) + n);
}

int s2(int m, int n) {
    if (m == n)
        return m;
    else if (m < n)
        return (m + s2(m+1, n));
}

int dig(int n) {
    if (abs(n) <= 9)
        return 1;

    return (1 + (dig(n/10)));
}

int pot(int x, int n) {
    if (n == 0)
        return 1;
    else if (n < 0)
        return (1 / pot(x, abs(n)));

    return x * pot(x, n - 1);
}

#endif // PILHASRECURS_H_INCLUDED
