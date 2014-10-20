#ifndef _Game
#define _Game
#include "pieces/Piece.h"

class Game{
  static const int width = 10;
  static const int height = 16;
  
  int score;
  Color board[height][width];

  Piece currentPiece;

  
  public:
  Game();
  std::vector< std::vector<Color> > getBoard();
  void stepDown();
  void stepRight();
  void stepLeft();

  void rotateLeft();
  void rotateRight();

  int getScore();
  
  bool isGameOver();

  private:
  bool checkDown();
  bool inBound(int i,int j);
  Piece getRandomPiece();
  void fixCurrentPiece();

};
#endif
