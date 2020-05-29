FROM ubuntu:18.04

COPY ./main.cpp /home/main.cpp

COPY ./Action.h /home/Action.h
COPY ./first.cpp /home/first.cpp
COPY ./sec.cpp /home/sec.cpp
COPY ./team1.txt /home/team1.txt

COPY ./team2.txt /home/team2.txt
RUN apt-get update

RUN apt-get install nano 
