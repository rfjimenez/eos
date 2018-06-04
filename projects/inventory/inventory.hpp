/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class inventory : public eosio::contract {
public:
	using contract::contract;

	inventory(account_name user) : contract(user), _fruits(_self, _self) {
		
	}

	/// @abi action
	void additem(account_name item, uint32_t count = 0); //gives initial value for count if not indicated
	/// @abi action
	void removeitem(const account_name item); 

	/// @abi action
	void decfruit(const account_name item, uint32_t dec);

	/// @abi action
	void incfruit(const account_name item, uint32_t inc);

	/// @abi action
	void emptyall(const account_name item);
	

private:
	/// @abi table fruits
	struct fruits {
		account_name item;
		uint32_t count;
	 
		uint64_t primary_key() const { return item; }
	 	EOSLIB_SERIALIZE( fruits, (item)(count) )
	};

	eosio::multi_index<N(fruits), fruits> _fruits;
      
};
EOSIO_ABI( inventory, (additem)(removeitem)(decfruit)(incfruit)(emptyall))




