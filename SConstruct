#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/", "CudNN/"])
sources = Glob("src/*.cpp")
env.Append(CPPDEFINES=['HEADER_ONLY'])
env.Append(CXXFLAGS=["-fPIC"])
env.Append(LINKFLAGS=["-fPIC", "-no-pie"])

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "build/NN.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "build/NN.{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
        LIBS='NN',
        LIBPATH='./CudNN/build',
    )
env.Depends(library, "CudNN/NN_constructor.h")
env.Depends(library, "CudNN/NN.h")
env.Depends(library, "CudNN/kernel_macros.h")
env.Depends(library, "CudNN/neuron_operations.cuh")
env.Depends(library, "CudNN/costs.cuh")

Default(library)
