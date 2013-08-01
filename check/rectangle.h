#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

typedef struct Rectangle Rectangle;

struct Rectangle
{
  double width;
  double height;
};

Rectangle Rectangle_New(double width, double height);

double Rectangle_Area(Rectangle self);
double Rectangle_Perimeter(Rectangle self);
int Rectangle_IsSquare(Rectangle self);

#endif
