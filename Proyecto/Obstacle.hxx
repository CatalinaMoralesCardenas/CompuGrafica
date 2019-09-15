#include "Obstacle.h"

// ----------------------------------------------------------------------
Obstacle( )
  : pos_x ( 0 ),
    pos_y ( 0 )
{
}

// ----------------------------------------------------------------------
Obstacle( int pos_xP, int pos_yP )
  : pos_x( pos_xP ),
    pos_y( pos_yP )
{
}

// ----------------------------------------------------------------------
const int getPos_x( )const
{
  return ( this->pos_x);
}

// ----------------------------------------------------------------------
const int getPos_y( )const
{
  return ( this->pos_y);
}

// ----------------------------------------------------------------------
void setPos_x( const int& pos_x )
{
  this->pos_x = pos_x;
}

// ----------------------------------------------------------------------
void setPos_y( const int& pos_)
{
  this->pos_y = pos_y;
}
