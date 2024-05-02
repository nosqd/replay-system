project('replay_test', 'cpp', 'c')

glad = static_library(
    'glad',
    'ext/glad/src/glad.c',
    include_directories: 'ext/glad/include',
)

raylib = static_library(
    'raylib',
    objects: 'ext/raylib/lib/raylib.lib',
    include_directories: 'ext/raylib/include',
)

imgui = static_library(
    'imgui',
    'ext/imgui/src/imgui.cpp',
    'ext/imgui/src/imgui_demo.cpp',
    'ext/imgui/src/imgui_draw.cpp',
    'ext/imgui/src/imgui_stdlib.cpp',
    'ext/imgui/src/imgui_tables.cpp',
    'ext/imgui/src/imgui_widgets.cpp',

    'ext/imgui/src/imgui_impl_opengl2.cpp',
    'ext/imgui/src/imgui_impl_opengl3.cpp',
    'ext/imgui/src/imgui_impl_win32.cpp',

    include_directories: 'ext/imgui/include'
)

rl_imgui = static_library(
    'rlImgui',
    'ext/rlImgui/src/rlImgui.cpp',
    include_directories: ['ext/rlImgui/include', 'ext/raylib/include', 'ext/imgui/include'],
    link_with: [imgui, raylib],
)

executable(
    'replay-test',
    'src/ReplayTest.cc',


    link_with: [raylib, imgui, glad, rl_imgui],
    link_args: ['-lopengl32', '-lgdi32', '-luser32', '-lwinmm'],
    include_directories: ['ext/imgui/include', 'ext/raylib/include', 'ext/glad/include', 'ext/rlImgui/include'],
)
