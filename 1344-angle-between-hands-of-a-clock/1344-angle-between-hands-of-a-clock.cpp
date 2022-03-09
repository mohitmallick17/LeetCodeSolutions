class Solution {
public:
    double angleClock(int hour, int minutes) {
        float h = (hour%12 + minutes/60.0) * 30; // 360 / 12 = 3
        float m = minutes*6; // 360 / 60 = 6
        float angle = fabs(h-m);
        if(angle>180)
            angle=360-angle;
        return angle;
    }
};