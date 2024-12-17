        #include "LinkedList.h"
		#include "LinkedList.cpp"
		
		#include <iostream>
		using namespace std;

            // Simple print method
        template <class Object>
        void printList( const List<Object> & theList )
        {
            if( theList.isEmpty( ) )
                cout << "Empty list" << endl;
            else
            {
                ListItr<Object> itr = theList.first( );
                for( ; !itr.isPastEnd( ); itr.advance( ) )
                    cout << itr.retrieve( ) << " ";
            }

            cout << endl;
        }

        int main( )
        {
			List<int> a;
			ListItr<int> b;
			b = a.zeroth();


			return 0;
        }
