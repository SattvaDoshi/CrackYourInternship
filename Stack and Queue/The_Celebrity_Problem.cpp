class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        
         stack<int> s;
        int n = mat.size();
        
        // Push all the elements in the stack
        for(int i = 0; i < n; i++){
            s.push(i);
        }
        
        // Step 2: Get 2 elements and compare them
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(mat[a][b] == 1){
                // a knows b, so a cannot be a celebrity, push b
                s.push(b);
            }
            else{
                // a does not know b, so b cannot be a celebrity, push a
                s.push(a);
            }
        }
        
        // Step 3: Single element in stack is the potential celebrity
        int candidate = s.top();
        
        // Check if candidate is actually a celebrity
        bool rowCheck = true;
        int zeroCount = 0;
        
        // Check the candidate's row
        for(int i = 0; i < n; i++){
            if(mat[candidate][i] == 0){
                zeroCount++;
            }
        }
        
        // All zeros in the candidate's row
        if(zeroCount != n){
            rowCheck = false;
        }
        
        // Check the candidate's column
        bool colCheck = true;
        int colCount = 0;
        
        for(int i = 0; i < n; i++){
            if(mat[i][candidate] == 1){
                colCount++;
            }
        }
        
        // All ones in the candidate's column except for the candidate's own position
        if(colCount != n - 1){
            colCheck = false;
        }
        
        if(rowCheck && colCheck){
            return candidate;
        }
        else{
            return -1;
        }
    }
};