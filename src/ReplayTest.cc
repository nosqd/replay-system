#include <iostream>
#include <glad/glad.h>
#include <raylib.h>
#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_raylib.h>

bool running = false;
bool isAboutMenu = false;

int main(int argc, char *argv[])
{
    InitWindow(1280, 720, "Hello, world!");

    // imgui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    // imgui style
    ImGui::StyleColorsDark();

    // init imgui impl
    ImGui_ImplWin32_InitForOpenGL(GetWindowHandle());
    ImGui_ImplRaylib_Init();
    Imgui_ImplRaylib_BuildFontAtlas();

    running = true;
    while (running)
    {
        if (WindowShouldClose())
        {
            running = false;
        }
        BeginDrawing();
        ImGui_ImplRaylib_ProcessEvents();

        ClearBackground(BLACK);
        DrawText("Hello, world", GetRenderWidth() / 2 - MeasureText("Hello, world", 20) / 2, GetRenderHeight() / 2 - 10, 20, RAYWHITE);

        // imgui starts here
        ImGui_ImplRaylib_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::BeginMainMenuBar();
        if (ImGui::MenuItem("About##MenuItem"))
        {
            isAboutMenu = true;
        }
        if (ImGui::MenuItem("Quit##MenuItem"))
        {
            running = false;
        }
        ImGui::EndMainMenuBar();

        ImVec2 center = ImGui::GetMainViewport()->GetCenter();
        ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
        if (isAboutMenu)
        {
            ImGui::Begin("About##Window", &isAboutMenu);
            ImGui::Text("replay-test v0");
            ImGui::Text("ImGui: %s", IMGUI_VERSION);
            ImGui::Text("Raylib: %s", RAYLIB_VERSION);
            ImGui::Separator();
            if (ImGui::Button("GitHub"))
            {
                OpenURL("https://github.com/nosqd/replay-system");
            }
            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplRaylib_RenderDrawData(ImGui::GetDrawData());
        // ends here

        EndDrawing();
    }

    ImGui_ImplRaylib_Shutdown();
    ImGui_ImplWin32_Shutdown();
    CloseWindow();

    return 0;
}