#include "pieces/Piece.h"

class Game{
  static const int width = 10;
  static const int height = 16;
  
  int score = 0;
  Color board[height][width];

  Piece currentPiece;

  
  public:
  Game();
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

};
