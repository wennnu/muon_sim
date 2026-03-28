cmake_minimum_required(VERSION 4.2 FATAL_ERROR)

project(Muon_Simulation)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(muon_sim main.cpp ${sources} ${headers})
target_link_libraries(muon_sim ${Geant4_LIBRARIES})

add_custom_target(Muon_Simulation depends muon_sim)
