
#if !defined(MATERIALDRAWER_HPP)
#define MATERIALDRAWER_HPP

class MaterialProperties;

class MaterialDrawer {
  void set(const MaterialProperties &m);
  void draw();
};

#endif // MATERIALDRAWER_HPP
