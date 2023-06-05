networking utilities

<br/><br/>


echo thing example thing:
```cpp
// server

#include <string>
#include <xieite/network.hpp>

int main() {
	xieite::network::StreamServer server;
	server.bind(xieite::network::Address("::", 8080));
	server.listen(10);

	while (true) {
		server.accepting([](xieite::network::StreamClient& client) {
			client.receiving([&](const std::string& clientMessage) {
				client.send(clientMessage);
				client.close();
			});
		});
	}
}
```
```cpp
// client

#include <iostream>
#include <string>
#include <xieite/network.hpp>

int main() {
	xieite::network::StreamClient client;
	client.connect(xieite::network::Address("::1", 8080));

	std::string clientMessage;
	std::getline(std::cin, clientMessage);
	client.send(clientMessage);

	client.receiving([](const std::string& serverMessage) {
		std::cout << serverMessage << '\n';
	});
}
```
