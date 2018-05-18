#ifndef HALIDE_PYTHON_EXTENSION_GEN_H_
#define HALIDE_PYTHON_EXTENSION_GEN_H_

#include <string>
#include "Target.h"

using std::string;

namespace Halide {

class Module;
struct Target;

namespace Internal {

class PythonExtensionGen {
public:
    PythonExtensionGen(std::ostream &dest, const std::string &header_name, Target target);

    void compile(const Module &module);
    void compile(const LoweredFunc &f);
private:
    void convert_buffer(string name, const LoweredArgument* arg);
    std::ostream &dest;
    std::string header_name;
    Target target;
};

}
}

#endif // HALIDE_PYTHON_EXTENSION_GEN_H_
