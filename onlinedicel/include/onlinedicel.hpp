#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>
#include <eosiolib/singleton.hpp>
#include <eosiolib/time.hpp>
#include <eosiolib/types.hpp>
#include <iostream>
using namespace eosio;
using namespace std;

#define ONLINE_DICE_APP N(onlinedice)

struct net_bet {
    uint64_t id;
    account_name player;
    account_name referrer;
    asset amount;
    uint8_t roll_under;
    checksum256 seed_hash;
    checksum160 user_seed_hash;
    uint64_t created_at;
};

struct net_result {
    uint64_t bet_id;
    account_name player;
    account_name referrer;
    asset amount;
    uint8_t roll_under;
    uint8_t random_roll;
    checksum256 seed;
    checksum256 seed_hash;
    checksum160 user_seed_hash;
    asset payout;
};

class onlinedicel : public contract {
   public:
    onlinedicel(account_name self) : contract(self){};

    // @abi action
    void result(net_result result);
};

EOSIO_ABI(onlinedicel, (result));
