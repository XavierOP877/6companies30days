class Solution {
public:
    void combination(int i, int k, int sum, int n, vector<int> &subSet, vector<vector<int>> &ans){
        if(sum > n){
            return;  
        }    
        if(k == 0){
            if(sum == n){
                ans.push_back(subSet); 
            }        
            return;
        }    
        if(i == 10){
            return;   
        } 
        sum += i;
        subSet.push_back(i);    
        combination(i + 1, k - 1, sum, n, subSet, ans);    
        sum -= i;
        subSet.pop_back();    
        combination(i + 1, k, sum, n, subSet, ans); 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subSet ;
        vector<vector<int>> ans ;
        combination(1, k, 0, n, subSet, ans) ;    
        return ans ;
    }
};