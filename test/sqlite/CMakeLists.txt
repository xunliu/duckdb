add_extension_definitions()

add_definitions(-DDUCKDB_ROOT_DIRECTORY="${PROJECT_SOURCE_DIR}"
                -DDUCKDB_BUILD_DIRECTORY="${PROJECT_BINARY_DIR}")

add_library_unity(
  test_sqlite
  OBJECT
  result_helper.cpp
  sqllogic_command.cpp
  sqllogic_test_runner.cpp
  test_sqllogictest.cpp
  sqllogic_parser.cpp)
set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:test_sqlite>
    PARENT_SCOPE)
