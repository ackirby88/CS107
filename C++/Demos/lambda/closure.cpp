/* system header files  */
# include <iostream>
# include <functional>
# include <stdexcept>

std::function<float(float)> make_withdrawal(float init_balance) {
    if (init_balance <= 0) {
        throw std::invalid_argument(" [ERROR] Initial balance must be > 0");
    }

    // set closure's balance
    float balance = init_balance;

    // Return a closure that captures the balance
    // In order to make the variable balance modifiable,
    // we must make the function mutable
    return [balance] (float withdrawal_amount) mutable {
        if (withdrawal_amount > balance) {
            printf("\n\x1B[0;31m[ERROR] Trying to withdraw %.2f from balance %.2f\x1B[0m\n",withdrawal_amount, balance);
            throw std::logic_error("\n [ERROR] Withdrawal amount can't be greater than balance!");
        }

        std::cout << "    ========================="  << "\n";
	std::cout << "              Balance: " << balance << "\n";

        balance -= withdrawal_amount;	// update balance within the closure

        std::cout << "(-) Withdrawal Amount: " << withdrawal_amount << "\n";
        std::cout << "    ------------------"  << "\n";
        std::cout << "    Remaining Balance: " << balance << "\n";

        return balance;
    };
}

/** HW2 Problem 3 Bank Account Closure
 *
 * This solution utilizes a C++ Lambda Expression.
 * NOTE: "\x1B" is a bash escape character. 
 *       "[0;32m" is a the bash color green.
 *       "[0m" resets the bash escape coloring.
 */
int main(void) {
    float init_balance = 200;

    std::cout << "    ========================="  << "\n";
    printf("\x1B[0;32m    Initial Balance: %.2f\x1B[0m\n", init_balance);

    auto wd = make_withdrawal(init_balance);
    wd( 10.75); // withdraw 10.75
    wd( 80.00); // withdraw 80.00
    wd(190.00); // try withdrawing 190.00
    wd( 20.25); // try withdrawing 20.25

    return 0;
}
