
#include <iostream>
#include "arrayutils.h"

using namespace std;


int binarySearch( int*, int );


int main( int argc, char** argv ) {
  int* ns = ( int* ) malloc( MAX * sizeof( int ) );
  if ( !ns ) exit( -1 );

  int n, pos;
  cout << "inserisci " << MAX << " interi ORDINATI, separati da uno spazio: ";
  readIntArray( ns );

  if ( !isIntArraySorted( ns ) ) return 1;

  cout << "inserisci l'intero da cercare: ";
  cin >> n;

  pos = binarySearch( ns, n );
  if ( pos < 0 ) cout << n << " non trovato" << endl;
  else {
    cout << n << " trovato in posizione " << pos << "; ns[ pos ] = ";
    cout << ns[ pos ] << endl;
  }

  return 0;
}

int binarySearch( int* ns, int n ) {
  int left = 0, right = MAX - 1;
  int middle;

  while ( left <= right ) {
    middle = ( left + right ) / 2;
    cout << "left = " << left;
    cout << ", middle = " << middle << ", ns[ middle ] = " << ns[ middle ];
    cout << ", right = " << right << endl;
    if ( left == 0 && right == MAX - 1 ) cin.get();
    cin.get();
    
    if ( ns[ middle ] < n ) {
      cout << "ns[ middle ] = " << ns[ middle ] << " minore di " << n;
      cout << ", aggiorno left" << endl;
      left = middle + 1;
    } else if ( ns[ middle ] > n ) {
      right = middle - 1;
      cout << "ns[ middle ] = " << ns[ middle ] << " maggiore di " << n;
      cout << ", aggiorno right" << endl;
    } else return middle;
  }

  return -1;
}
