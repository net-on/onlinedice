#include "onlinedicel.hpp"

void onlinedicel::result(net_result result) {
    require_auth(ONLINE_DICE_APP);
    require_recipient(result.player);
}
