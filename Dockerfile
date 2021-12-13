FROM gcc:4.9

COPY . /usr/src/aoc2021
WORKDIR /usr/src/aoc2021
 
RUN cd build/ && gcc -I.. -o aoc ../main.cpp ../util.cpp ../day1.cpp -lstdc++
