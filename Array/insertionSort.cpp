
#include <iostream>
#include "arrayutils.h"

using namespace std;


void insertionSort( int* );


int main( int argc, char** argv ) {
  int ns[ MAX ];

  cout << "inserisci " << MAX << " interi separati da uno spazio: ";
  readIntArray( ns );

  insertionSort( ns );
  printIntArray( ns );

  return 0;
}


void insertionSort( int* ns ) {
  int j, key;

  for ( int i = 1; i < MAX; ++i ) {
    j = i;
    cout << "j parte da " << j << endl; 
    
    key = ns[ i ];
    cout << "La chiave è ns[ " << i << " ], cioè " << key << endl;

    while ( ns[ j - 1 ] > key && j > 0 ) {
      // if ( j < i - 1 ) cout << "Nuova iterazione" << endl;

      cout << ns[ j - 1 ] << " è maggiore della chiave " << key << ", ";
      cout << "quindi copio " << ns[ j - 1 ] << " al posto di " << ns[ j ];
      cout << endl;
      ns[ j ] = ns[ j - 1 ];

      printIntArray( ns );

      --j;
      cout << "Decremento j, che diventa " << j << endl;
      cin.get();
    }

    if ( ns[ j - 1 ] < key )
      cout << ns[ j - 1 ] << " non è maggiore della chiave " << key << endl;

    cout << "Ho fatto spazio per la chiave: sostituisco " << ns[ j ];
    cout << ", in posizione " << j << ", con " << key << endl;
    ns[ j ] = key;

    cout << "il nuovo vettore è ";
    printIntArray( ns );
    cin.get();
  }
}
