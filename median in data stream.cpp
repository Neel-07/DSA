#include <iostream>
#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap; // Max-heap for the smaller half (default max-heap)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min-heap for the larger half

public:
    // Function to add a number to the stream
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num); // Push to max-heap if smaller than or equal to max-heap's top
        } else {
            minHeap.push(num); // Otherwise, push to min-heap
        }

        // Balance the heaps if their sizes differ by more than 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Function to find the median
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top(); // If max-heap has more elements, median is the top of max-heap
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0; // If heaps are equal, median is the average of the tops
        }
    }
};

int main() {
    // Create a MedianFinder object
    MedianFinder mf;

    // Perform operations
    mf.addNum(1);
    std::cout << "Median after adding 1: " << mf.findMedian() << std::endl;

    mf.addNum(5);
    std::cout << "Median after adding 5: " << mf.findMedian() << std::endl;

    mf.addNum(2);
    std::cout << "Median after adding 2: " << mf.findMedian() << std::endl;

    mf.addNum(8);
    std::cout << "Median after adding 8: " << mf.findMedian() << std::endl;

    mf.addNum(3);
    std::cout << "Median after adding 3: " << mf.findMedian() << std::endl;

    mf.addNum(9);
    std::cout << "Median after adding 9: " << mf.findMedian() << std::endl;

    return 0;
}
