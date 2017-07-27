#include"client.h"


int main()
{
	WSADATA ws;
	WSAStartup(MAKEWORD(2,2), &ws);  //初始化windows socket dll

	int sockfd=socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in their_address;

	their_address.sin_family = AF_INET;
	their_address.sin_port = htons(PORT);
	their_address.sin_addr.s_addr = inet_addr(IP);
	connect(sockfd, (sockaddr*)&their_address, sizeof(sockaddr));

	Message msg;
	msg.nummsg = 110;
	send(sockfd, (const char*)&msg, sizeof(msg), 0);
	std::cout<<"发送完毕"<<std::endl;

	int numbytes = recv(sockfd, (char*)&msg, sizeof(msg), 0);
	std::cout<<"接收来自服务端的消息息："<<msg.nummsg<<std::ends<<msg.msg_header.msg_type<<std::endl;
	closesocket(sockfd);

	system("pause");
	return 0;
}
