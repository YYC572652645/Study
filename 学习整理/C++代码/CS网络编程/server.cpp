#include"server.h"

int main()
{
	int sockfd,new_fd;
	struct sockaddr_in my_address;			    // 本地地址信息 
	struct sockaddr_in their_address;			// 连接者地址信息 
	int sin_size;

	WSADATA ws;
	WSAStartup(MAKEWORD(2,2), &ws);			     //初始化windows Socket dll

	sockfd = socket(AF_INET, SOCK_STREAM, 0);    //建立socket

	my_address.sin_family = AF_INET;             //协议类型是INET
	my_address.sin_port = htons(8080);           //绑定端口8080
	my_address.sin_addr.s_addr = INADDR_ANY;     //本机IP

	bind(sockfd, (sockaddr*)&my_address, sizeof(sockaddr));

	listen(sockfd, 5);  //监听
	std::cout<<"监听..."<<std::endl;

	sin_size=sizeof(sockaddr_in);
	new_fd=accept(sockfd, (sockaddr*)&their_address, &sin_size);

	Message msg;
	int numbytes = recv(new_fd, (char*)&msg, sizeof(msg), 0);
	std::cout<<"接收来自客户端的消息："<<msg.nummsg<<std::endl;

	msg.nummsg = 120;
	send(new_fd, (const char*)&msg, sizeof(msg), 0);
	std::cout<<"发送完毕"<<std::endl;

	closesocket(sockfd);
	closesocket(new_fd);

	system("pause");
	return 0;
}