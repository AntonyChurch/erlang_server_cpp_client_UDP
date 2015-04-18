#include <SFML/Network.hpp>
#include <iostream>
#include <string>

int main()
{
  //Set the port number
  int Port = 12345;
  //Set the server address
  char serverAddress[] = "127.0.0.1";
  int serverPort = 54321;

  //Create the socket
  sf::UdpSocket socket;

  //Bind the socket
  socket.bind(Port);

  std::cout << "Socket Bound" << std::endl;

  //Send a message to the server server
  std::string message = "Here is my game stuff in a packet";

  std::cout << "Message: " << message << std::endl;

  socket.send(message.c_str(), message.size() + 1, serverAddress, serverPort);

  std::cout << "Mesage sent." << std::endl;

  //Recieve a message from the server.
  char buffer[1024];
  std::size_t received = 0;
  sf::IpAddress sender;
  unsigned short port;
  socket.receive(buffer, sizeof(buffer), received, sender, port);
  std::cout << "Reply: " << buffer << std::endl;

  return 0;
}
