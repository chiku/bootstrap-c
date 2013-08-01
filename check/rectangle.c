#include <rectangle.h>

Rectangle Rectangle_New(double width, double height)
{
  Rectangle rectangle = {width, height};
  return rectangle;
}

double Rectangle_Area(Rectangle self)
{
  return self.width * self.height;
}

double Rectangle_Perimeter(Rectangle self)
{
  return 2 * (self.width + self.height);
}

int Rectangle_IsSquare(Rectangle self)
{
  return (self.width == self.height);
}
