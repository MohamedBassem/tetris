#include <vector>
#include "../Color.h"

class Piece{
  
  public:
    int width;
    int height;
    int posi;
    int posj;
    int orientation;
    Color color;

    Piece(int i,int j);
    Piece();
    std::vector< std::vector<Color> > getPieceShape();
};
