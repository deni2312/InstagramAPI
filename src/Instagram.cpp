#include "../include/Instagram.h"

struct Instagram::Data {
	std::string username;
	std::string password;
	std::string base;
};

Instagram::Instagram(const std::string& username, const std::string& password) :data{ std::make_unique<Data>() }, network{ std::make_unique<Network>("https://i.instagram.com/api/v1/") }
{
	data->username = username;
	data->password = password;
	data->base = "ig_sig_key_version=4&signed_body=67d69889a0c11fc7c51c4fb8d997fc87b62e95d16cf21f5d9993590011bc791d.";
}

void Instagram::login()
{
	network->sendRequestPost("accounts/login/", data->base+"{\"phone_id\": \"1234\", \"device_id\": \"android - 36c34ce3ee48d07c\", \"guid\": \"1234\", \"username\": \"" + data->username + "\", \"password\": \"" + data->password + "\"}");
}

void Instagram::remove_profile_picture()
{
	 network->sendRequestPost("accounts/current_user/");
}

void Instagram::set_private()
{
	 network->sendRequestPost("accounts/set_private/");
}

void Instagram::set_public()
{
	 network->sendRequestPost("accounts/set_public/");
}

void Instagram::follow(const std::string& user_id)
{
	 network->sendRequestPost("friendships/create/"+user_id+"/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

void Instagram::unfollow(const std::string& user_id)
{
	 network->sendRequestPost("friendships/destroy/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

void Instagram::block(const std::string& user_id)
{
	 network->sendRequestPost("friendships/block/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

void Instagram::remove_follower(const std::string& user_id)
{
	 network->sendRequestPost("friendships/remove_follower/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

void Instagram::unblock(const std::string& user_id)
{
	 network->sendRequestPost("friendships/unblock/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

void Instagram::comment_like(const std::string& comment_id)
{
	 network->sendRequestPost("media/" + comment_id + "/comment_like/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"comment_id\": \"" + comment_id + "\"}");
}

void Instagram::comment_unlike(const std::string& comment_id)
{
	 network->sendRequestPost("media/" + comment_id + "/comment_unlike/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"comment_id\": \"" + comment_id + "\"}");
}

void Instagram::media_like(const std::string& media_id)
{
	 network->sendRequestPost("media/" + media_id + "/like/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\"}");
}

void Instagram::media_unlike(const std::string& media_id)
{
	 network->sendRequestPost("media/" + media_id + "/unlike/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\"}");
}

void Instagram::comment(const std::string& media_id,const std::string& comment_text)
{
	 network->sendRequestPost("media/" + media_id + "/comment/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\", \"comment_text\": \"" + comment_text + "\"}");
}

IgTypes::UserCommentsRequest Instagram::comments(const std::string& media_id)
{
	 return IgTypes::json::parse(network->sendRequestPost("media/" + media_id + "/comments/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\"}"));
}

IgTypes::UserListRequest Instagram::get_user_following(const std::string& user_id)
{
	 return IgTypes::json::parse(network->sendRequestGet("friendships/" + user_id + "/following/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}"));
}

IgTypes::UserListRequestFollow Instagram::get_user_followers(const std::string& user_id)
{
	 return IgTypes::json::parse(network->sendRequestGet("friendships/" + user_id + "/followers/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}"));
}

IgTypes::UserFeedRequest Instagram::get_user_feed(const std::string& user_id)
{
	 return IgTypes::json::parse(network->sendRequestPost("feed/user/" + user_id+"/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}"));
}

IgTypes::UserRequest Instagram::search_username(const std::string& username)
{
	return IgTypes::json::parse(network->sendRequestGet("users/" + username + "/usernameinfo/"));
}

Instagram::~Instagram()
{
}
