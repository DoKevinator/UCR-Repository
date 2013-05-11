    #include "intvector.h"
    #include <iostream>
 
    using namespace std;
 
    ostream& operator<<(ostream &out, IntVector &iv)
    {
      for(unsigned i = 0; i < iv.size(); i++)
        out << iv.at(i) << " ";
      return out;
    }
 
    int main()
    {

      IntVector my_vector(10);
	
      my_vector.at(0) = 1;
      for(unsigned i = 1; i < my_vector.size(); i++)
        my_vector.at(i) = my_vector.at(i-1) * i;
 
      cout << my_vector << endl;
 
      return 0;
    }


