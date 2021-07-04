#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H
class NetworkInterface {
public:
	virtual Json::Value sendRequestGet(const std::string& requ, const std::string& body = "") = 0;
	virtual Json::Value sendRequestPost(const std::string& requ, const std::string& body = "") = 0;
};
#endif
