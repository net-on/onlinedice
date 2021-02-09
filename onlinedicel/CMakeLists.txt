add_executable(onlinedicel.wasm ${CMAKE_CURRENT_SOURCE_DIR}/src/onlinedicel.cpp)
target_include_directories(onlinedicel.wasm
   PUBLIC 
   ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(onlinedicel.wasm
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

add_custom_target(onlinedicel.abi ALL)

set(ABI_FILE "${CMAKE_CURRENT_BINARY_DIR}/onlinedicel.abi")

add_custom_command(
    TARGET onlinedicel.abi
    COMMAND eosiocpp -g  ${ABI_FILE}   "${CMAKE_CURRENT_SOURCE_DIR}/include/onlinedicel.hpp"
)

add_custom_command(TARGET onlinedicel.abi POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${ABI_FILE} "${CMAKE_CURRENT_SOURCE_DIR}/abi/onlinedicel.abi"
)
