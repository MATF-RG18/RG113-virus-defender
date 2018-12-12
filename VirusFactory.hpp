
#if !defined(VIRUSFACTORY_HPP)
#define VIRUSFACTORY_HPP

#include<GL/glut.h>
namespace vd {

template<size_t min_num, size_t max_num>
class VirusFactory {
    public:
        VirusFactory(int tick_interval, int group_number, GLfloat x, GLfloat y);

        
    private:
        int m_tick_interval;
        static std::array<max_num - min_num, std::unique_ptr<Virus>>

};

}


#endif // VIRUSFACTORY_HPP
