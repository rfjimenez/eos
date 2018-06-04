#include <helloworld.hpp>

using namespace eosio;

void helloworld::printhello(account_name sender) {
	print( "Hello world, ", name{sender});
}
