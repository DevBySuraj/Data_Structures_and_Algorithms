
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineers(n);

        for(int i =0; i<n; i++){
            engineers[i] = {efficiency[i], speed[i]};
        }

        sort(engineers.rbegin(), engineers.rend());

        priority_queue<int, vector<int>, greater<int>> mh;

        long long speedSum = 0;
        long long ans = 0;
        for(auto &[eff, speed]  : engineers){
            
            mh.push(speed);
            speedSum += speed;

            if(mh.size() > k){
                speedSum -= mh.top();
                mh.pop();
            }


            ans = max(ans, speedSum*eff);
        }
        return ans % 1000000007;
    }
};