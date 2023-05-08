/*[338,890,301,532,284,930,426,616,919,267,571,140,716,859,980,469,628,490,195,664,925,652,503,301,917,563,82,947,910,451,366,190,253,516,503,721,889,964,506,914,986,718,520,328,341,765,922,139,911,578,86,435,824,321,942,215,147,985,619,865]

[773,537,46,317,233,34,712,625,336,221,145,227,194,693,981,861,317,308,400,2,391,12,626,265,710,792,620,416,267,611,875,361,494,128,133,157,638,632,2,158,428,284,847,431,94,782,888,44,117,489,222,932,494,948,405,44,185,587,738,164,356,783,276,547,605,609,930,847,39,579,768,59,976,790,612,196,865,149,975,28,653,417,539,131,220,325,252,160,761,226,629,317,185,42,713,142,130,695,944,40,700,122,992,33,30,136,773,124,203,384,910,214,536,767,859,478,96,172,398,146,713,80,235,176,876,983,363,646,166,928,232,699,504,612,918,406,42,931,647,795,139,933,746,51,63,359,303,752,799,836,50,854,161,87,346,507,468,651,32,717,279,139,851,178,934,233,876,797,701,505,878,731,468,884,87,921,782,788,803,994,67,905,309,2,85,200,368,672,995,128,734,157,157,814,327,31,556,394,47,53,755,721,159,843]
*/
[10,63,95,16,85,57,83,95,6,29,71]
[70,31,83,15,32,67,98,65,56,48,38,90,5]


class Cmp {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        //return a.size == b.size ? a.price > b.price : a.size < b.size;
        if(a.first==b.first)return a.second > b.second;
        else return a.first > b.first;
        //优先比较第一项，第一项相等比第二项，都是小的放在前面
    }
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //servers[i]:第 i 台服务器 权重
        //task[j] j time
        //维护一个当前可用的空闲服务器的优先队列，权重最小，下标小的放在前面
        //维护一个正在使用的服务器优先队列，对应运行时间短的在前面

        for(int i=0;i<servers.size();i++){
            emp.push(pair<int,int>{servers[i],i});
        }
        int time=0;
        vector<int>ans;
        for(int j = 0;j<tasks.size(); ){
            time=max (time,j);
            release(time,servers);

            if(emp.empty() && use.size()){
                time=use.top().first;
                release(time,servers);
            }

            while (emp.size() && j <= time){
                int i=emp.top().second;//对应下标
                emp.pop();
                use.push(pair<int,int>{tasks[j++]+time,i});
                ans.push_back(i);               
            }           
        }
        return ans;
    }
    private:
        void release(int t, const vector<int>&servers){
            while(!use.empty() && use.top().first<=t){
                int t=use.top().second;
                use.pop();
                emp.push(pair<int,int>{servers[t],t});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,Cmp>emp,use;
};