TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tcp_socket.cpp \
    actorbase.cpp \
    actor.cpp \
    buffer.cpp \
    producer.cpp \
    consumer.cpp \
    manager.cpp

HEADERS += \
    tcp_socket.h \
    actor.h \
    actorbase.h \
    buffer.h \
    producer.h \
    consumer.h \
    manager.h

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread
