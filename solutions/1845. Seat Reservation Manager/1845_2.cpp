// Time complexity: O(mlogn)
// Space complexity: O(n)
class SeatManager {
    int marker;
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        marker = 1;
    }

    int reserve() {
        if (!availableSeats.empty()) {
            int seatNumber = availableSeats.top();
            availableSeats.pop();
            return seatNumber;
        }

        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        availableSeats.push(seatNumber);
    }
};