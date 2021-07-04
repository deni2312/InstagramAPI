#include "include/Instagram.h"

using namespace std;

int main()
{
	Instagram instagram("username", "password");
	instagram.login();
	std::string user_id = instagram.search_username("username")["user"]["pk"].asString();
	instagram.follow(user_id);
	instagram.media_like("media_id");
	instagram.get_user_followers(user_id);
	instagram.set_private();
}
