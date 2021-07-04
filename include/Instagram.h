#ifndef INSTAGRAM_H
#define INSTAGRAM_H
#include <string>
#include <iostream>
#include <exception>
#include "Network.h"
#include <memory>
class Instagram {
public:
	Instagram(std::string username,std::string password);
	void login();
	Json::Value remove_profile_picture();
	Json::Value set_private();
	Json::Value set_public();
	Json::Value discover();
	Json::Value follow(const std::string& user_id);
	Json::Value unfollow(const std::string& user_id);
	Json::Value block(const std::string& user_id);
	Json::Value remove_follower(const std::string& user_id);
	Json::Value unblock(const std::string& user_id);
	Json::Value show(const std::string& user_id);
	Json::Value comment_like(const std::string& comment_id);
	Json::Value comment_unlike(const std::string& comment_id);
	Json::Value comment_likers(const std::string& comment_id);
	Json::Value media_info(const std::string& media_id);
	Json::Value media_like(const std::string& media_id);
	Json::Value media_unlike(const std::string& media_id);
	Json::Value media_likers(const std::string& media_id);
	Json::Value comment(const std::string& media_id,const std::string& comment_text);
	Json::Value comments(const std::string& media_id);
	Json::Value get_user_following(const std::string& user_id);
	Json::Value get_user_followers(const std::string& user_id);
	Json::Value get_user_feed(const std::string& user_id);
	Json::Value search_username(const std::string& username);
	virtual ~Instagram() noexcept;
private:
	struct Data;
	std::unique_ptr<Data> data;
	std::unique_ptr<Network> network;
};
#endif
