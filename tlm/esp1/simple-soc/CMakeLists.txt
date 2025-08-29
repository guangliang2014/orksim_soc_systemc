add_executable(simple-soc 
    Or1ksimExtSC.cpp
    simpleSocMainSC.cpp
    TermSC.cpp
    UartSC.cpp
    ../logger/Or1ksimSC.cpp
)

target_include_directories(simple-soc
    PUBLIC
        ../logger
)

target_link_libraries(simple-soc 
    systemc
    sim
)