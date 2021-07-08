#ifndef INSTAGRAM_H
#define INSTAGRAM_H
#include <exception>
#include "Network.h"
#include <memory>
class Instagram {
public:
	Instagram(const std::string& username,const std::string& password);
	void login();
	void remove_profile_picture();
	void set_private();
	void set_public();
	void follow(const std::string& user_id);
	void unfollow(const std::string& user_id);
	void block(const std::string& user_id);
	void remove_follower(const std::string& user_id);
	void unblock(const std::string& user_id);
	void comment_like(const std::string& comment_id);
	void comment_unlike(const std::string& comment_id);
	void media_like(const std::string& media_id);
	void media_unlike(const std::string& media_id);
	void comment(const std::string& media_id,const std::string& comment_text);
	IgTypes::UserCommentsRequest comments(const std::string& media_id);
	IgTypes::UserListRequest get_user_following(const std::string& user_id);
	IgTypes::UserListRequestFollow get_user_followers(const std::string& user_id);
	IgTypes::UserFeedRequest get_user_feed(const std::string& user_id);
	IgTypes::UserRequest search_username(const std::string& username);
	~Instagram();
private:
	struct Data;
	std::unique_ptr<Data> data;
	std::unique_ptr<NetworkInterface> network;
};
#endif
