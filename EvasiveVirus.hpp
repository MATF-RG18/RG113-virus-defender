
#if !defined(EVASIVEVIRUS_HPP)
#define EVASIVEVIRUS_HPP

#include "Virus.hpp"

namespace vd {
class EvasiveVirus : public Virus {
    public:
        EvasiveVirus(GLfloat x = 0, GLfloat y = 0, GLfloat z= 0) : Virus(x,y,z,
        HP, SPEED, RADIUS) {
                set_color(1, 0, 0);
        }
        void draw() override;
        void update() override;
    private:
        static constexpr GLfloat HP {100};
        static constexpr GLfloat RADIUS{0.1};
        static constexpr GLfloat SPEED{ 0.04};
};
}



#endif // EVASIVEVIRUS_HPP
