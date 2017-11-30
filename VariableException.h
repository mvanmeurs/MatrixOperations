/* VariableException.h models exceptions in Matrix Operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Modified by: Mason VanMeurs
 */

#ifndef VARIABLE_EXCEPTION
#define VARIABLE_EXCEPTION

#include <iostream>
using namespace std;

 
class VariableException {
public:
   VariableException(const string& whereThrown, const string& message) {
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


/* Function to allow a VariableException (or a subclass) to be displayed
 * via an ostream.
 * Parameters: out, an ostream;
 *             se, a StackException.
 * Postcondition: the string representation of mde has been inserted
 * into out
 *             && return-value == out.
 */
inline ostream& operator<<(ostream& out, const VariableException& ve) {
      out << ve.asString();
      return out;
}

#endif

