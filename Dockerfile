FROM gcc:4.9

COPY . /usr/src/aoc2021
WORKDIR /usr/src/aoc2021
 
RUN cd build/ && g++ -std=c++11 -I ../src/solutions -I ../src/util -o aoc ../src/solutions/*.cpp ../src/util/*.cpp ../src/*.cpp
