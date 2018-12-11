#include "PassiveMouseMotionAction.hpp"
#include<iostream>
namespace vd {

    void PassiveMouseMotionAction::operator()(int x, int y) {
        std::cerr << x << ' ' << y << '\n';
    }


}