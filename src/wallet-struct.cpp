struct wallet{
    const float max = 100,000.00;
    float personalWallet = max;
};
struct user {
    int id;
    string userName;
    int age;
    wallet personalWallet;
    int wonBets;
};