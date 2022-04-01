![Badge tracking code size](https://img.shields.io/github/languages/code-size/Preffet/C-simple-echo-server?color=%234CBB17)![Badge tracking last commit](https://img.shields.io/github/last-commit/Preffet/C-simple-echo-server?color=%2317bb53) ![Badge tracking project size](https://img.shields.io/github/repo-size/Preffet/C-simple-echo-server?color=%2317bb9d) 


![banner](https://user-images.githubusercontent.com/84241003/161335385-528ac047-0959-4657-9bb9-64a8800e6d53.png)

-----------------------------------------------------------------------------
### Description

This program is an example of a very simple client-server program in C. The client sends a message to the server, the server prints the message on screen with the total number of bytes received. If the client enters a message that begins with a ".", the client will send the message and then terminate. When the server receives a message that begins with a ".", it terminates.

You can use localhost as a client and as a server. This is called the loopback interface. Packets sent to the local host address (127.0.0.1) are not put onto the physical network but a loopback emulation of a network. They are processed locally and treated as incoming packets. At the level of abstraction of socket programming there is no difference between a physical network interface and the loopback interface. Provided you have appropriate privileges, the same program will run using the loopback interface or across a real physical network. This is useful for testing.

This project contains the following files:   
   
echo-server/
- Makefile
- echo_client.c
- echo_server.c

-----------------------------------------------------------------------------
### How to build and run the project

To build the client and server do:

```
make
```
or
```
make clean 
make
```
    
### Staring the server and client

You will need **two terminal windows**. Start the server in one terminal window and then the client in the other terminal.

The server command is:

```
./echo_server port
```
where "port" is replaced by a number in the range: 1025 to 65535.

You should get the following output from the server:
```
waiting
```
Now **in the other terminal window** start the client by entering the following command:
```
./echo_client 127.0.0.1 port
```
where 127.0.0.1 is the localhost or loopback address and port is replaced by the port you started the server listening to. 

You will then be prompted to enter text at the client that will be echoed at the server. When you enter a message beginning "." at the client, both server and client will terminate.
