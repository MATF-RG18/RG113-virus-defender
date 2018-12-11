
#if !defined(KEYBOARD_ACTION_HPP)
#define KEYBOARD_ACTION_HPP

#include "Camera.hpp"
#include<functional>
namespace vd {
class KeyboardAction {
    public:
        KeyboardAction(Camera &camera) : m_camera(camera) {}
        void operator()(unsigned key, int x, int y);

             
    private:
        Camera &m_camera;

        void on_1(int x,int y);  
        void on_2(int x,int y);    
        void on_3(int x,int y);   
        void on_4(int x,int y);   
        void on_w(int x,int y);  
        void on_a(int x,int y); 
        void on_s(int x,int y);
        void on_d(int x,int y); 
};
}

#endif // KEYBOARD_ACTION_HPP
