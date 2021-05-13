PWD=$(shell pwd)

.PHONY: build
build:
	docker build -t jmaguire5588/ubclang:latest ./

.PHONY: run
run:
	docker run --rm --name $(name) \
		-v $(PWD)/chap$(chap):/src \
		-it jmaguire5588/ubclang:latest \
		/bin/bash -c "clang++ -std=c++17 ${name}.cpp -pthread -Wall -o prog && ./prog $(args)"

.PHONY: vec_run
vec_run:
	docker run --rm --name $(name) \
		-v $(PWD)/chap$(chap)/$(name).cpp:/src/$(name).cpp \
		-v $(PWD)/chap$(chap)/Vector.cpp:/src/Vector.h \
		-v $(PWD)/chap$(chap)/Vector.h:/src/Vector.cpp \
		-it jmaguire5588/ubclang:latest \
		/bin/bash -c "clang++ -std=c++17 *.cpp -pthread -Wall -o prog && ./prog $(args)"
