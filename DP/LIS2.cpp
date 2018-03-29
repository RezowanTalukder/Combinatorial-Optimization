#include <stdio.h>

int a[10001], t[10001], n, l, i;

/**
a -> This is the input, is an array of integers
t -> Each position have the index of the last item in the ith LIS
l -> The last valid position of t
n -> Size of input a
**/

int ceil(int v)
{
    int init = 0, fin = l; ///Start and end for binary search
    while(init < fin-1)
    {
        int m = (init+fin)/2;

        if(a[t[m]] >= v)
            fin = m;
        else
            init = m;
    }

    if(a[t[init]] >= v)
        return init;
    return fin;
}

void lis()
{
    r[0] = 1;
    t[0] = 0;
    l = 0;

    for(i=1; i<n; i++)
    {
        if(a[i] > a[t[l]])
            l++, t[l] = i;
        else
            t[ceil(a[i])] = i;
    }
}
