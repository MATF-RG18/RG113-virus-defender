#include "KeyboardAction.hpp"
#include<iostream>
namespace vd {

    void KeyboardAction::key_down(unsigned key, int x, int y) {
        switch (key) {   
            case '1': on_1_down(x,y); break;
            case '2': on_2_down(x,y); break;
            case '3': on_3_down(x,y); break;
            case '4': on_4_down(x,y); break;

            case 'w': return on_w_down(x,y); break; 
            case 'a': return on_a_down(x,y); break;
            case 's': return on_s_down(x,y); break;
            case 'd': return on_d_down(x,y); break;
        }
    }
    void KeyboardAction::key_up(unsigned key, int x, int y) {
        switch (key) {   
            // case '1': on_1_up(x,y); break;
            // case '2': on_2_up(x,y); break;
            // case '3': on_3_up(x,y); break;
            // case '4': on_4_up(x,y); break;

            case 'w': on_w_up(x,y); break;
            case 'a': on_a_up(x,y); break;
            case 's': on_s_up(x,y); break;
            case 'd': on_d_up(x,y); break;
        }
    }

    void KeyboardAction::on_1_down(int x,int y){
        std::cerr << '1';
    }
    void KeyboardAction::on_2_down(int x,int y){
        std::cerr << '2';        
    }
    void KeyboardAction::on_3_down(int x,int y){
        std::cerr << '3';        
        
    }
    void KeyboardAction::on_4_down(int x,int y){
        std::cerr << '4';        
        
    }
    void KeyboardAction::on_w_down(int x,int y){
        std::cerr << 'w';        
        m_camera.start_moving_north();
    }
    void KeyboardAction::on_a_down(int x,int y){
        std::cerr << 'a';        
        m_camera.start_moving_west();
    }
    void KeyboardAction::on_s_down(int x,int y){
        std::cerr << 's';   
        m_camera.start_moving_south();         
    }
    void KeyboardAction::on_d_down(int x,int y){
        std::cerr << 'd';        
        m_camera.start_moving_east();
      
    }

    void KeyboardAction::on_w_up(int x,int y){
        std::cerr << 'w';        
        m_camera.stop_moving_north();
    }
    void KeyboardAction::on_a_up(int x,int y){
        std::cerr << 'a';  
        m_camera.stop_moving_west();      
    }
    void KeyboardAction::on_s_up(int x,int y){
        std::cerr << 's';      
        m_camera.stop_moving_south();      
    }
    void KeyboardAction::on_d_up(int x,int y){
        std::cerr << 'd';        
        m_camera.stop_moving_east();
    }


}