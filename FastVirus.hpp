
#if !defined(FASTVIRUS_HPP)
#define FASTVIRUS_HPP

#include "Virus.hpp"
namespace vd {
   class FastVirus : public Virus {
      public:
            void draw() override;
            void update() override;
}; 
}



#endif // FASTVIRUS_HPP
