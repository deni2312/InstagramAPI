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

This API is tested with C++ 14, on linux g++ and on Visual Studio 2017/2019.

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

All the operations returns a `Json::Value` that contains all informations about the request.  
There's a example:  
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

### Error Handling

To handle errors you only need to catch `Network::Error &e` and the output of `e.what()` will be the JSON error returned by instagram.

### Contacts

You can contact us on Telegram for any issue or doubt.  
<a href="https://t.me/deni2312"> @deni2312 </a>
