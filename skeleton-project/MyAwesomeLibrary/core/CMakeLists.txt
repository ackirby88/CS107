# =======================================
# Source directories for this project
set(src_path src)
add_subdirectory(${src_path})
# =======================================

# =======================================
# Unit Testing Option - uses Google Test
OPTION(UNIT_TEST "build unit tests" ON)
if(UNIT_TEST)
  include_directories(${src_path})
  add_subdirectory(tests)
endif()
# =======================================
