//Najdłuższy podciąg rosnący (The longest increasing subsequence)

#include <iostream>

const int mem = 1000001, infinity = 2147483647;
int data[mem], buildLIS[mem], n;

void read() {
    std::cin >> n; // Wczytaj ilość danych liczb.
    for ( int i = 0; i < n; ++i ) {
        std::cin >> data[i]; // Wczytaj dane liczby.
        build[i] = infinity; // Wypełnij tablicę "budujNPR" od 0 do n (patrz:
                             // linia 15) wartością "nieskończoną" (infinity).
    }
    build[n] = infinity;
}

int upperBound( int a ) { // Wyszukaj binarnie danej wartości (patrz: 34, 35).
    int l = 0, r = n, mid;
    while ( l < r ) {
        mid = ( l + r ) / 2;
        if ( build[mid] < a )
            l = mid + 1;
        else
            r = mid;
    }
    return l; // Zwróć indeks w tablicy "budujNPR", pod którym znajduje się szukana wartość (patrz: 34, 35).
}

int searchForLIS() {
    for ( int i = 0; i < n; ++i )
        buildLIS[upperBound( data[i] )] = data[i]; // Wstaw daną liczbę (data[i]) pod indeksem w tablicy
                                                   // "budujNPR", gdzie znajduje się pierwsza większa bądź
                                                   // równa wartość w stosunku do danej liczby (data[i]).
    return upperBound( infinity ); //Zwróć długość najdłuższego podciągu rosnącego.
}

int main() {
    read(); // Wczytaj dane.
    std::cout << searchForLIS() << std::endl; // Wypisz długość najdłuższego podciągu rosnącego.
    return 0;
}
