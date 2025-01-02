#include <bits/stdc++.h>

using namespace std;

string code;
string date_of_birth;
string father_code;
string mother_code;
string is_alive;
string region_code;
string queries;
int number_people = 0;
int most_alive_ancestor;
int max_unrelated_people = 0;
map <string, vector<string>> number_people_born_at;
map <string, string> father;
map <string, string> mother;
map <string, bool> alive;
map <string, int> save_date;
map <string, vector <string>> adj;
set <string> save_code;
int t;
int k = 1;
map <string, bool> visited;
map <string, int> r;
map <int, int> prefix;

bool are_related(string p1, string p2)
{
    return (father[p1] == p2 || mother[p1] == p2 ||
            father[p2] == p1 || mother[p2] == p1);
}

bool check(string p, set <string>& current_people)
{
    if (visited[p]) return false;
    if (current_people.size() == 0) return true;
    for (auto i : current_people)
        if (are_related(p, i))
            return false;
    return true;
}

void backtrack(set <string> &current_people, string last)
{
    max_unrelated_people = max(max_unrelated_people,(int)current_people.size());
    for (auto it = save_code.upper_bound(last); it != save_code.end(); ++it)
    {
        string i = *(it);
        if (check(i, current_people))
        {
            visited[i] = true;
            current_people.insert(i);
            backtrack(current_people, i);
            visited[i] = false;
            current_people.erase(i);
        }
    }
}

int calc_rank(string p)
{
    if (father[p] == "0000000"
     && mother[p] == "0000000")
        return 0;
    most_alive_ancestor = - 1;
    string save = p;
    t = 0;
    while (1)
    {
        if (alive[father[save]] && father[save] != "0000000")
        {
            save = father[save];
            t++;
        }
        else
        {
            break;
        }
    }
    most_alive_ancestor = max(t, most_alive_ancestor);
    t = 0; save = p;
    while (1)
    {
        if (alive[mother[save]] && mother[save] != "0000000")
        {
            save = mother[save];
            t++;
        }
        else
        {
            break;
        }
    }
    most_alive_ancestor = max(t, most_alive_ancestor);
    return most_alive_ancestor;
}

int main()
{
    cin >> code;
    while (code != "*")
    {
        cin >> date_of_birth >> father_code >> mother_code >> is_alive
            >> region_code;
        number_people++;
        number_people_born_at[date_of_birth].push_back(code);
        father[code] = father_code;
        mother[code] = mother_code;
        if (is_alive == "Y") alive[code] = true;
        else alive[code] = false;
        save_date[date_of_birth] =  0;
        save_code.insert(code);
        cin >> code;
    }

    for (auto i = save_date.begin(); i != save_date.end(); i++)
    {
        i -> second = k;
        prefix[k] = prefix[k - 1] + number_people_born_at[i -> first].size();
        k++;
    }
    prefix[k] += number_people_born_at[((save_date).end()) -> first].size();
    for (auto i : save_code)
    {
        visited[i] = false;
        r[i] = calc_rank(i);
    }
    cin >> queries;
    while (queries != "***")
    {
        if (queries == "NUMBER_PEOPLE")
            cout << number_people << endl;
        if (queries == "NUMBER_PEOPLE_BORN_AT")
        {
            string date;
            cin >> date;
            cout << number_people_born_at[date].size() << endl;
        }
        if (queries == "MOST_ALIVE_ANCESTOR")
        {
            string code;
            cin >> code;
            cout << r[code] << endl;
        }
        if (queries == "NUMBER_PEOPLE_BORN_BETWEEN")
        {
            string from_date, to_date;
            cin >> from_date >> to_date;
            int lo = save_date.lower_bound(from_date) -> second;
            int hi = save_date.upper_bound(to_date) -> second;
            if (lo != 0 && hi == 0) hi = save_date.size();
            else hi--;
 //           for (int i = 0; i <= save_date.size(); i++)
   //             cout << prefix[i] << " ";
     //       cout << endl << lo << " " << hi << " ";
            cout << prefix[hi] - prefix[lo - 1] << endl;
        }
        if (queries == "MAX_UNRELATED_PEOPLE")
        {
            set<string> current_people;
            backtrack(current_people, "");
            cout << max_unrelated_people << endl;
        }
        cin >> queries;
    }
    return 0;
}
