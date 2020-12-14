#include <string>
#include <CL/cl.hpp>
#include "clhelper.h"

class Caesar {
public:
  Caesar();
  std::string caesarify(std::string *stringin, int offset);
private:
  //const char *chars;

  cl::Device device = getFirstDevice();
  cl::Program::Sources sources = getSourcesFromFile("caesar.cl");
  cl::Context context = cl::Context({device});
  cl::Program program = cl::Program(context, sources);
};
