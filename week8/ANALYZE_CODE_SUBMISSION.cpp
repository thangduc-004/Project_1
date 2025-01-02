#include <bits/stdc++.h>

using namespace std;

string user_id;
string problem_id;
string time_point;
string status;
int point;
set <string> save_user;
set <pair<string, string>> save_problem;
int total_number_submissions = 0;
int number_error_submission = 0;
map <string, int> number_error_submission_of_user;
map <string, int> point_of_user;
map <pair<string, string>, int> max_point_case;
map <int, int> number_submission_in_time;
vector <int> prefix(86400, 0);

int calc_time(string t)
{
    string hs = t.substr(0, 2);
    string ms = t.substr(3, 2);
    string ss = t.substr(6, 2);
    int h = stoi(hs);
    int m = stoi(ms);
    int s = stoi(ss);
    return h * 3600 + m * 60 + s;
}

int main()
{
    cin >> user_id;
    while (user_id != "#")
    {
        cin >> problem_id >> time_point >> status >> point;
    //    save_user.insert(user_id);
        save_problem.insert({user_id, problem_id});
        int t = calc_time(time_point);
        total_number_submissions++;
        if (status == "ERR")
        {
            number_error_submission++;
            number_error_submission_of_user[user_id]++;
        }
        else
            max_point_case[{user_id, problem_id}] = max(max_point_case[{user_id, problem_id}], point);
        number_submission_in_time[t]++;
        cin >> user_id;
    }
    for (auto i : save_problem)
        point_of_user[i.first] += max_point_case[i];
    for (int i = 1; i < 86400; i++)
        prefix[i] += prefix[i - 1] + number_submission_in_time[i];
    string queries;
    cin >> queries;
    while (queries != "#")
    {
        if (queries == "?total_number_submissions")
            cout << total_number_submissions << endl;
        else if (queries == "?number_error_submision")
            cout << number_error_submission << endl;
        else if (queries == "?number_error_submision_of_user")
        {
            string id;
            cin >> id;
            cout << number_error_submission_of_user[id] << endl;
        }
        else if (queries == "?total_point_of_user")
        {
            string id;
            cin >> id;
            cout << point_of_user[id] << endl;
        }
        else if (queries == "?number_submission_period")
        {
            string from_time, to_time;
            cin >> from_time >> to_time;
            int from = calc_time(from_time);
            int to = calc_time(to_time);
            cout << prefix[to] - prefix[from - 1] << endl;
        }
        cin >> queries;
    }
    return 0;
}
