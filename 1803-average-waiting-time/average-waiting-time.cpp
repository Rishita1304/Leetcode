class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long currentTime = 0; // Tracks the current time
        long long totalWaitingTime = 0; // Accumulates the total waiting time
        
        for (const auto& customer : customers) {
            int arrivalTime = customer[0];
            int cookingTime = customer[1];
            
            // If the current time is less than the customer's arrival time, move the current time to the arrival time
            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }
            
            // Calculate the time the customer will finish being served
            currentTime += cookingTime;
            
            // Calculate the waiting time for the current customer
            totalWaitingTime += (currentTime - arrivalTime);
        }
        
        // Calculate and return the average waiting time
        return static_cast<double>(totalWaitingTime) / n;
    }
};
