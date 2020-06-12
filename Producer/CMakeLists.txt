add_executable(Producer
        main.cpp
        Camera/Camera.cpp
        Camera/Camera.h
        ../Communication/Connection.cpp
        ../Communication/MessageQueueConnection.cpp
        ../Communication/SharedMemoryConnection.cpp
        )

target_link_libraries( Producer ${OpenCV_LIBS} -lrt )


