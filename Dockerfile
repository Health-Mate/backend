FROM ubuntu:latest

RUN apt-get update && apt-get upgrade -y

RUN apt-get install libasio-dev libwebsocketpp-dev cmake make build-essential -y 

WORKDIR /app

COPY ./src ./src

COPY ./CMakeLists.txt ./

COPY ./include ./include

RUN  cmake CMakeLists.txt && make

CMD './ClinicMate_backend'