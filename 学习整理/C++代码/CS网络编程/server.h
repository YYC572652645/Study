#include<winsock.h>
#include<iostream>
#pragma comment(lib,"Ws2_32")
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
	Message():msg_header(2005){}
	MessageHeader msg_header;
	int nummsg;
};