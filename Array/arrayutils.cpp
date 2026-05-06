
#include <iostream>
#include "arrayutils.h"

using namespace std;


void readIntArray( int* ns ) {
  for ( int i = 0; i < MAX; ++i ) cin >> ns[ i ];
}

void printIntArray( int* ns ) {
  for ( int i = 0; i < MAX - 1; ++i ) cout << ns[ i ] << " ";
  cout << ns[ MAX - 1 ] << endl;
}

bool isIntArraySorted( int* ns ) {
  for ( int i = 0; i < MAX - 1; i++ )
    if ( ns[ i ] > ns[ i + 1 ] ) return false;
  
  return true;
}

void printIntArrayHead( int* ns, int headLen ) {
  if ( headLen >= MAX ) return;
  for ( int i = 0; i < headLen; ++i ) cout << ns[ i ] << " ";
  cout << ns[ headLen ];
}

void printIntArrayTail( int* ns, int tailLen ) {
  if ( tailLen >= MAX ) return;
  for ( int i = tailLen; i < MAX - 1; ++i ) cout << ns[ i ] << " ";
  cout << ns[ MAX - 1 ];
}
