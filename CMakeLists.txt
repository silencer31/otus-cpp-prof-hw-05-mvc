cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(mvc_example VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)

#Main target 
add_executable(mvc_example main.cpp  "Models/documents_model.cpp" "Models/graphics_model.cpp" "View/graphics_view.cpp" "View/documents_view.cpp" "Controller/GraphicsController.cpp" "Controller/DocumentsController.cpp")
add_library(lib_mvc_example lib.cpp  "Models/documents_model.cpp" "Models/graphics_model.cpp" "View/graphics_view.cpp" "View/documents_view.cpp" "Controller/GraphicsController.cpp" "Controller/DocumentsController.cpp")

set_target_properties(mvc_example lib_mvc_example PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(lib_mvc_example
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(mvc_example PRIVATE
    lib_mvc_example
)

if (MSVC)
    target_compile_options(mvc_example PRIVATE
        /W4
    )
    target_compile_options(lib_mvc_example PRIVATE
        /W4
    )
else ()
    target_compile_options(mvc_example PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(lib_mvc_example PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS mvc_example RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()