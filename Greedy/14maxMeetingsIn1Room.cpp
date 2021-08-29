#include <bits/stdc++.h>
using namespace std;
 
// Structure for storing starting time,
// finishing time and position of meeting.
struct meeting {
    int start;
    int end;
    int pos;
};

// Comparator function which can compare
// the endtime of element in structure used to
// sort pairs in increasing order of endtime.
// if endtime equals then sort according to position
bool comparator(struct meeting m1, meeting m2){
    if(m1.end!=m2.end) return (m1.end < m2.end);
    else return (m1.pos<m2.pos);
}

// Function for finding maximum meeting in one room
void maxMeeting(int s[], int f[], int n){
    struct meeting meet[n];
    for (int i=0;i<n;i++){
        meet[i].start = s[i];
        meet[i].end = f[i];
        // position is 1 indexed
        meet[i].pos = i + 1;
    }
 
    // Sorting of meeting according to their finish time.
    sort(meet,meet + n,comparator);
 
    // Vector for storing selected meeting.
    vector<int> m;
 
    // Initially select first meeting.
    m.push_back(meet[0].pos);
 
    // time_limit to check whether new
    // meeting can be conducted or not.
    int time_limit = meet[0].end;
 
    // Check for all meeting whether it
    // can be selected or not.
    for (int i=1;i<n;i++){
        // if ith meeting start is greater or equal to the lastest
        // meeting end time (i.e. time_limit)
        if (meet[i].start >= time_limit){
            // Push selected meeting to vector
            m.push_back(meet[i].pos);
            // Update time limit.
            time_limit = meet[i].end;
        }
    }
 
    // Print final selected meetings.
    for (int i=0;i<m.size();i++) cout<<m[i]<<" ";
}

int main(){
    // Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };
     
    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
     
    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
 
    // Function call
    maxMeeting(s, f, n);
 
    return 0;
}
