#include "include/Instagram.h"
#include <iostream>
#include <string>

int main()
{
	Instagram instagram{"username", "password"};
	try{
		instagram.login();
	}catch(Network::Error& e){
		std::cerr<<e.what();
	}
	//Get user id
	auto user_id=*instagram.search_username("username").get_user()->get_pk();
	//Get user feed like photos or videos
	auto feed=instagram.get_user_feed(std::to_string(user_id));
	//Iterate feed
	for(auto item : *feed.get_items()){
		//Print item id
		auto id=*item.get_id();
		std::cout<<"id: "+id;
		//Like post
		instagram.media_like(id);
		//Unlike post
		instagram.media_unlike(id);
		//Comment post
		instagram.comment(id,"hello");
		//Get comment
		auto comment=instagram.comments(id);
	}
	//Set profile private
	instagram.set_private();
	//Get followers
	auto followers=instagram.get_user_followers(std::to_string(user_id));
	for(auto follower: *followers.get_users()){
		//print username
		std::cout<<*follower.get_username();
	}
	//Follow user
	instagram.follow(std::to_string(user_id));
}