// Time complexity: O(mlogn)
// Space complexity: O(n)
class SeatManager {
    int marker;
    set<int> availableSeats;

public:
    SeatManager(int n) {
        marker = 1;
    }

    int reserve() {
        if (!availableSeats.empty()) {
            int seatNumber = *availableSeats.begin();
            availableSeats.erase(availableSeats.begin());
            return seatNumber;
        }

        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        availableSeats.insert(seatNumber);
    }
};