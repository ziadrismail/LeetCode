class Bank {
public:
    Bank(vector<long long>& balance) : balance(balance){
        n = (int) balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!valid_account(account1) || !valid_account(account2)) {
            return false;
        }

        if (!valid_transaction(account1, money)) {
            return false;
        }

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!valid_account(account)) {
            return false;
        }

        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!valid_account(account)) {
            return false;
        }

        if (!valid_transaction(account, money)) {
            return false;
        }

        balance[account - 1] -= money;
        return true;
    }

private:
    int n;
    vector<long long> balance;

    bool valid_account(int account) {
        return 1 <= account && account <= n;
    }

    bool valid_transaction(int account, long long money) {
        return balance[account - 1] >= money;
    }
};
