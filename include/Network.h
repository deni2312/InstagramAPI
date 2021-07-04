#ifndef INSTAGRAM_NETWORK
#define INSTAGRAM_NETWORK
#include <string>
#include <cpr/cpr.h>
#ifdef _WIN32
	#include <json/json.h>
#else
	#include <jsoncpp/json/json.h>
#endif

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
#endif
