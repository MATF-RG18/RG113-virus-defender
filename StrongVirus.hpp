
#if !defined(STRONGVIRUS_HPP)
#define STRONGVIRUS_HPP

#include "Virus.hpp"

namespace vd {
    class StrongVirus : public Virus {
        public:
            void draw() override;
            void update() override;
    };
}


#endif // STRONGVIRUS_HPP
