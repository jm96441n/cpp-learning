PWD=$(shell pwd)

build:
	docker build -t jmaguire5588/ubclang:latest ./

run:
	docker run --rm --name $(name) \
		-v $(PWD)/chap$(chap):/src \
		-it jmaguire5588/ubclang:latest \
		/bin/bash -c "clang++ -std=c++17 ${name}.cpp -o prog && ./prog"
