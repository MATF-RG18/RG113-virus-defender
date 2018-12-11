

#if !defined(GAMEOBJECT_HPP)
#define GAMEOBJECT_HPP

namespace vd {
class GameObject {
    public:
        virtual void update() = 0;
        virtual void draw() = 0;
    protected:
        float m_xyz[3];
};

}

#endif // GAMEOBJECT_HPP
