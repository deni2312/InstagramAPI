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

Json::Value Instagram::remove_profile_picture()
{
	return network->sendRequestPost("accounts/current_user/");
}

Json::Value Instagram::set_private()
{
	return network->sendRequestPost("accounts/set_private/");
}

Json::Value Instagram::set_public()
{
	return network->sendRequestPost("accounts/set_public/");
}

Json::Value Instagram::discover()
{
	return network->sendRequestPost("discover/");
}

Json::Value Instagram::follow(const std::string& user_id)
{
	return network->sendRequestPost("friendships/create/"+user_id+"/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::unfollow(const std::string& user_id)
{
	return network->sendRequestPost("friendships/destroy/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::block(const std::string& user_id)
{
	return network->sendRequestPost("friendships/block/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::remove_follower(const std::string& user_id)
{
	return network->sendRequestPost("friendships/remove_follower/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::unblock(const std::string& user_id)
{
	return network->sendRequestPost("friendships/unblock/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::show(const std::string& user_id)
{
	return network->sendRequestPost("friendships/show/" + user_id + "/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::comment_like(const std::string& comment_id)
{
	return network->sendRequestPost("media/" + comment_id + "/comment_like/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"comment_id\": \"" + comment_id + "\"}");
}

Json::Value Instagram::comment_unlike(const std::string& comment_id)
{
	return network->sendRequestPost("media/" + comment_id + "/comment_unlike/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"comment_id\": \"" + comment_id + "\"}");
}

Json::Value Instagram::comment_likers(const std::string& comment_id)
{
	return network->sendRequestPost("media/" + comment_id + "/comment_likers/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"comment_id\": \"" + comment_id + "\"}");
}

Json::Value Instagram::media_info(const std::string& media_id)
{
	return network->sendRequestPost("media/" + media_id + "/info/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\"}");
}

Json::Value Instagram::media_like(const std::string& media_id)
{
	return network->sendRequestPost("media/" + media_id + "/like/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\"}");
}

Json::Value Instagram::media_unlike(const std::string& media_id)
{
	return network->sendRequestPost("media/" + media_id + "/unlike/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\"}");
}

Json::Value Instagram::media_likers(const std::string& media_id)
{
	return network->sendRequestPost("media/" + media_id + "/likers/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\"}");
}

Json::Value Instagram::comment(const std::string& media_id,const std::string& comment_text)
{
	return network->sendRequestPost("media/" + media_id + "/comment/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\", \"comment_text\": \"" + comment_text + "\"}");
}

Json::Value Instagram::comments(const std::string& media_id)
{
	return network->sendRequestPost("media/" + media_id + "/comments/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"media_id\": \"" + media_id + "\"}");
}

Json::Value Instagram::get_user_following(const std::string& user_id)
{
	return network->sendRequestGet("friendships/" + user_id + "/following/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::get_user_followers(const std::string& user_id)
{
	return network->sendRequestGet("friendships/" + user_id + "/followers/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::get_user_feed(const std::string& user_id)
{
	return network->sendRequestPost("feed/user/" + user_id+"/", data->base+"{\"_uuid\": \"3a12620f-332a-4393-8cdc-6ae15c039dfd\", \"_uid\": 44502302651, \"user_id\": \"" + user_id + "\"}");
}

Json::Value Instagram::search_username(const std::string& username)
{
	return network->sendRequestGet("users/" + username+"/usernameinfo/");
}

Instagram::~Instagram()
{
}
