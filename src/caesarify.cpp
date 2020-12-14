#include <iostream>
#include "caesarify.h"

Caesar::Caesar() {
  auto build_error = program.build();

  if (build_error != 0) {
    std::cout << "BUILD ERROR: " << build_error << std::endl;
    std::string log;
    program.getBuildInfo(device, CL_PROGRAM_BUILD_LOG, &log);
    std::cout << log << std::endl;
  }
}

std::string Caesar::caesarify(std::string *stringin, int offset) {
  //const char *chars = stringin->c_str();
  char chars[stringin->length()];
  strcpy(chars, stringin->c_str());
 
  cl::Buffer strBuf(context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, sizeof(chars), &chars);
  cl::Buffer argument(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, sizeof(int), &offset);

  cl::Kernel kernel(program, "caesar");

  kernel.setArg(0, strBuf);
  kernel.setArg(1, argument);

  cl::CommandQueue queue(context, device);

  queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(strlen(chars)));
  queue.enqueueReadBuffer(strBuf, false, 0, sizeof(chars), &chars);

  queue.finish();

  return std::string(chars);
}
