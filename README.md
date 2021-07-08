#  C++ Instagram API

<p align="left">A header-only version of Instagram Private API in C++

  * [Getting started.](#getting-started)
  * [Writing your first bot](#writing-your-first-bot)
  * [General API Documentation](#general-api-documentation)
    * [Usage](#usage)
    * [Error Handling](#error-handling)
  * [Contacts](#contacts)

## Getting started.
















<h2> Steps </h2>

This API is tested with C++ 14, on linux g++.

### Linux 
Install on linux with vcpkg:  
  * Dependencies
    * nlohmann-json
    * cpr  
```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install nlohmann-json
./vcpkg install cpr
./vcpkg integrate install
```  
With CMake:  
```bash
cd InstagramAPI
mkdir build
cmake -B build/ -S . -DCMAKE_TOOLCHAIN_FILE=vcpkgdirectory/scripts/buildsystems/vcpkg.cmake
cd build
cmake --build .
./Instagram
```  
Change vcpkgdirectory with the relative or absolute path of vcpkg  

## Writing your first bot

<h3>Hello World!</h3>

```c++
#include "include/Instagram.h"

int main()
{
	Instagram instagram{"username", "password"};
	try {
		instagram.login();
	}
	catch (Network::Error& e) {
		std::cerr << e.what();
	}
}


```

## General API Documentation

### Usage

All the operations that contains information returned by Instagram are typed.  
This implementation has all basic methods, here a list of them:  
```c++
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


```

There's a example:  
```c++
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


```
### Error Handling

To handle errors you only need to catch `Network::Error &e` and the output of `e.what()` will be the JSON error returned by instagram.

### Contacts

You can contact us on Telegram for any issue or doubt.  
<a href="https://t.me/deni2312"> @deni2312 </a>
