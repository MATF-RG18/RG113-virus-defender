#include "KeyboardAction.hpp"
#include<iostream>
namespace vd {

    void KeyboardAction::operator()(unsigned key, int x, int y) {
        switch (key) {   
            case '1': return on_1(x,y);
            case '2': return on_2(x,y);
            case '3': return on_3(x,y);
            case '4': return on_4(x,y);

            // case 'w': return on_w(x,y);
            // case 'a': return on_a(x,y);
            // case 's': return on_s(x,y);
            // case 'd': return on_d(x,y);
        }
    }

    void KeyboardAction::on_1(int x,int y){
        std::cerr << '1';
    }
    void KeyboardAction::on_2(int x,int y){
        std::cerr << '2';        
    }
    void KeyboardAction::on_3(int x,int y){
        std::cerr << '3';        
        
    }
    void KeyboardAction::on_4(int x,int y){
        std::cerr << '4';        
        
    }
    void KeyboardAction::on_w(int x,int y){
        std::cerr << 'w';        
     
    }
    void KeyboardAction::on_a(int x,int y){
        std::cerr << 'a';        
       
        
    }
    void KeyboardAction::on_s(int x,int y){
        std::cerr << 's';        
      
        
    }
    void KeyboardAction::on_d(int x,int y){
        std::cerr << 'd';        
      
    }

}