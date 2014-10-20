#ifndef _Color
#define _Color
class Color{
  public:
  int r,g,b;
  
  Color();
  Color(int r,int g, int b);
  static bool isEmpty(Color c);
};
#endif
