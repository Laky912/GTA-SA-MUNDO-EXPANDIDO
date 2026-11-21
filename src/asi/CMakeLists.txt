cmake_minimum_required(VERSION 3.20)
project(MundoExpandidoASI LANGUAGES C CXX)

if(NOT WIN32)
  message(FATAL_ERROR "MundoExpandidoASI solo se compila para Windows.")
endif()
if(NOT CMAKE_SIZEOF_VOID_P EQUAL 4)
  message(FATAL_ERROR "GTA San Andreas clásico requiere un plugin ASI x86/Win32.")
endif()

include(FetchContent)
FetchContent_Declare(
  minhook
  GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
  GIT_TAG v1.3.4
)
FetchContent_MakeAvailable(minhook)

add_library(MundoExpandidoASI SHARED src/asi/MenuModes.cpp)
target_compile_features(MundoExpandidoASI PRIVATE cxx_std_17)
target_compile_definitions(MundoExpandidoASI PRIVATE WIN32_LEAN_AND_MEAN)
target_link_libraries(MundoExpandidoASI PRIVATE minhook)
set_target_properties(MundoExpandidoASI PROPERTIES
  PREFIX ""
  SUFFIX ".asi"
  OUTPUT_NAME "MundoExpandido"
)
