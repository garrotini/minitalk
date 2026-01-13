# minitalk

## description

Minitalk is a simple client-server communication program that uses UNIX signals (`SIGUSR1` and `SIGUSR2`).

Messages are transmitted by interpreting signals as binary data:
- SIGUSR1 -> when bit is 1
- SIGUSR2 -> when bit is 0

Basically the client will encode the each character (1 byte = 8 bits), send it as signals, and the server will receive, decode and show each character in the stdout.

## usage

1. build:
`make`

2. start the server:
`./server`

3. send a message using server's PID:
`./client [SERVER_PID] "message"`


## demo

![Demo](minitalk.mp4)

## license

This project is part of the 42 school curriculum.

