#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

int main() {
  io_service io_service;
  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 8080));

  while (true) {
    tcp::socket socket(io_service);
    acceptor.accept(socket);

    std::string message = "Hello, world!";
    std::stringstream ss;
    ss << "HTTP/1.1 200 OK\r\n";
    ss << "Content-Type: text/plain\r\n";
    ss << "Content-Length: " << message.length() << "\r\n";
    ss << "\r\n";
    ss << message;

    std::string response = ss.str();
    boost::system::error_code ignored_error;
    write(socket, buffer(response), ignored_error);
  }

  return 0;
}
