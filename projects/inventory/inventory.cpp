#include <inventory.hpp>

void inventory::additem(account_name item, uint32_t count) {
	//require_auth(item); //makes sure that the authorization matches the account name pushing the action

	auto itr = _fruits.find(item);

	eosio_assert(itr == _fruits.end(), "Fruit already added."); //if condition is not satisfied then 
	_fruits.emplace(item, [&](auto&  p) {
		p.item = item;
		p.count = count;
	});
	print("Fruit ", name{item}, " created (count =  ", count, ").");

}

void inventory::removeitem(const account_name item) {
	//require_auth(item);
	
	auto itr = _fruits.find(item);

	eosio_assert(itr != _fruits.end(), "Fruit does not exist in the table.");

	_fruits.erase(itr);

	print("Fruit ", name{item}, " deleted.");
}

void inventory::decfruit(const account_name item, uint32_t dec) {
	auto itr = _fruits.find(item);

	eosio_assert(itr != _fruits.end(), "Fruit does not exist in the table.");

	_fruits.modify(itr, item, [&](auto& p) {
		eosio_assert(p.count >= dec, "Can only decrease fruit count until count becomes 0.");
		p.count -= dec;
	});

	print("Fruit ", name{item}, " decreased by ", dec, ".\n");
	print("New fruit count: ", itr->count);

}

void inventory::incfruit(const account_name item, uint32_t inc) {
	auto itr = _fruits.find(item);

	eosio_assert(itr != _fruits.end(), "Fruit does not exist in the table.");

	_fruits.modify(itr, item, [&](auto& p) {
		p.count += inc;
	});

	print("Fruit ", name{item}, " increased by ", inc, ".\n");
	print("New fruit count: ", itr->count);

}

void inventory::emptyall(const account_name item) {
	for (auto itr=_fruits.begin(); itr != _fruits.end();) {
		auto dummy = itr;
		itr++;
		_fruits.erase(dummy);
	}
	print("Removed all fruits from the inventory.");
}
