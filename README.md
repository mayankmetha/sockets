GROUP DETAILS:  1) Mayank Metha D
                                   PES1201802185

                               2) Sandhya C S
                                   PES1201802545

                              3) Lavanya yadav S
                                  PES1201802542

COMMANDS: cd/sockets
          
        1)for iterative and concurrent files:  

           
                    $ gcc server.c -o server 8080 
                    $ ./server

          In the new terminal, 
	        compile and run the client file
                $  gcc client.c -o client
                $ ./client 
	  
        2)  for concurrent run client file on multiple terminals.

        3)  exception case for bonus part:  $ ./bonus_server.o 8080 | tee serverLog
                                            $ ./bonus_client 127.0.01 8080

EXAMPLE: For scaling 1000+ clients.
                   
		   step1: $gcc bonus_server.c -o bonus_server 8080
                   step2:  $./bonus_server
                   step3: from various terminals    $gcc bonus_client.c -o bonus_client
                                                    $./bonus_client
                             

                   step4: for analying: $ ./bonus_server.o 8080 | tee serverLog
                   
	           step5:   $ ./bonus_client 127.0.01 8080

DESCRIPTION:

Working:      
              
	      * In the iterative process of communication after successful connection server terminates responding to client.
              
	      * In the concurrent process of communication server stays online and responds to all the clients, trying to connect with server parallely.
              
	      * When scaling more than 1000+ clients notifies the response time of all the triggering clients until the server crashes at a thresold.
              
	      * Error conditions: Tried with all posibble error conditions while creating sockets, bind, listen, accept, closing sockets funtionalities using the MAN page error ID's.

CHALLENGES:



There is never an easy solution till we hit a difficult challenge. Similarly, we too faced few challenges in concurrent server and server loading with huge amount of request. 
     
     * The concurrent server was more of a conceptual misunderstaning of fork() which was solved when a friend Prashant helped us understand the underlying process of fork(). 
     
     * The second problem was how to launch a thousand clients to analyse the response. Most of the suggestions from stackoverflow and github were leading to iterative client process thats when we decided to experiment with fork() and the results were brillant.
     
     * The last problem was the overwhelming data from server and clients during scaling making analysis difficult. The solution was filtering data and visualizing it using bash and pyhton scripts.


DETAILS AND EXPLANATIONS OF RESULTS OBTAINED 

 

* server1 and client: Demonstrates a basic error handling of server and a client sockets and how they communicate with each other before   they terminate the connection and exit. 

* On encountering an error the error location and type of error is shown and program terminates.



* Server2 and client: An iterative server based on infinte loop concept with all the error handlers demonstrates how multiple clients     establish connection and communicate with the server before terminating the connection.



* Server3 and client: A concurrent server based on fork() concept with all the error handlers demonstrates how multiple clients          establish connection and communicate with the server before terminating the connection.


* Bonus_server and bonus_client: An extension to server3 and client code where the client can send some random number of request with random number to server at regular intervals. The server echos back the clients request as the response message for client.
 The client can then compute the response time for the same.

bonus_server and scale_client: Similar to bonus_server and bonus_client. The only difference is with the client. The code create a thousand clients that communicate with the server. Some of the clients terminate successfully after completion while other clients request fails to fetch a response as the server crashes due to excess load (Proof of Concept for DDoS Attack). 
This give rise to response delay which can be analysed and the issue of scaling can also be studied easily.
