#include "Color.h"

Color::Color(int r,int g, int b){
  this->r = r;
  this->g = g;
  this->b = b;
}

Color::Color(){}

bool Color::isEmpty( Color c ){
  return c.r == -1 && c.g == -1 && c.b == -1;
}
