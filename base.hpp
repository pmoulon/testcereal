
#pragma once

#include <cereal/cereal.hpp>

struct Base
{
  unsigned int _w, _h;

  void test() { std::cout << " test" << std::endl; }
  virtual int getType() const = 0;

  /// Serialization out
  template <class Archive>
  void save( Archive & ar) const
  {
    ar(cereal::make_nvp("width", _w));
    ar(cereal::make_nvp("height", _h));
  }

  /// Serialization in
  template <class Archive>
  void load( Archive & ar)
  {
    ar(cereal::make_nvp("width", _w));
    ar(cereal::make_nvp("height", _h));
  }
};

struct Toto
{
  unsigned int _w, _h;

  /// Serialization out
  template <class Archive>
  void save( Archive & ar) const
  {
    ar(cereal::make_nvp("width", _w));
    ar(cereal::make_nvp("height", _h));
  }

  /// Serialization in
  template <class Archive>
  void load( Archive & ar)
  {
    ar(cereal::make_nvp("width", _w));
    ar(cereal::make_nvp("height", _h));
  }
};
