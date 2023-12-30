#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include "GreeterClient.h"


ABSL_FLAG(std::string, target, "172.21.242.34:30000", "Server address");


int main(int argc, char** argv) {
    absl::ParseCommandLine(argc, argv);
    std::string target_str = absl::GetFlag(FLAGS_target);

    GreeterClient greeter(
        grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

    // Spawn reader thread that loops indefinitely
    std::thread thread_ = std::thread(&GreeterClient::AsyncCompleteRpc, &greeter);

    std::string message = "";

    std::cout << "Press control-c to quit" << std::endl << std::endl;

    while (true) 
    {
        std::getline(std::cin, message);
        greeter.SayHello(message);  // The actual RPC call!
    }

    return 0;
}