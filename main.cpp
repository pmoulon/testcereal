
#define USE_DERIVED 1

#include "base.hpp"
#include "derived.hpp"
#include <iostream>
#include <fstream>

#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/archives/json.hpp>

int main(int argc, char **argv)
{

  std::shared_ptr<Base> test = std::make_shared<Derived>();
  
  std::ofstream stream("foo.txt");

  cereal::JSONOutputArchive archive(stream);
  
#if defined USE_DERIVED
  archive(test);
#endif

  archive(Toto());

  return EXIT_SUCCESS;
}
