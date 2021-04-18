## Tour of CPP

Work for specific chapters are organized by file. To compile and run specific files/binaries use
the make commands provided. To build the docker image for compiling from the root directory just run
`make build`. To run a specific cpp file navigate to that directory and run `make -C ../ run name=FILENAME
chap=CHAPNUM`. So, for example, to run the `arithmetic.cpp` file from chap4, first navigate to the chap4 directory
and then run `make -C ../ run name=arithmetic chap=4`.
