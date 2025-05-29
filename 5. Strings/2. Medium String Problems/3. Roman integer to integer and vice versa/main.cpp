// https://leetcode.com/problems/roman-to-integer/description/


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mymap{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int answer=0;
        for( int i =0; i<s.size(); i++){
            if(i + 1 < s.size() && mymap[s[i]] < mymap[s[i+1]]){ //iv is 4
                answer -= mymap[s[i]];
            }
            else{
                answer += mymap[s[i]];
            }
        }
        return answer;
    }
};