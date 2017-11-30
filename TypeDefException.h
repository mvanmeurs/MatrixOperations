/* TypeDefException.h models exceptions in Matrix Operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Modified by: Mason VanMeurs
 */

#ifndef TYPEDEF_EXCEPTION
#define TYPEDEF_EXCEPTION

#include <iostream>
using namespace std;

 
class TypeDefException {
public:
   TypeDefException(const string& whereThrown, const string& message) {
       myLocation = whereThrown; 
       myMessage = message; 
   }

   string asString() const {
       return "*** TypeDef Exception in " +
               myLocation + ": " + myMessage; 
   }

private:
   string myLocation;
   string myMessage;
};


/* Function to allow a TypeDefException (or a subclass) to be displayed
 * via an ostream.
 * Parameters: out, an ostream;
 *             se, a StackException.
 * Postcondition: the string representation of mde has been inserted
 * into out
 *             && return-value == out.
 */
inline ostream& operator<<(ostream& out, const TypeDefException& tde) {
      out << tde.asString();
      return out;
}

#endif

