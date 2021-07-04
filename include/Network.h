#pragma once
#include <string>
#include <cpr/cpr.h>
#include <json/json.h>
class Network {
public:
	Network(const std::string& request);
	Json::Value sendRequestGet(const std::string& requ,const std::string& body="");
	Json::Value sendRequestPost(const std::string& requ, const std::string& body = "");
	struct Error;
private:
	const std::string request;
	cpr::Session session;
};
