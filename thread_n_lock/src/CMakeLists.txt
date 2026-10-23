add_library(threading_functions STATIC 
    threads.cpp    
)

target_include_directories(threading_functions PUBLIC ${PROJECT_SOURCE_DIR}/inc)