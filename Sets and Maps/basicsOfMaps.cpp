#include<iostream>
#include<unordered_map>
using namespace std;
// class pair{
// public: 
//     string first;
//     int second;
// };
int main() {
    // Pair Class
    
    // pair<int, int> p;
    // p.first = 1;
    // p.second = 2;
    // cout << p.first << " " << p.second;

    // pair<string, string> p;
    // p.first = "Keshav";
    // p.second = "Nikhil";
    // cout << p.first << " " << p.second;

    // pair<string, char> p;
    // p.first = "Keshav";
    // p.second = 'A';
    // cout << p.first << " " << p.second;

    unordered_map<string, int> m;
    // m.insert("Keshav", 24);           // -- It is wrong   
    // Hm pair banake fir insert kr skte hai 

    // Insertion -- Method 1
    pair<string, int> p1;       // Pair class has 2 variables by default i.e., first and second of sam/different data types
    p1.first = "Keshav";
    p1.second = 24;
    m.insert(p1);
    // m["Keshav"] = 24;

    pair<string, int> p2;
    p2.first = "Nikhil";
    p2.second = 40;
    m.insert(p2);
    // m["Nikhil"] = 40;

    pair<string, int> p3;
    p3.first = "Jyotsna";
    p3.second = 23;
    m.insert(p3);
    // m["Jyotsna"] = 23

    // Alternating method of inserting any pair in the map
    // Insertion -- Method 2
    m["Paryansh"] = 40;     // map_name[key] = value
    
    // To increase the value/ frequency of any particular key we have to use       --         map_name[key]++
 
    // Printing -- Method 1
    // for(pair<string, int> p : m) {
    //     cout << p.first << " " << p.second << endl;
    // }

    //          OR
    
    // Printing -- Method 2 
    for(auto p : m) {
        cout << p.first << " " << p.second << endl;
    }
    cout << "Size : " << m.size() << endl;      // m.size() -- Size of map
    cout << endl;

    // Deletion or Erase
    m.erase("Paryansh");        // m.erase(key);

    for(auto p : m) {
        cout << p.first << " " << p.second << endl;
    }
    cout << "Size : " << m.size() << endl;      // m.size() -- Size of map
    cout << endl;

    // For printing any value :     Use -- map_name<key>
    cout << m["Keshav"];
}