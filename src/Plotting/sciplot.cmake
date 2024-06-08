include(FetchContent) # If not included already

FetchContent_Declare(sciplot_content
        GIT_REPOSITORY https://github.com/sciplot/sciplot.git
        GIT_TAG master)

FetchContent_GetProperties(sciplot_content)
if(NOT sciplot_content_POPULATED)
    FetchContent_Populate(sciplot_content)
    add_subdirectory(${sciplot_content_SOURCE_DIR} ${sciplot_content_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

include_directories(${sciplot_content_SOURCE_DIR})