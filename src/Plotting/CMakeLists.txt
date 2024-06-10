include(sciplot.cmake)

set(PLOTS
    ReactionDrawer.cpp
    TrajectoryDrawer.cpp
    Point.cpp
    Point.h
)

add_library(SpStochLibPlots ${PLOTS})
target_link_libraries(SpStochLibPlots PUBLIC sciplot)