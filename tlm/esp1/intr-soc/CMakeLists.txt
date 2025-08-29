add_executable(intr-soc 
    ../simple-soc/Or1ksimExtSC.cpp
    ../sync-soc/Or1ksimSyncSC.cpp
    ../simple-soc/TermSC.cpp
    ../sync-soc/TermSyncSC.cpp
    ../simple-soc/UartSC.cpp
    ../sync-soc/UartSyncSC.cpp
    ../logger/Or1ksimSC.cpp
    intrSocMainSC.cpp
    Or1ksimDecoupSC.cpp
    Or1ksimIntrSC.cpp
    UartDecoupSC.cpp
    UartIntrSC.cpp
)

target_include_directories(intr-soc
    PUBLIC
        ../logger
        ../simple-soc
        ../sync-soc
)

target_link_libraries(intr-soc
    systemc
    sim
)