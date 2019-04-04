
#if !defined(WINDOW_HPP)
#define WINDOW_HPP

namespace vd {
/*
  Wrapper klasa oko WindowProzora
.*/
class Window {
public:
  Window() = default;
  Window(int width, int height)
      : m_width(width), m_height(height),
        m_x_region_size(m_region_proportion * width),
        m_y_region_size(m_region_proportion * height), m_x_center(width / 2),
        m_y_center(height / 2) {}

  int get_width() const { return m_width; }
  int get_height() const { return m_height; }

  void set_width(int width) {
    m_width = width;
    m_x_region_size = m_region_proportion * width;
    m_x_center = width / 2;
  }
  void set_height(int height) {
    m_width = height;
    m_y_region_size = m_region_proportion * height;
    m_y_center = height / 2;
  }
  int get_center_x() const { return m_x_center; }
  int get_center_y() const { return m_y_center; }

private:
  // Proportion of the Window that goes to regions
  const float m_region_proportion = 0.1;

  // window size in pixels
  int m_width = 768, m_height = 768;

  // sizes in pixels for WindowRegion definitions
  int m_x_region_size, m_y_region_size;

  // center points
  int m_x_center, m_y_center;
};
} // namespace vd

#endif // WINDOW_HPP
