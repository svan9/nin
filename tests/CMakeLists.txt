find_package(${PROJECT_NAME} QUIET COMPONENTS nin)

add_executable(nin_test "main.cpp")
target_link_libraries(nin_test PUBLIC nin)
target_include_directories(nin_test PUBLIC ${NIN_INCLUDE})