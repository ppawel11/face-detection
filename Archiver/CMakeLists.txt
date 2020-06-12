add_executable(Archiver
        main.cpp
        ../Communication/Connection.cpp
        ../Communication/Connection.h
        ../Communication/MessageQueueConnection.cpp
        ../Communication/MessageQueueConnection.h
        )
target_link_libraries( Archiver ${OpenCV_LIBS} -lrt )