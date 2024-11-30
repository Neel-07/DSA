#include <iostream>
#include <cmath>     // For fabs()
#include <algorithm> // For min()

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Calculate the hour hand angle
        double hourAngle = (hour % 12) * 30 + (minutes * 0.5); // 30 degrees per hour + 0.5 degrees per minute
        
        // Calculate the minute hand angle
        double minuteAngle = minutes * 6; // 6 degrees per minute
        
        // Calculate the absolute difference between the two angles
        double angleDifference = fabs(hourAngle - minuteAngle);
        
        // Return the smaller angle
        return std::min(angleDifference, 360 - angleDifference);
    }
};

int main() {
    Solution solution;
    int hour = 3, minutes = 15;

    double result = solution.angleClock(hour, minutes);

    std::cout << "The smaller angle is: " << result << " degrees" << std::endl;

    return 0;
}
