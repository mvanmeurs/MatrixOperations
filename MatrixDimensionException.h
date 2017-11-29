/* MatrixDimensionException.h models exceptions in Matrix Operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Modified by: Mason VanMeurs
 */

#ifndef STACK_EXCEPTION
#define STACK_EXCEPTION

#include <iostream>
using namespace std;

 
class MatrixDimensionException {
public:
   MatrixDimensionException(const string& whereThrown, const string& message) {
       myLocation = whereThrown; 
       myMessage = message; 
   }

   string asString() const {
       return "*** StackException in " +
               myLocation + ": " + myMessage; 
   }

private:
   string myLocation;
   string myMessage;
};


/* Function to allow a MatrixDimensionsException (or a subclass) to be displayed
 * via an ostream.
 * Parameters: out, an ostream;
 *             se, a StackException.
 * Postcondition: the string representation of mde has been inserted
 * into out
 *             && return-value == out.
 */
inline ostream& operator<<(ostream& out, const MatrixDimensionException& mde) {
      out << mde.asString();
      return out;
}

#endif

