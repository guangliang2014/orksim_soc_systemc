add_executable(logger_test 
    Or1ksimSC.cpp
    LoggerSC.cpp
    loggerMainSC.cpp
)


target_link_libraries(logger_test 
    systemc
    sim
)

