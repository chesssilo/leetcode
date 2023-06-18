class ParkingSystem {
public:
    int carLimit[3];
    ParkingSystem(int big, int medium, int small) {
        carLimit[0] = big;
        carLimit[1] = medium;
        carLimit[2] = small;
    }

    bool addCar(int carType) {
        if (carType == 1 && carLimit[0] > 0) {
            carLimit[0]--;
            return 1;
        }
        else if (carType == 2 && carLimit[1] > 0) {
            carLimit[1]--;
            return 1;
        }
        else if (carType == 3 and carLimit[2] > 0) {
            carLimit[2]--;
            return 1;
        }
        else return 0;
    }
};