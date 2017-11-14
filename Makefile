CXXFLAGS=-std=c++11 -Wall -Wextra -Werror -MMD
TARGET=main
LIBS=libimpl.a

$(TARGET): $(LIBS) main.go
	go build main.go

libimpl.a: impl.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -f $(LIBS)
	rm -f *.d

-include *.d

