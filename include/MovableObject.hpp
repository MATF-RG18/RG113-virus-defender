

#if !defined(MOVABLE_OBJECT)
#define MOVABLE_OBJECT

#include "GameObject.hpp"

class MovableObject : public GameObject  {
    public:
        virtual void move(float x, float y, float z);    
};


#endif // MOVABLE_OBJECT
