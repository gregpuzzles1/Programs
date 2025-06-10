# Search for all source files in the current directory
# and save the names to the DIR_examples_SRCS variable
aux_source_directory(. DIR_examples_SRCS)

# Add header file directory
include_directories(../lib/Config)
include_directories(../lib/LCD1602)


# Generate link library
add_library(examples ${DIR_examples_SRCS})
target_link_libraries(examples PUBLIC Config LCD1602)