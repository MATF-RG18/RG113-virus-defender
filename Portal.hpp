
#if !defined(PORTAL_HPP)
#define PORTAL_HPP
#include "GameObject.hpp"

namespace vd {
class Portal : public GameObject{
    public:
        Portal() : m_hp(100000){    
            m_xyz[0] = m_xyz[1] = 25;    
        }
        void draw() override;
        void update() override;
        void take_damage(GLfloat damage) {
            m_hp -= damage;
            std::cerr << m_hp << '\n';
            if (m_hp <= 0)
                std::cerr << "End!";
        }
        GLfloat get_radius() const { return m_radius; }
    private:
        GLfloat m_hp;
        GLfloat m_radius = 3;
};

}

#endif // PORTAL_HPP
