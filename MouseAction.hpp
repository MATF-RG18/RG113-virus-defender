

#if !defined(MouseAction_HPP)
#define MouseAction_HPP

#include "Cursor.hpp"
namespace vd {

/*
  Callback funkcije za pritisak dugmenta misa
*/
class MouseAction {
public:
  MouseAction(Cursor &cursor) : m_cursor(cursor) {}
  void on_left_click_down();
  void on_right_click_down();

private:
  Cursor &m_cursor;
};
} // namespace vd

#endif // MouseAction_HPP
