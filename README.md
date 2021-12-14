# Advent-Of-Code-2021
Holds my solutions to the advent of code 2021 challenges.
https://adventofcode.com/2021/

## Run
**Requirements**:
- Docker and docker-compose

To run the solution for a given day:
- Clone this repo to your local computer
- Make sure you have docker setup and run `docker-compose build`
- Then simply run `docker-compose run --rm dev build/aoc day<x>`

`day<x>` will be the command for the _x_ day's solution you want to run with the `day<x>test.txt` input file.

For example:
`docker-compose run --rm dev build/aoc day1` will run the solution for the [first day](https://adventofcode.com/2021/day/1).
