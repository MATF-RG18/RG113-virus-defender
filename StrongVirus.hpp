
#if !defined(STRONGVIRUS_HPP)
#define STRONGVIRUS_HPP

#include "Virus.hpp"

namespace vd {
    class StrongVirus : public Virus {
        public:
            StrongVirus(GLfloat x, GLfloat y, GLfloat z) : Virus(x,y,z,
            300, 0.1, 0.6) {
                set_color(1, 0, 0);
            }
            void draw() override;
            void update() override;
    };
}


#endif // STRONGVIRUS_HPP
