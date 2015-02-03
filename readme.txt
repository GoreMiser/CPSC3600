William Newberry
Password Breaker Read Me:

This code was designed to implement a server and a client.  The server, which has a password, Requires a port and a max password size. The server simply listens, waiting for a client to send a message to it. Once it receives a message, it tests to see if that message is the same as the password. On success, the server sends back a "SUCCESS" message. On failure, a "FAILURE" message.  

The client requires the server IP, the server port, and the size of the password(same as on the server).  The client attempts to guess the servers password, and upon success exits and displays the number of tries, successes, and the time it took to get the password.  

To make the program, run a make clean, make depends, and make.  Then you will run the client and server as such:

SERVER:

./passwordServer <UDP SERVER PORT> <PASSWORD LENGTH> <OPTIONAL INITIAL PASSWORD>

CLIENT:

./passwordBreaker <UDP SERVER IP> <UDP SERVER PORT> <PASSWORD LENGTH>



Upon termination, the client closes displaying the information explained above.  
