FROM gcc:4.9

COPY . /usr/src/aoc2021
WORKDIR /usr/src/aoc2021
 
RUN cd build/ && g++ -std=c++11 -I.. -o aoc ../main.cpp ../util.cpp ../day1.cpp
