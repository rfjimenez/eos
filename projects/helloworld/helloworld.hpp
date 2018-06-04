/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eosiolib/eosio.hpp>

using namespace eosio;

class helloworld : public eosio::contract {
  public:
      using contract::contract;

      /// @abi action 
      void printhello(account_name sender);
};

EOSIO_ABI( helloworld, (printhello) )
