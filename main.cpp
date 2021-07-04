#include "include/Instagram.h"

int main()
{
	Instagram instagram{"username", "password"};
	try{
	instagram.login();
	}catch(Network::Error& e){
		std::cerr<<e.what();
	}
	std::string user_id = instagram.search_username("username")["user"]["pk"].asString();
	instagram.follow(user_id);
	instagram.media_like("media_id");
	instagram.get_user_followers(user_id);
	instagram.set_private();
}
