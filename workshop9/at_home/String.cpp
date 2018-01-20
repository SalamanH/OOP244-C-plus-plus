#include <cstring>
#include <iostream>
#include "String.h"
#include <stdio.h>
#include <string.h>
using namespace std;

namespace sict {


   //////////////////////////////////////////////////////
   //
   // Default Constructor
   // String::String();
   //
   // initialize the string to ""
   //
   // 
   String::String() 
   {
      // initialize the string to ""
      m_pString = nullptr;
   }


   //////////////////////////////////////////////////////
   //
   // String::String(const char* p);
   //
   // Construct a String from a char array
   // You may assume the input string pSource 
   // has a length of < 50, and the internal buffer has enough
   // space to hold it.
   //
   // 
   String::String(const char* pSource) 
   {
	  m_pString = new char[strlen(pSource) + 1];

      strcpy(m_pString, pSource);
	  
   }

   //////////////////////////////////////////////////////
   //
   // String::String(const String &s, int capacity);
   //
   // Copy constructor
   //
   // Construct a String from another String
   //
   // 
   String::String(const String& other)
   {
      strcpy(m_pString, other.m_pString);
 
   }




   //////////////////////////////////////////////////////
   //
   // String::operator=(const String& other)
   // 
   // Assignment operator
   // copy string "other" to this object
   //   
   //     
   String& String::operator=(const String& other)
   {
      strcpy(m_pString, other.m_pString);
      return *this;
   }


   String::String(int capacity) {
      m_pString = new char[capacity];
	  m_pString = nullptr;


   }
   String::String(const char* p, int capacity) {
       // capacity >= length + 1
	   if (capacity >= (strlen(p) + 1)) {
		   //char* m_pString = new char[capacity];
           m_pString[capacity];
		   strcpy(m_pString, p);
	   }
	   else {
		   //char* m_pString = new char[strlen(p) + 1];
           m_pString[strlen(p) + 1];
		   strcpy(m_pString, p);
	   }
   }
   /*String::String(const String& s) {
       if (strlen(s.m_pString) > strlen(m_pString));
       char* m_pString = new char[strlen(s.m_pString)];
       strcpy(m_pString, s.m_pString);
   }*/
  /* int String::capacity() {
       return strlen(m_pString);
   }*/
   void String::resize(int newCapacity) {
       char* temp = new char[newCapacity];
       strcpy(temp, m_pString);
	   delete[] m_pString;
       m_pString = new char[newCapacity];
	   strcpy(m_pString , temp);
   }

   //////////////////////////////////////////////////////
   //
   // String::~String
   // 
   // destructor
   // 
   // clean up the internal string buffer  
   // 
   String::~String()
   {
      //delete[] m_pString; not yet implemented
   }


   //////////////////////////////////////////////////////
   //
   // String::length()
   // 
   // return the length of the string
   // 
   // 
   int String::length() const
   {
	   if (m_pString == nullptr){
		   char* m_pString = new char[1];
		   strcpy(m_pString, "");
	   }
      int temp = strlen(m_pString);
	  return temp;
   }

   //////////////////////////////////////////////////////
   //
   // String::operator const char*() const
   // 
   // convert the String to a char*
   // 
   // 
   String::operator const char *() const
   {
      return m_pString;
   }

   //////////////////////////////////////////////////////
   //
   // String::empty()
   // 
   // 
   // returns true if the string is empty
   // i.e. either the first char is \0, or 
   // length is 0.
   bool String::empty() const
   {
	  
   //  return (m_pString == nullptr) ? true : false;
	   if (m_pString == nullptr)
		   return true;
	   else
	   return false;
	   
   }

   //////////////////////////////////////////////////////
   //
   // String::operator bool()
   // 
   // same as empty(), just wrapped in an operator
   // 
   //         
   String::operator bool() const
   {
      if (!empty()) {
         return true;
      }
      else {
         return false;
      }
   }


   //////////////////////////////////////////////////////
   //
   // String::operator==(const String& s2) const
   // 
   // returns true if *this == s2.
   // You can use the strcmp function to check if 
   // two strings are equal, or write your own
   // treating the string as a char-array
   //           
   bool String::operator==(const String& s2) const
   {
      return (strcmp(m_pString, s2.m_pString) == 0) ? true : false;
   }


   //////////////////////////////////////////////////////
   //
   // String::operator+=(const String& s2)
   // 
   // Concatenates s2 to the end of *this
   //
   // implements *this = (*this + s2)
   // return *this
   // 
   //         
   String& String::operator+=(const String& s2)
   {
      strcat(m_pString, s2.m_pString);
      return *this;
   }

   //////////////////////////////////////////////////////
   //
   // String::operator+(const String& s2) const
   // 
   // implements the operator (*this + s2)
   // returns the expression
   // DOES NOT MODIFY *this
   // 
   //     
   String String::operator+(const String& s2) const
   {
	   /*int temp = length() + s2.length() + 1;
	   resize(temp);
	   strcat(m_pString, s2.m_pString);
       char* temp = new char[strlen(s2.m_pString)];
       strcpy(temp,"");
      strcpy(temp, this->m_pString);
      char* take = strcat(temp, s2.m_pString);

      return *this;
*/

	   String temp;
	   temp = m_pString;
	   temp += s2;
	   return s2;
   }

   //////////////////////////////////////////////////////
   //
   // String::operator+=(char c)
   // 
   // Adds a single char c to the end of the string in *this
   // 
   //        
   String& String::operator+= (char c)
   {
      int totalLen = strlen(m_pString);
      m_pString[totalLen] = c;
      m_pString[totalLen + 1] = '\0';
      return *this;
   }






   //////////////////////////////////////////////////////
   //
   // operator<<
   // 
   // Print the string to the output stream
   // 
   // clean up the internal string buffer  
   //     
   std::ostream& String::get(std::ostream& ostr) const {
      return ostr << m_pString;

   }
   std::ostream& operator<<(std::ostream& output, const String &s)
   {
      return s.get(output);
   }


   //////////////////////////////////////////////////////
   //
   // operator>>
   // 
   // Input a string from an input stream into the String s
   // 
   // Note: the input can be ANY length in character. You will need to 
   // read it one char at a time. 
   // 
   std::istream& operator >> (std::istream& istream, String &s)
   {
      s = "";
      char tempC = 0;
      do
      {
         tempC = istream.get();
         if (tempC != '\n')
         {
            s += tempC;
         }
         else
            break;
      } while (1);
      return istream;
   }


}