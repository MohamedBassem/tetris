#include "Piece.h"

class Piece0 : Piece{
  
  int shape[2][4] = {
    {0,0,0,0},
    {1,1,1,1}
  };

  public:

  std::vector< std::vector<Color> > getPieceShape(){
    std::vector< std::vector<Color> > p;
    for(int i=0;i<2;i++){
      p.push_back( std::vector<Color>() );
      for(int j=0;j<4;j++){
        if( shape[i][j] == 0 ){
          p[i].push_back(Color(-1,-1,-1));
        }else{
          p[i].push_back(color);
        }
      }
    }
    return p;
  }

};
