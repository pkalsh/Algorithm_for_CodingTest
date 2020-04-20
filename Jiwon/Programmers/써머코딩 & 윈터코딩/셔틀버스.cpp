/*
카카오에서는 무료 셔틀버스를 운행하기 때문에 판교역에서 편하게 사무실로 올 수 있다. 카카오의 직원은 서로를 '크루'라고 부르는데, 
아침마다 많은 크루들이 이 셔틀을 이용하여 출근한다.

이 문제에서는 편의를 위해 셔틀은 다음과 같은 규칙으로 운행한다고 가정하자.

셔틀은 09:00부터 총 n회 t분 간격으로 역에 도착하며, 하나의 셔틀에는 최대 m명의 승객이 탈 수 있다.
셔틀은 도착했을 때 도착한 순간에 대기열에 선 크루까지 포함해서 대기 순서대로 태우고 바로 출발한다. 
예를 들어 09:00에 도착한 셔틀은 자리가 있다면 09:00에 줄을 선 크루도 탈 수 있다.
일찍 나와서 셔틀을 기다리는 것이 귀찮았던 콘은, 일주일간의 집요한 관찰 끝에 어떤 크루가 몇 시에 셔틀 대기열에 도착하는지 알아냈다. 
콘이 셔틀을 타고 사무실로 갈 수 있는 도착 시각 중 제일 늦은 시각을 구하여라.

단, 콘은 게으르기 때문에 같은 시각에 도착한 크루 중 대기열에서 제일 뒤에 선다. 또한, 모든 크루는 잠을 자야 하므로 23:59에 집에 돌아간다. 
따라서 어떤 크루도 다음날 셔틀을 타는 일은 없다.

셔틀 운행 횟수 n, 셔틀 운행 간격 t, 한 셔틀에 탈 수 있는 최대 크루 수 m, 크루가 대기열에 도착하는 시각을 모은 배열 timetable이 입력으로 주어진다.

예:
n	t	m	timetable	                                                                                                    answer
1	1	5	[08:00, 08:01, 08:02, 08:03]	                                                                                09:00
2	10	2	[09:10, 09:09, 08:00]	                                                                                        09:09
2	1	2	[09:00, 09:00, 09:00, 09:00]	                                                                                08:59
1	1	5	[00:01, 00:01, 00:01, 00:01, 00:01]	                                                                            00:00
1	1	1	[23:59]	                                                                                                        09:00
10	60	45	[23:59,23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59, 23:59]	18:00
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<int> tthour;
    vector<int> ttmin;
    vector<int> tttime;

    for(int i = 0; i < timetable.size(); i++){
        tthour.push_back(stoi(timetable[i].substr(0,2).c_str()));
        ttmin.push_back(stoi(timetable[i].substr(3,2).c_str()));
        tttime.push_back(tthour[i]*60 + ttmin[i]);
    }
    
    sort(tttime.begin(), tttime.end());

    int prestime = 540, cnt = 0, k = 0, ans = 0;
    
    for(int i = 0; i < n; i++){
        prestime = 540 + i*t;
        cnt = 0;        
        for(int j = k; j < tttime.size(); j++){
            if(tttime[j] <= prestime){
                cnt++;
                k = j + 1;
                if(cnt == m){
                    break;
                }
            }
            else break;            
        }
        
        if(n == i + 1){
            if(cnt == m){
                ans = tttime[k-1] - 1;
            }
            else{
                ans = prestime;
            }
        }
        if(prestime >= (60*24)) break;
    }
    
    cout << ans;

    string tmp = "";

    int hour = ans / 60;   
    int min = ans % 60;
     
    if (hour < 10) tmp += "0" + to_string(hour);
    else tmp += to_string(hour);

    tmp += ":";

    if (min < 10) tmp += "0" + to_string(min);
    else tmp += to_string(min);
    
    answer = tmp;

    return answer;
}