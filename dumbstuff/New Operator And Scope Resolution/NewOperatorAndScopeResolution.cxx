#include <string.h>

class CName {
public:
   enum {
      sizeOfBuffer = 256
   };

   char m_szFirst[sizeOfBuffer];
   char m_szLast[sizeOfBuffer];

public:
   void SetName(char* pszFirst, char* pszLast) {
     strcpy_s(m_szFirst, sizeOfBuffer, pszFirst);
     strcpy_s(m_szLast, sizeOfBuffer, pszLast);
   }

};

int main() {
   // Allocate memory for the array
   char* pCharArray = new char[CName::sizeOfBuffer];
   strcpy_s(pCharArray, CName::sizeOfBuffer, "Array of characters");

   // Deallocate memory for the array
   delete [] pCharArray;
   pCharArray = NULL;

   // Allocate memory for the object
   CName* pName = new CName;
   pName->SetName("Firstname", "Lastname");

   // Deallocate memory for the object
   delete pName;
   pName = NULL;
}

/* So this is an example program this page: https://docs.microsoft.com/en-us/cpp/cpp/new-operator-cpp?view=vs-2019
 * 
 * It explains the new operator. I was getting caugt up on line 22 though.
 * So the "::" is called the scope resolution operator. Normally I thought
 * of namespaces while using it, but in retrospect things like the streambuffer
 * classes would often require use of the "::". So it seems like you can
 * store constant "literals" (like '2', 'h', etc.) in classes, for things like
 * the max size of an array for that class etc. you can store them there. But,
 * how'd you access them before you've created an object of that class? You
 * use the scope resolution operator "::".
 * 
 * I think the purpose in this particular usage is to be able to store const
 * literals that are specific to your class within that class (or that class's
 * namespace... oooh), and then to be able to access it. So the usage arrises
 * out of an organizational desire.*/
