/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/design-parking-system/
 */
class ParkingSystem {
public:
    int big, medium, small;
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        switch (carType){
            case 1:
                if(this->big > 0){
                    this->big = this->big - 1;
                    return true;
                }
                else{
                    return false;
                }
                break;
            case 2:
                if(this->medium > 0){
                    this->medium = this->medium - 1;
                    return true;
                }
                else{
                    return false;
                }
                break;
            case 3:
                if(this->small > 0){
                    this->small = this->small - 1;
                    return true;
                }
                else{
                    return false;
                }
                break;
            default:
                return false;
                break;
        }
    }
};
