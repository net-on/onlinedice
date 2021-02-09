# Design Provably-fair Dice with Blockchain Paradigm

As all we know, when we play a traditional dice game in old times, the game fairness is exclusively endorsed by the owner's reputation. So many trick or fraud exists because of this reason.

Now thanks to the blockchain technology which provides transparent, irreversible online ledget everybody can audit, we have a way to design an online provably fair dice game technically.

## 1. Roll Randomness

The most important in roll randomness is to prevent single party alone to control the roll. In other words, both player and house seeds must be evaluated when calculating roll.


## 2. Procedure of creating Random Roll

Among all blockchain infrastructures, we chose EOS here since it's fast and provides good user experience.

Following is the scheme of making random roll.

```
1. PLAYER send roll info like "Roll_Under_To_Win" value to HOUSE.
 
2. HOUSE creates a new HOUSE_SEED for each bet and keeps it a secret until step 9.
 
3. HOUSE calculates the corresponding HOUSE_HASH and HOUSE_BET_INFO from HOUSE_SEED.
 
4. HOUSE sends HOUSE_HASH, HOUSE_BET_INFO to the PLAYER.
 
5. PLAYER creates his PLAYER_SEED.
 
6. PLAYER uploads the HOUSE_BET_INFO & PLAYER_SEED to the EOS blockchain.
 
7. CONTRACT deployed on EOS checks to prevent PLAYER from replay attacking the previous HOUSE_SEED by changing HOUSE_BET_INFO.
 
8. HOUSE uploads the HOUSE_SEED.
 
9. CONTRACT checks HOUSE_SEED and HOUSE_HASH to confirm HOUSE didn't swap the HOUSE_SEED sneakingly for its profit.
 
10. CONTRACT at last calculates the final Roll based on the PLAYER_SEED & HOUSE_SEED.
```

------

net-on