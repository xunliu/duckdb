include_directories(../third_party/catch)
include_directories(../third_party/tpce-tool/include)
include_directories(../third_party/sqlite/include)
include_directories(include)

add_subdirectory(api)
add_subdirectory(appender)
add_subdirectory(common)
add_subdirectory(extension)
add_subdirectory(helpers)
add_subdirectory(sql)
add_subdirectory(sqlite)
add_subdirectory(ossfuzz)

if(BUILD_ARROW_ABI_TEST)
  add_subdirectory(arrow)
  target_compile_options(test_arrow PRIVATE "-w")
endif()

if(NOT WIN32 AND NOT SUN)
  if(${BUILD_TPCE})
    add_subdirectory(tpce)
  endif()
  add_subdirectory(persistence)
endif()

add_definitions(-DDUCKDB_ROOT_DIRECTORY="${PROJECT_SOURCE_DIR}")

add_executable(unittest unittest.cpp ${ALL_OBJECT_FILES})

if(BUILD_ARROW_ABI_TEST)
  target_link_libraries(unittest test_arrow)
endif()

if(NOT WIN32 AND NOT SUN)
  target_link_libraries(unittest duckdb test_helpers)
  if(${BUILD_TPCE})
    target_link_libraries(unittest tpce)
  endif()
else()
  target_link_libraries(unittest duckdb_static test_helpers)
endif()

if(${BUILD_TPCH_EXTENSION})
  if(${BUILD_SQLSMITH})
    add_subdirectory(sqlsmith)
  endif()
endif()
