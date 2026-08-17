class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;

        for(char x : tasks){
            mp[x]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto &[task, freq] : mp){
            pq.push({freq, task});
        }

        int time = 0;
        queue<pair<pair<int,char>, int>> q;

        while(!pq.empty() || !q.empty()){

            while(!q.empty()){
                auto it = q.front();
                int freq = it.first.first;
                char task = it.first.second;
                int cooldown = it.second;
                if(cooldown <= time){ 
                pq.push({freq,task});
                q.pop();
                }
                else break;
            }

            if(!pq.empty()){
                auto it = pq.top();
                int frequency = it.first;
                char taskexecute = it.second;
                pq.pop();

                time++;
                frequency--;
                if(frequency > 0){
                    q.push({{frequency, taskexecute}, time+n});
                }
            }
            else{
                time++;
            }
        }
        return time;
    }
};