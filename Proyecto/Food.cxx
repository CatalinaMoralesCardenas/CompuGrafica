#include "Food.h"

GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
GLfloat mat_shininess[] = {100.0};

// ----------------------------------------------------------------------
Food::Food( )
  : eaten ( false ),
    pos_x ( 0 ),
    pos_y ( 0 ),
    pos_z ( 0 )
{
}

// ----------------------------------------------------------------------
Food::Food( bool eatenP, int pos_xP, int pos_yP, int pos_zP )
  : eaten ( eatenP ),
    pos_x ( pos_xP ),
    pos_y ( pos_yP ),
    pos_z ( pos_zP )
{
}

// ----------------------------------------------------------------------
bool Food::getEaten( )
{
  return ( this->eaten );
}

// ----------------------------------------------------------------------
int Food::getPos_x( )
{
  return ( this->pos_x );
}

// ----------------------------------------------------------------------
int Food::getPos_y( )
{
  return ( this->pos_y );
}

// ----------------------------------------------------------------------
int Food::getPos_z( )
{
  return ( this->pos_z );
}

// ----------------------------------------------------------------------
void Food::setEaten( bool eaten )
{
  this->eaten = eaten;
}

// ----------------------------------------------------------------------
void Food::setPos_x( int pos_x )
{
  this->pos_x = pos_x;
}

// ----------------------------------------------------------------------
void Food::setPos_y( int pos_y )
{
  this->pos_y = pos_y;
}

// ----------------------------------------------------------------------
void Food::setPos_z( int pos_z )
{
  this->pos_z = pos_z;
}

// ----------------------------------------------------------------------
void Food::drawFood(int type)
{
  glPushMatrix();
  glTranslatef(this->pos_x, this->pos_y, this->pos_z);
  glColor3f(1.0f, 0.0f, 0.0f);
  glColorMaterial(GL_FRONT, GL_DIFFUSE);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  if ( type == 1 )
    glutSolidCube(2.0f);
  else if ( type == 2 )
    glutSolidSphere(2.0f, 50.0f, 50.0f);
  else if ( type == 3 )
    glutSolidCone(1, 2, 50, 50);
  glPopMatrix();
}

// ----------------------------------------------------------------------
void Food::spawnFood(const float map_size, std::deque< std::deque<float> > snake_coords, int food_coords[2] )
{
  if(this->eaten){
        return;
    }

    int temp_food_coords[2];
    bool collides;

    do {
        collides = false;

        // Produce a temporary random coordinate
        temp_food_coords[0] = 2 * (rand() % ((int) map_size + 1)) - (int) map_size;
        temp_food_coords[1] = 2 * (rand() % ((int) map_size + 1)) - (int) map_size;

        // Does it collide with the snake?
        for(unsigned int a = 0; a < snake_coords.size(); a++){
            if(temp_food_coords[0] == snake_coords[a][0] &&
               temp_food_coords[1] == snake_coords[a][1]){
                collides = true;
            }
        }
    } while(collides);

    food_coords[0] = temp_food_coords[0];
    food_coords[1] = temp_food_coords[1];

    this->eaten = true;
}
