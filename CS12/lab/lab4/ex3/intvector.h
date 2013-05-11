//intvector.h


#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_
#include <iostream>

using namespace std;

class IntVector {
    
    private:
        unsigned vsize;
        unsigned vcapacity;
        int* data;
    
    public:
        IntVector();
        IntVector( unsigned size );
        int &at( unsigned index );
        const int &at( unsigned index) const;
        unsigned int size();
};

#endif


