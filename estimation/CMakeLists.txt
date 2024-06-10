set(ESTIMATION_FILES
    Estimate.cpp
    main.cpp
)

foreach(ESTIMATION_FILE ${ESTIMATION_FILES})
    get_filename_component(FILE_NAME ${ESTIMATION_FILE} NAME_WE)
    add_executable(${FILE_NAME} ${ESTIMATION_FILE})
    target_link_libraries(${FILE_NAME} PRIVATE SpStochLib)
endforeach()