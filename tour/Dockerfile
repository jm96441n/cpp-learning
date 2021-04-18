FROM ubuntu:20.04

RUN bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"

RUN apt-get update \
  && apt-get install -y build-essential clang

RUN mkdir src

WORKDIR src
