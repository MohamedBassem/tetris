#ifndef _Game
#define _Game
#include "pieces/Piece.h"
#include "pieces/Piece0.h"
#include "pieces/Piece1.h"
#include "pieces/Piece2.h"
#include "pieces/Piece3.h"
#include "pieces/Piece4.h"
#include "pieces/Piece5.h"
#include "pieces/Piece6.h"

class Game{
  static const int width = 10;
  static const int height = 16;
  
  int score;
  Color board[height][width];
  bool _isGameOver;

  Piece* currentPiece;

  
  public:
  Game();
  std::vector< std::vector<Color> > getBoard();
  void stepDown();
  void stepRight();
  void stepLeft();

  void rotateLeft();
  void rotateRight();

  int getScore();
  bool isIntersect();
  bool isGameOver();
  int getWidth();
  int getHight();

  private:
  bool checkDown();
  bool inBound(int i,int j);
  Piece* getRandomPiece();
  void fixCurrentPiece();
  void removeFullRows();

};
#endif
