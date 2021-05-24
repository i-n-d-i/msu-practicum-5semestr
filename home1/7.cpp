#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>

using namespace std;


class Server {
    string domen = "";
    string ip = "";
public:
    Server();
    void setWebSite(const string & newDomen, const string & newIP);
    string getDomen();
    string getIP();
};

Server::Server() {}

void Server::setWebSite(const string & newDomen, const string & newIP) {
    domen = newDomen;
    ip = newIP;
}

string Server::getDomen() {
    return domen;
}

string Server::getIP() {
    return ip;
}


string findIP(string domen, vector<Server> sites) {
    bool flag = 0;
    string answer;
    for (unsigned int i = 0; i < sites.size(); i++) {
	if (sites[i].getDomen() == domen) {
	    answer = sites[i].getIP();
	    flag = 1;
	}
    }
    if (flag == 0) {
	answer = "PUSTO";
    }
    return answer;		
}


int main () {
    int time1 = clock();
    int N, M;
    cin >> N >> M;
    string domen, ip;
    
    vector<string> answer(M);
    vector<Server> sites(N);

    for (int i = 0; i < N; i++) {
	cin >> domen >> ip;
        sites[i].setWebSite(domen, ip);
    }
    int time2 = clock();
    cout << time2-time1 << endl;
    time1 = clock(); 
    for (int i = 0; i < M; i++) {
	cin >> domen;
	answer[i] = findIP(domen, sites);	
    }
    time2 = clock();
    cout << time2-time1 << endl;
    for (int i = 0; i < M; i++) {
        cout << answer[i] << endl;
    }
    return 0;
}
