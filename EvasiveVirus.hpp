
#if !defined(EVASIVEVIRUS_HPP)
#define EVASIVEVIRUS_HPP

#include "Virus.hpp"

namespace vd {
class EvasiveVirus : public Virus {
    public:
        void draw() override;
        void update() override;
};
}



#endif // EVASIVEVIRUS_HPP
