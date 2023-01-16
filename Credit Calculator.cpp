#include <iostream>
#include <string>
using namespace std;

/* Class definition*/
class applicant
{

    /* Defining data members for storing applicant details*/
    string name;
    int age;
    string address;
    int m_sal;
    int h_loan;
    int p_loan;
    int no_chq_bounce;
    char Own_house;
    char Spouse_working;
    char Dependent_parents;
    int Company_tier;
    int yes, no;
    int liability;

    public:
        /* member function declaration */
        void get_data();
        int calc_liability();
        void display_score();
};

void applicant::get_data()
{
    cout << "\n\nName of applicant (Press | to terminate): " << endl;
    getline(cin, name, '|');

    cout << "\nAge : " << endl;
    cin >> age;

    cout << "\nAddress (Press | to terminate): "<<endl;
    getline(cin, address, '|');

    cout << "\nMonthly Salary : " << endl;
    cin >> m_sal;

    cout << "\nTotal home loan EMI : " << endl;
    cin >> h_loan;

    cout << "\nTotal personal loan EMI : " << endl;
    cin >> p_loan;

    cout << "\nNumber of cheque bounces in last 6 months : " << endl;
    cin >> no_chq_bounce;

    cout << "\n\nOwn house? (Y or N) : " << endl;
    cin >> Own_house;

    cout << "\nSpouse working? (Y or N) : " << endl;
    cin >> Spouse_working;

    cout << "\nDependent parents? (Y or N) : " << endl;
    cin >> Dependent_parents;

    cout << "\nCompany Tier (1,2 or 3) : " << endl;
    cin >> Company_tier;
}

int applicant::calc_liability()
{
    int score = 0; /* the score variable for storing credit score */

    /*details of applicant age*/
    if (age > 22 && age <= 30)
        score = score + 2;
    else if (age > 30 && age <= 35)
        score = score + 2;
    else
        score = score - 1;

    /* details 0f home and person loan with monthly salary EMI*/
    liability = h_loan + p_loan;

    if (liability <= m_sal / 4)
        score = score + 5;

    if (liability > m_sal / 4 && liability <= m_sal / 3)
        score = score + 3;

    if (liability > m_sal / 3 && liability <= m_sal / 2)
        score = score + 1;

    if (liability > m_sal / 2)
        score = score - 1;

    /* details of no_chq_bounce*/
    if (no_chq_bounce > 1)
        score = score - 2;

    if (no_chq_bounce == 1)
        score = score - 1;

    if (no_chq_bounce == 0)
        score = score + 1;

    /* details of personal and home loan*/
    if (p_loan + h_loan)
        score = score - 1;
    else
        score = score + 1;

    /* details of own house,spouse working,dependent parent */
    if (Own_house == 'Y')
        score = score + 1;

    if (Spouse_working == 'Y')
    score = score + 1;

    if (Dependent_parents == 'Y')
        score = score - 1;
    else
        score = score + 1;

    /* details of company tier */
    if (Company_tier == 1)
        score = score + 3;

    if (Company_tier == 2)
        score = score + 2;
    else
        score = score + 1;

    return (score);
} // end of calc_liability()

/* function for diplaying credit score and applicant rating*/
void applicant::display_score()
{
    int score = calc_liability();

    if (score > 9)
    cout << "\nThe applicant " << name << " is at low risk.\ncredit score = " << score << "\nCredit can be given." << endl;

    else
    {
    if (score > 5 && score <= 9)
        cout << "\nThe applicant " << name << " is at average risk.\ncredit score = " << score << "\nCredit can be given with due precaution." << endl;

    else
        cout << "\nThe applicant " << name << " is at high risk.\ncredit score = " << score << "\nCredit can not  be given" << endl;
    }
}

int user_menu(){
    int choice;
    cout << "\n\n\t\t\t\t\t\t\t   Credit Calculator" << endl;
    cout << "\t\t\t\t\t\t\t   *****************" << endl;
    cout << "\n1 - Enter loan applicant details." << endl;
    cout << "2 - Display credit score." << endl;
    cout << "3 - Exit." << endl;
    cout << "\nSelect an option." << endl;
    cin >> choice;
    return (choice);
}

int main() {
    applicant a;
    char flag = 'f';
    int ch;

    while(ch > 0 ){
        ch = user_menu();

        switch(ch) {
            case 1 :
                a.get_data();
                flag = 't';
                break;
            case 2 :
                if(flag=='f')
                {
                    cout<<"Loan applicant details not yet entered! Input the details..."<<endl;
                    a.get_data();
                    a.display_score();
                }
                else
                    a.display_score();
                break;
            case 3 :
                cout << "Bye - Bye!" << endl;
                exit (0);
            default :
                cout << "Invalid Input. Please try again" << endl << endl;
        }
    }
    return(0);
}
