CXX := g++
LDD := g++

FLAGS_RELEASE := -Wall -Wextra -fPIC -O2
FLAGS_DEBUG   := -Wall -Wextra -fPIC -g
INCLUDES      := `php-config --includes`
LDD_FLAGS     := -shared -lopencv_highgui -lopencv_core

TARGET_RELEASE := release/PluggR.so
TARGET_DEBUG   := debug/PluggR.so

SWIG_FLAGS := -c++ -php
SWIG_SRC   := PluggR.i
SWIG_OUT   := PluggR_wrap.cpp
SWIG_OBJ   := PluggR_wrap.cpp.o
SWIG_CRAP  := php_ServR.h ServR.php

SRC := PluggR.cpp $(SWIG_OUT)
OBJ := $(SRC:.cpp=.o)

swig: $(SWIG_OUT)
$(SWIG_OUT):
	swig $(SWIG_FLAGS) $(SWIG_SRC)

release: $(TARGET_RELEASE)
$(TARGET_RELEASE): $(SWIG_SRC) $(SRC)
	$(CXX) $(INCLUDES) $(FLAGS_RELEASE) -c $(SRC)
	$(LDD) $(OBJ) -o $(TARGET_RELEASE) $(LDD_FLAGS)

debug: $(TARGET_DEBUG) $(SRC)
$(TARGET_DEBUG): $(SWIG_SRC)
	$(CXX) $(INCLUDES) $(FLAGS_DEBUG) -c $(SRC)
	$(LDD) $(OBJ) -o $(TARGET_DEBUG) $(LDD_FLAGS)

clean:
	rm -f $(OBJ) $(TARGET_RELEASE) $(TARGET_DEBUG) \
	      $(SWIG_CRAP) $(SWIG_OUT) $(SWIG_OBJ)
