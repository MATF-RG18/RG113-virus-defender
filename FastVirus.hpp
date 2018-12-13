
#if !defined(FASTVIRUS_HPP)
#define FASTVIRUS_HPP
#include<GL/glut.h>
#include "Virus.hpp"
namespace vd {
   class FastVirus : public Virus {
      public:
            FastVirus(GLfloat x =0 , GLfloat y=0, GLfloat z=0) : Virus(x,y,z,
            HP, SPEED, RADIUS) {
                set_color(0, 1, 0);
            }
            void draw() override;
            void update() override;
      private:
         static constexpr GLfloat HP {400};
         static constexpr GLfloat RADIUS{0.2};
         static constexpr GLfloat SPEED{ 0.02};
}; 
}



#endif // FASTVIRUS_HPP
