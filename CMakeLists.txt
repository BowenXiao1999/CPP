cmake_minimum_required(VERSION 3.13)
project(CPP)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE MAIN_SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")

foreach(src ${MAIN_SOURCES})
    # Create a human readable name.
    get_filename_component(output ${src} NAME)
    string(REPLACE ".cpp" "" foutput ${output})

    add_executable(${foutput} EXCLUDE_FROM_ALL ${src})

    set_target_properties(${foutput}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
    COMMAND ${foutput}
    )
endforeach(src ${MAIN_SOURCES})

#add_executable(typedef Magics/alias/typedef.cpp)
#add_executable(stack Magics/stack.cpp)
#add_executable(hasptr Chapter13/13.1/13.5.cpp)
#add_executable(sort Interview/interview/ali/sort.cpp)
#add_executable(new_sort Interview/interview/ali/new_sort.cpp)
#add_executable(myString Interview/cpp/myString.cpp)
#add_executable(1 Modern_CPP/chapter2/combined_struct.cpp)
#add_executable(structured.binding Modern_CPP/chapter2/structured.binding.cpp)
#add_executable(combined_struct Modern_CPP/chapter2/combined_struct.cpp)
#add_executable(enhance random/MoveSemantics/enhance.cpp)
#add_executable(special CPP_Primer/Chapter16/16.5/specialization.cpp)
#add_executable(bit random/bit/bitoperation.cpp random/bit/asm.cpp)
#add_executable(test random/test.cpp)
add_executable(test CXX/Type/unsigned/unsigned.cpp)

