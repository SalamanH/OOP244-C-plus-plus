// compilation safegaurds
#ifndef ict_Error_h
#define ict_Error_h
#include <iostream>

namespace ict {
   class Error {
      char* m_message;
   public:
   // constructors
	   Error();
	   Error(const char* errorMessage);
	   Error(const Error& em) = delete;

   // destructor

	  // ~Error();
	   virtual ~Error();
   // deleted constructor and operator=
	   Error& operator=(const Error& em) = delete;
   // operator= for c-style strings
	   operator const char*() const;
	   void operator=(const char* errorMessage);
   // methods
	   void clear();
	   bool isClear()const;
	   void message(const char* value);
	   operator bool()const;
   // cast overloads

   };
   // operator << overload prototype for cout
   std::ostream& operator<<(std::ostream& ostr, const Error& obj);
}
 
#endif

