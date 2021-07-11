#ifndef INSTAGRAM_NETWORK
#define INSTAGRAM_NETWORK
#include <cpr/cpr.h>
#include "NetworkInterface.h"

class Network : public NetworkInterface{
public:
	Network(const std::string& request);
	std::string sendRequestGet(const std::string& requ,const std::string& body="");
	std::string sendRequestPost(const std::string& requ, const std::string& body = "");
	void setProxy(const std::string& type,const std::string& address);
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
