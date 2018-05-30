// Client.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 5月 30 04:50:08 2018 (+0800)
// Last-Updated: 三 5月 30 05:09:35 2018 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 4
// URL: http://wuhongyi.cn 

// g++ Client.cc -l zmq  -o 123

// Hello World client in C++  
// Connects REQ socket to tcp://localhost:5555  
// Sends "Hello" to server, expects "World" back  
//  
#include <zmq.hpp>  
#include <string>  
#include <iostream>  
int main ()  
{  
  // Prepare our context and socket  
  zmq::context_t context (1);  
  zmq::socket_t socket (context, ZMQ_REQ);  
  std::cout << "Connecting to hello world server..." << std::endl;  
  socket.connect ("tcp://localhost:5555");  
  // Do 10 requests, waiting each time for a response  
  for (int request_nbr = 0; request_nbr != 10; request_nbr++)
    {  
      zmq::message_t request (6);  
      memcpy ((void *) request.data (), "Hello", 5);  
      std::cout << "Sending Hello " << request_nbr << "..." << std::endl;  
      socket.send (request);  
      // Get the reply.  
      zmq::message_t reply;  
      socket.recv (&reply);  
      std::cout << "Received World " << request_nbr << std::endl;  
    }  
  return 0;  
} 

// 
// Client.cc ends here
