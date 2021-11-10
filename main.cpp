#include <iostream>
#include <cmath>

using namespace std;

class Users {
    public:
        int userId;
        float userExpense, actualShare, diff;

        void pending() {
            if (diff < 0)
                cout<<"You owe Rs."<<abs(diff);
            else cout<<"Your should recieve Rs."<<diff;
        }
};

void percentShare(int members, Users user[], float totalExpense) {
    float percent[members];
    for (int i = 0; i < members; i++) {
        cout<<"Enter the percentage of User "<<user[i].userId<<": ";
        cin>>percent[i];
        user[i].actualShare = (percent[i] / 100) * totalExpense;
    }
}

void exactShare(int members, Users user[], float totalExpense) {
    for (int i = 0; i < members; i++) {
        user[i].actualShare = totalExpense / members;
    }
}

void calcDiff (Users user[], int members) {
    for (int i = 0; i < members; i++) {
        user[i].diff = user[i].userExpense - user[i].actualShare;
    }
}

int main()
{
    int members, i, inputUser;
    float totalExpense = 0;
    char shareType;
    cout<<"\t\t\t\t\tWelcome to Splitwise - Expense Sharing App\n";
    cout<<"Enter total memebers: ";
    cin>>members;
    Users user[members];
    cout<<"Enter type of share (P/E): ";
    cin>>shareType;

    for (i = 0; i < members; i++) {
        user[i].userId = i + 1;
        cout<<"Enter the expense by user "<<user[i].userId<<": ";
        cin>>user[i].userExpense;
        totalExpense += user[i].userExpense;
    }

    if (shareType == 'P') percentShare(members, user, totalExpense);
    else exactShare(members, user, totalExpense);

    calcDiff(user, members);

    cout<<"Enter user ID: ";
    cin>>inputUser;

    user[inputUser-1].pending();
    return 0;
}
