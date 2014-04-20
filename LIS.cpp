#include <cstdio>
#include <cstring>

const int mem = 1000001, max = 2147483647;
int arr[mem], a[mem], n;

void read() {
    scanf( "%d", &n );
    for (int i = 0; i < n; ++i) {
        scanf( "%d", &arr[i] );
        a[i] = max;
    }
}

int binary_search( int b ) {
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if ( a[mid] < b )
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int alg() {
    for (int i = 0; i < n; ++i)
        a[ binary_search( arr[i] ) ] = arr[i];
    return binary_search( max );
}

int main() {
    read();
    printf( "%d\n", alg() );
    return 0;
}
