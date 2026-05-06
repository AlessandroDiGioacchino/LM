
#include <iostream>
#include "arrayutils.h"

using namespace std;


void selectionSort( int* );


int main( int argc, char** argv ) {
  int* ns = ( int* ) malloc( MAX * sizeof( int ) );
  
  readIntArray( ns );
  selectionSort( ns );
  printIntArray( ns );

  return 0;
}

void selectionSort( int* ns ) {
  int min, minPos;

  for ( int i = 0; i < MAX - 1; i++ ) {
    min = ns[ i ];
    minPos = i;

    for ( int j = i + 1; j < MAX; j++ )
      if ( ns[ j ] < min ) {
        min = ns[ j ];
        minPos = j;
      }

    cout << "il minimo è " << min << ", in posizione " << minPos << endl;
    cout << "Scambio il minimo con ns[ " << i << " ] = " << ns[ i ] << endl; 
    ns[ minPos ] = ns[ i ];
    ns[ i ] = min;

    cout << "Parte ordinata del vettore -> ";
    printIntArrayHead( ns, i );
    cout << " | ";
    printIntArrayTail( ns, i + 1 );
    cout << " <- parte disordinata del vettore" << endl;

    if ( i == 0 ) cin.get();
    cin.get();
  }
}
