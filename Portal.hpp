
#if !defined(PORTAL_HPP)
#define PORTAL_HPP
#include "GameObject.hpp"

namespace vd {
class Portal : public GameObject{
    public:
        Portal() {    
            m_xyz[0] = m_xyz[1] = m_xyz[2] = 0;    
        }
        void draw() override;
        void update() override;

    private:
        float m_hp;
};

}

#endif // PORTAL_HPP
