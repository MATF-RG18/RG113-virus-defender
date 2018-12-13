
#if !defined(VIRUSFACTORY_HPP)
#define VIRUSFACTORY_HPP

#include<GL/glut.h>
#include<vector>
namespace vd {

template<typename T>
class VirusFactory {
    public:
        using iterator = std::vector<T>;
        VirusFactory(GLfloat interval_sec, GLfloat x, GLfloat y, GLfloat z) :
        m_interval_sec(interval_sec), m_x(x), m_y(y),m_update_tick(60 * interval_sec),
        m_virus(x,y,z) {
            
        }
        bool ready() const { return m_remaning_ticks < 0; }
        void update();
        T& get() { 
            m_remaning_ticks = m_update_tick;
            return m_virus;
        }
    private:
        // How many ticks does it take to generate all viruses
        GLfloat m_interval_sec;
        GLfloat m_x, m_y;
        const int m_update_tick;
        int m_remaning_ticks;
        T m_virus;
        
};

template<typename T>
void VirusFactory<T>::update()
{
    if (m_remaning_ticks < 0)
        return;
    --m_remaning_ticks;
}

}




#endif // VIRUSFACTORY_HPP
