
#include <iostream>
using namespace std;

int displayMenu();
void fillNames( string*, int* );
bool isSorted( string* );
void bubbleSort( string*, int* );
void printStrings( string*, int* );

const int MAX = 10;

int main( int argc, char* argv[] ) {
  displayMenu();
  return 0;
}

int displayMenu() {
  int choice;
  string names[ MAX ];
  int marks[ MAX ];

  do {
    cout << "Digita ";
    cout << "`1` per inserire nomi e voti, ";
    cout << "`2` per stamparli in ordine alfabetico, ";
    cout << "`3` per uscire" << endl;

    cin >> choice;

    switch ( choice ) {
      case 1:
      fillNames( names, marks );
      break;

      case 2:
      if ( !isSorted( names ) ) bubbleSort( names, marks );
      printStrings( names, marks );
      break;
    }
  } while ( choice != 3 );

  return 0;
}

void fillNames( string* names, int* marks ) {
  cout << "inserisci i " << MAX << " nomi separati da uno spazio: ";
  for ( int i = 0; i < MAX; i++ ) cin >> names[ i ];

  cout << "inserisci i " << MAX << " voti separati da uno spazio: ";
  for ( int i = 0; i < MAX; i++ ) cin >> marks[ i ];
}

bool isSorted( string* names ) {
  for ( int i = 0; i < MAX - 1; i++ )
    if ( names[ i + 1 ] < names[ i ] ) return false;

  return true;
}

void bubbleSort( string* names, int* marks ) {
  bool flag;
  string name;
  int mark;

  int i = 1;

  do {
    flag = false;

    for ( int j = 0; j < MAX - i; j++ )
      if ( names[ j + 1 ] < names[ j ] ) {
        // Scambio `names[ j ]` con `names[ j + 1 ]`
        name = names[ j ];
        names[ j ] = names[ j + 1 ];
        names[ j + 1 ] = name;

        mark = marks[ j ];
        marks[ j ] = marks[ j + 1 ];
        marks[ j + 1 ] = mark;

        flag = true;
      }

    ++i;
  } while ( flag );
}

void printStrings( string* names, int* marks ) {
  for ( int i = 0; i < MAX - 1; i++ ) {
    cout << names[ i ] << " ";
    cout << marks[ i ] << " " << endl;
  }

  cout << names[ MAX - 1 ] << " " << marks[ MAX - 1 ] << endl;
}
