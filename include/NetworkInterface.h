#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H
#include "types/UserRequest.h"
#include "types/UserListRequest.h"
#include "types/UserListRequestFollow.h"
#include "types/UserFeedRequest.h"
#include "types/UserCommentsRequest.h"
#include "types/LoginRequest.h"
#include <string>
class NetworkInterface {
public:
	virtual std::string sendRequestGet(const std::string& requ, const std::string& body = "") = 0;
	virtual std::string sendRequestPost(const std::string& requ, const std::string& body = "") = 0;
	virtual void setProxy(const std::string& type,const std::string& address)=0;
};
#endif
