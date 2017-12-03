/* PointException.h models exceptions in Point Operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Modified by: Mason VanMeurs
 */

#ifndef POINT_EXCEPTION
#define POINT_EXCEPTION

#include <iostream>
using namespace std;

 
class PointException {
public:
   PointException(const string& whereThrown, const string& message) {
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


/* Function to allow a PointException (or a subclass) to be displayed
 * via an ostream.
 * Parameters: out, an ostream;
 *             se, a StackException.
 * Postcondition: the string representation of mde has been inserted
 * into out
 *             && return-value == out.
 */
inline ostream& operator<<(ostream& out, const PointException& pe) {
      out << pe.asString();
      return out;
}

#endif

