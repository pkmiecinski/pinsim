cmake_minimum_required (VERSION 3.24)

project(pinsim
  LANGUAGES CXX
  VERSION 1.0.0
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/arthursonzogni/ftxui.git
  GIT_TAG        v5.0.0
  GIT_PROGRESS   TRUE
  GIT_SHALLOW    TRUE
  EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(ftxui)
# ------------------------------------------------------------------------------

SET (RPISIM_SOURCES 
${CMAKE_SOURCE_DIR}/src/rpisim/model/cpin.cpp
${CMAKE_SOURCE_DIR}/src/rpisim/model/model.cpp
${CMAKE_SOURCE_DIR}/src/rpisim/view/view.cpp
${CMAKE_SOURCE_DIR}/src/rpisim/controller/controller.cpp
${CMAKE_SOURCE_DIR}/src/rpisim/app/rpisim.cpp
)

SET (RPISIM_HEADERS
${CMAKE_SOURCE_DIR}/src/rpisim/model/cpin.hpp
${CMAKE_SOURCE_DIR}/src/rpisim/model/model.hpp
${CMAKE_SOURCE_DIR}/src/rpisim/view/view.hpp
${CMAKE_SOURCE_DIR}/src/rpisim/controller/controller.hpp
${CMAKE_SOURCE_DIR}/src/rpisim/app/rpisim.hpp
)


add_executable(pinsim ${RPISIM_SOURCES} src/main.cpp)

target_include_directories(pinsim PRIVATE RPISIM_HEADERS)

target_link_libraries(pinsim
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component  
)

# --- Fetch JSON --------------------------------------------------------------
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(pinsim PRIVATE nlohmann_json::nlohmann_json)