set(BENCHMARK_FILES
        Benchmarks.cpp
)

foreach(BENCHMARK_FILE ${BENCHMARK_FILES})
    get_filename_component(BENCHMARK_NAME ${BENCHMARK_FILE} NAME_WE)
    add_executable(${BENCHMARK_NAME} ${BENCHMARK_FILE})
    target_link_libraries(${BENCHMARK_NAME} PRIVATE SpStochLib benchmark::benchmark)
endforeach()