
#if !defined(GAMEOBJECTCONTAINER_HPP)
#define GAMEOBJECTCONTAINER_HPP


#include<vector>
#include<iostream>
namespace  vd{


template<typename T, size_t N>
class GameObjectContainer {
    public:
        GameObjectContainer() : m_objects(N) {}
        void update();
        void draw();
        void insert(const T& object);
    private:
        std::vector<T> m_objects;
        // size_t m_active_count={0};
};

template<typename T, size_t N>
void GameObjectContainer<T,N>::update()
{
    for (auto& o : m_objects) {
        if (o.is_active()) {
            o.update();
        }
    }
}

template<typename T, size_t N>
void GameObjectContainer<T,N>::insert(const T& object)
{
    for (auto &o : m_objects) {
        if (!o.is_active()) {
            o = object;
            o.activate();
            return;
        }
    }
    
    
}
template<typename T, size_t N>
void GameObjectContainer<T,N>::draw()
{
    for (auto& o: m_objects) {
        if (o.is_active()) {
            o.draw();
        }
    }
}   

}
#endif // GAMEOBJECTCONTAINER_HPP
