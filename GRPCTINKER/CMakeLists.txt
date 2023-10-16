# CMakeList.txt : CMake project for GRPCTINKER, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (GRPCTINKER "GRPCTINKER.cpp" "GRPCTINKER.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GRPCTINKER PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
find_package(Crow CONFIG REQUIRED)
target_link_libraries(GRPCTINKER PRIVATE Crow::Crow)