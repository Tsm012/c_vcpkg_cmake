# CMakeList.txt : CMake project for GRPCTINKER, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Main "Main.cpp" "Main.h" "Proto/Generated/helloworld.grpc.pb.cc" "Proto/Generated/helloworld.pb.cc")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Main PROPERTY CXX_STANDARD 20)
endif()

find_package(absl CONFIG REQUIRED)
target_link_libraries(Main PRIVATE  absl::flags_parse)

find_package(gRPC CONFIG REQUIRED)
target_link_libraries(Main PRIVATE gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts gRPC::grpc++_error_details gRPC::grpc++_reflection gRPC::grpc++_unsecure)

find_package(protobuf CONFIG REQUIRED)
target_link_libraries(Main PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)