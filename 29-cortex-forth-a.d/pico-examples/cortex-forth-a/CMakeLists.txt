add_executable(cortex-forth-a
        cortex-forth-a.c
        )

# target_link_libraries(cortex-forth-a forth pico-LED pico_stdlib)
# add_library(Cortex-Forth Cortex-Forth.c)
# target_link_libraries(cortex-forth-a Cortex-Forth pico_stdlib)
target_link_libraries(cortex-forth-a Cortex-Forth pico_stdlib)

pico_enable_stdio_usb(cortex-forth-a 1)
pico_enable_stdio_uart(cortex-forth-a 1) # was zero

pico_add_extra_outputs(cortex-forth-a)

example_auto_set_url(cortex-forth-a)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

add_subdirectory(Cortex-Forth)
# add_subdirectory(pico-hw)
