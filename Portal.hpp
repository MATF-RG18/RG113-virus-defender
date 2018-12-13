
#if !defined(PORTAL_HPP)
#define PORTAL_HPP
#include "GameObject.hpp"
#include "GameVariables.hpp"
namespace vd {
class Portal : public GameObject{
    public:
        Portal() {    
            m_xyz[0] = m_xyz[1] = 25;    
        }
        void draw() override;
        void update() override;
        void take_damage(GLfloat damage) {
            GameVariables::PORTAL_HP -= damage;
            std::cerr << GameVariables::PORTAL_HP<< '\n';
            if (GameVariables::PORTAL_HP<= 0)
                std::cerr << "End!";
        }
        GLfloat get_radius() const { return m_radius; }
    private:
        GLfloat m_radius = 3;
};

}

#endif // PORTAL_HPP
