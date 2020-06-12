add_executable(Detector
        main.cpp
        Detection/Detector.cpp
        Detection/Detector.h
        ../Communication/Connection.cpp
        ../Communication/Connection.h
        ../Communication/MessageQueueConnection.cpp
        ../Communication/MessageQueueConnection.h
        ../Communication/Message.h
        )

target_link_libraries( Detector ${OpenCV_LIBS} -lrt )

