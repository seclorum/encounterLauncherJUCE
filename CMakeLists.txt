cmake_minimum_required(VERSION 3.15)

project(EncounterLauncher VERSION 1.0)

# JUCE Setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(FetchContent)
FetchContent_Declare(
  juce
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(juce)

# Add executable target
juce_add_gui_app(
  EncounterLauncher
  PRODUCT_NAME "EncounterLauncher"
)

# Add source files
target_sources(EncounterLauncher
  PRIVATE
    Source/Main.cpp
    Source/MainComponent.cpp
)

# Link JUCE module
target_link_libraries(EncounterLauncher
  PRIVATE
    juce::juce_gui_extra
)
