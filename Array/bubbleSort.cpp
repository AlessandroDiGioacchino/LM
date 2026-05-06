
#include <iostream>
#include "arrayutils.h"

using namespace std;


void bubbleSort( int* );


int main( int argc, char** argv ) {
  int ns[ MAX ];
  readIntArray( ns );

  bubbleSort( ns );
  printIntArray( ns );
}


void bubbleSort( int* ns ) {
  bool flag;
  int i = 1;

  do {
    if ( i > 1 ) cout << "Nuova iterazione: imposto `flag` su `false`" << endl;
    flag = false;
    cin.get();

    for ( int j = 0; j < MAX - i; ++j ) {
      if ( ns[ j ] > ns[ j + 1 ] ) {
        cout << ns[ j ] << " e " << ns[ j + 1 ] << " non sono in ordine: ";
        cout << "li scambio" << endl;
        swap( ns[ j ], ns[ j + 1 ] );

        cout << "Vettore corrente: ";
        printIntArray( ns );

        if ( !flag ) {
          cout << "Ho fatto uno scambio: imposto `flag` su `true`" << endl;
          flag = true;
        }

        cin.get();
      }
    }

    if ( !isIntArraySorted( ns ) ) {
      cout << "Parte disordinata del vettore -> ";
      printIntArrayHead( ns, MAX - i - 1 );
      cout << " | ";
      printIntArrayTail( ns, MAX - i );
      cout << " <- parte ordinata del vettore" << endl;
      
      cout << "incremento `i`, che diventa: " << ++i << endl;
      cin.get();
    }    
  } while ( flag );

  cout << "Il vettore è ordinato:" << endl;
}
