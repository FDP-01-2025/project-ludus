//wallet.h

namespace walletCommands{

    bool winnerResult(bool personalWallet, bool winnBet){
        bool win;
        win = personalWallet - winnBet;
        return win;

    }
}