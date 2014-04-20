//Algorytm Ryttera

#include <cstdio> //scanf(), printf()
#include <cmath> //log2()

typedef long long LL;

const int mem = 1000001;
int data[mem], count[mem];

inline bool odd( const LL& a ) {
    return a & 1; //Zwracam prawdę, jeśli dana liczba jest nieparzysta.
}

int main() {
    int n;
    scanf( "%d", &n ); //Wczytuję ilość elementów permutacji.
    for ( int i = 0; i < n; ++i ) {
        scanf( "%d", &data[i] ); //Wczytuję liczby.
        --data[i]; //Konwertuję permutację "od 1 do n" na "od 0 do n - 1".
    }
    LL answer = 0;
    int a, log_2 = log2( n ) + 1;
    for ( int i = 0; i < log_2; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            a = data[j];
            if ( odd( a ) )
                ++count[a]; //Jeśli dana liczba jest nieparzysta, to
                            //inkrementuję wartość wskazywaną przez nią w tablicy "count".
            else
                answer += (LL)count[a + 1]; //W przeciwnym razie, dodaję do wyniku wartość
                                            //wskazywaną przez daną liczbę + 1 w tablicy "count".
        }
        for ( int j = 0; j < n; ++j ) {
            data[j] >>= 1; //Dzielę przez 2 każdą daną .
            count[j] = 0; //Zeruję tablicę "count".
        }
    }
    printf( "%lld\n", answer ); //Wypisuję wynik.
    return 0;
}
