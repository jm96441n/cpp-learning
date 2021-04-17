PWD=$(shell pwd)
run:
	docker run --rm --name $(name) \
		-v $(PWD)/chap$(chap)/$(name).cpp:/prog.cpp \
		-it jmaguire5588/ubclang:latest \
		/bin/bash -c "clang++ -std=c++17 prog.cpp -o prog && /prog"
