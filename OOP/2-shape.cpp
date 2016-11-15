#include <iostream>
 
using namespace std;

// Base class
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
      virtual int getArea()
      {

      }
   protected:
      int width;
      int height;
};

// Derived class
class Rectangle: public Shape
{
   public:
      static int count;
      Rectangle()
      {
         width = 0;
         height = 0;
      }
      Rectangle(int width, int height)
      {
         this->width = width;
         this->height = height;
      }
      int getArea()
      { 
         return (width * height); 
      }
};

int main(void)
{
   Rectangle Rect(10, 2);

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}