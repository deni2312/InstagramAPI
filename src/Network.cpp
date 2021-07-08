#include "../include/Network.h"




Network::Network(const std::string& request) :request{request}
{
	cpr::Header header1;
	header1.insert({ "Content-type" ," application/x-www-form-urlencoded; charset=UTF-8" });
	header1.insert({ "User-Agent" , "Instagram 26.0.0.10.86 Android (24/7.0; 640dpi; 1440x2560; HUAWEI; LON-L29; HWLON; hi3660; en_US)" });
	session.SetHeader(header1);
}

std::string Network::sendRequestPost(const std::string& requ, const std::string& body)
{
	cpr::Response response;
	session.SetUrl({ request + requ });
	session.SetBody({ body });
	response = session.Post();
	int code;
	code = response.status_code;
	if (code != 200) {
		throw Error{ std::to_string(code) };
	}
	session.SetBody({ "" });
	return response.text;
}

std::string Network::sendRequestGet(const std::string& requ,const std::string& body)
{
	cpr::Response response;
	session.SetUrl({ request + requ });
	session.SetBody({ body });
	response = session.Get();
	int code;
	code = response.status_code;
	if (code != 200) {
		throw Error{ std::to_string(code) };
	}
	session.SetBody({ "" });
	return response.text;
}

Network::Error::Error(std::string error_code) :message{ error_code }
{
}

const char* Network::Error::what() const noexcept
{
	return message.c_str();
}
