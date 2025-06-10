# Search for all source files in the current directory
# and save the names to the DIR_LCD_SRCS variable
aux_source_directory(. DIR_LCD_SRCS)

include_directories(../Config)

# Generate link library
add_library(LCD1602 ${DIR_LCD_SRCS})
target_link_libraries(LCD1602 PUBLIC Config)