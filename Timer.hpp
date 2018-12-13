
#if !defined(TIMER_HPP)
#define TIMER_HPP



namespace vd {

class Timer {
    public:
        Timer(int msec_update, int timer_id) :
        m_msec_update(msec_update), m_timer_id(timer_id) {}
        int get_msec_update() { return m_msec_update; }
        int get_timer_id() { return m_timer_id; }
    private:
        const int m_msec_update;
        const int m_timer_id;
};


}



#endif // TIMER_HPP
