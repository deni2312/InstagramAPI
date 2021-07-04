#pragma once
#include <string>
#include <cpr/cpr.h>
#include <json/json.h>
class Network {
public:
	Network(const std::string& request);
	Json::Value sendRequestGet(const std::string& requ,const std::string& body="");
	Json::Value sendRequestPost(const std::string& requ, const std::string& body = "");
	struct Error : public std::exception{
		Error(std::string error_code);
		const char* what() const noexcept override;
	private:
		std::string message;
	};
private:
	const std::string request;
	cpr::Session session;
};
