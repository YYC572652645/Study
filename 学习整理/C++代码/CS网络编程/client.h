#include<iostream>
#include<winsock.h>
#pragma comment(lib,"Ws2_32")
#define IP   "127.0.0.1"
#define PORT 8080
#define MAXDATASIZE 100
typedef struct MessageHeader
{
	MessageHeader(unsigned short type):msg_type(type){}
	unsigned short msg_type;
	unsigned short server_id;
}MessageHeader;

class Message
{
public:
	Message():msg_header(2006){}
	MessageHeader msg_header;
	int nummsg;
};