// Time complexity: O((m + n) * logn)
// Space complexity: O(n)
class SeatManager {
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        for (int seatNumber = 1; seatNumber <= n; ++seatNumber) {
            availableSeats.push(seatNumber);
        }
    }

    int reserve() {
        int seatNumber = availableSeats.top();
        availableSeats.pop();
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        availableSeats.push(seatNumber);
    }
};