#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize all with -1
    stack<int> st; // Monotonic decreasing stack (stores indices)
    
    for (int i = 0; i < n; i++) {
        cout << "Processing nums[" << i << "] = " << nums[i] << endl;
        
        // While stack not empty AND current element > stack's top element
        while (!st.empty() && nums[i] > nums[st.top()]) {
            int idx = st.top();
            result[idx] = nums[i]; // Current element is next greater for stack top
            st.pop();
            cout << "  Found next greater for nums[" << idx << "] = " << nums[idx] 
                 << " → " << nums[i] << endl;
        }
        
        st.push(i);
        cout << "  Pushed index " << i << " to stack" << endl;
        cout << "  Stack size: " << st.size() << endl;
        cout << "---" << endl;
    }
    
    return result;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    vector<int> result = nextGreater(nums);
    
    cout << "\nFinal Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}