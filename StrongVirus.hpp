
#if !defined(STRONGVIRUS_HPP)
#define STRONGVIRUS_HPP

#include "Virus.hpp"

namespace vd {
    class StrongVirus : public Virus {
        public:
            StrongVirus(GLfloat x = 0, GLfloat y = 0, GLfloat z= 0) : Virus(x,y,z,
            HP, SPEED, RADIUS) {
                set_color(1, 0, 0);
            }
            void draw() override;
            void update() override;
        private:
            static constexpr GLfloat HP {600};
            static constexpr GLfloat RADIUS{0.3};
            static constexpr GLfloat SPEED{ 0.01};
    };
}


#endif // STRONGVIRUS_HPP
