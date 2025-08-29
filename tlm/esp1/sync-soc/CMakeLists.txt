add_executable(sync-soc 
    ../simple-soc/Or1ksimExtSC.cpp
    Or1ksimSyncSC.cpp
    syncSocMainSC.cpp
    ../simple-soc/TermSC.cpp
    TermSyncSC.cpp
    ../simple-soc/UartSC.cpp
    UartSyncSC.cpp
    ../logger/Or1ksimSC.cpp
)

target_include_directories(sync-soc
    PUBLIC
        ../logger
        ../simple-soc
)

target_link_libraries(sync-soc 
    systemc
    sim
)