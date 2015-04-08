
#pragma once

#include "base.hpp"

struct Derived : public Base
{
  unsigned int _hh;

  virtual int getType() const {return 0;}
  // Serialization
  template <class Archive>
  void save( Archive & ar) const
  {
    Base::save(ar);
    ar(cereal::make_nvp("hh", _hh));
  }

  // Serialization
  template <class Archive>
  void load( Archive & ar)
  {
    Base::load(ar);
    ar(cereal::make_nvp("hh", _hh));
  }
};

#if defined USE_DERIVED

#include <cereal/types/polymorphic.hpp>
CEREAL_REGISTER_TYPE_WITH_NAME(Derived, "derived");

#endif
