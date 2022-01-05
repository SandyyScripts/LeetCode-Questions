class Solution {
public:
    double angleClock(int hour, int minutes) {
        int minHand=6*minutes;
        if(hour==12){
            hour=0;
        }
        float hourHand=(30*hour)+(0.5*minutes);
        if(minHand==hourHand){
            return 0;
        }
        double angle=abs(minHand-hourHand);
        if(angle>180){
            angle=360-angle;
        }
        return angle;
    }
};