#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include "GreeterClient.h"
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>


ABSL_FLAG(std::string, target, "172.21.242.34:30000", "Server address");


int main(int argc, char** argv) {
    //absl::ParseCommandLine(argc, argv);
    //std::string target_str = absl::GetFlag(FLAGS_target);

    //GreeterClient greeter(
    //    grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

    //// Spawn reader thread that loops indefinitely
    //std::thread thread_ = std::thread(&GreeterClient::AsyncCompleteRpc, &greeter);



    //std::string message = "";

    //std::cout << "Press control-c to quit" << std::endl << std::endl;

    //while (true) 
    //{
    //    //std::getline(std::cin, message);
    //    //greeter.SayHello(message);  // The actual RPC call!
    //}

    if (!glfwInit())
        return 1;

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Your ImGui code here
        ImGui::Begin("Hello, world!");
        ImGui::Text("This is a simple ImGui application.");
        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}