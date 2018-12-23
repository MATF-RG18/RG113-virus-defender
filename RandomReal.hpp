
#if !defined(RANDOM_REAL_HPP)
#define RANDOM_REAL_HPP

#include <random>
namespace vd {

class RandomReal {
public:
  RandomReal(float a, float b) : m_gen(m_rd()), m_ureal(a, b) {}
  float operator()() { return m_ureal(m_gen); }

private:
  std::random_device m_rd;
  std::mt19937 m_gen;
  std::uniform_real_distribution<> m_ureal;
};

} // namespace vd
#endif // RANDOM_REAL_HPP
