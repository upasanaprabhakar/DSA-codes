class Solution {
public:
    priority_queue<int> maxHeap;                            // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger half

    unordered_map<int, int> delayed;

    int leftSize = 0;
    int rightSize = 0;

    void pruneMaxHeap() {
        while (!maxHeap.empty()) {
            int num = maxHeap.top();
            if (delayed.count(num)) {
                delayed[num]--;
                if (delayed[num] == 0) {
                    delayed.erase(num);
                }
                maxHeap.pop();
            } else
                break;
        }
    }

    void pruneMinHeap() {
        while (!minHeap.empty()) {
            int num = minHeap.top();
            if (delayed.count(num)) {
                delayed[num]--;
                if (delayed[num] == 0) {
                    delayed.erase(num);
                }
                minHeap.pop();
            } else
                break;
        }
    }

    void balanceHeaps() {
        if (leftSize > rightSize + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            leftSize--;
            rightSize++;
            pruneMaxHeap();
        } else if(leftSize < rightSize){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            leftSize++;
            rightSize--;
            pruneMinHeap();
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            // insert
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
                leftSize++;
            } else {
                minHeap.push(num);
                rightSize++;
            }
            balanceHeaps();

            // remove outgoing element
            if (i >= k) {
                int outNum = nums[i - k];
                delayed[outNum]++;

                if (outNum <= maxHeap.top()) {
                    leftSize--;
                } else {
                    rightSize--;
                }

                if (!maxHeap.empty() && outNum == maxHeap.top()) {
                    pruneMaxHeap();
                }
                if (!minHeap.empty() && outNum == minHeap.top()) {
                    pruneMinHeap();
                }
                balanceHeaps();
            }

            // get median
            if (i >= k - 1) {
                if (k % 2 == 1) {
                    result.push_back(maxHeap.top());
                } else {
                    result.push_back(((double)maxHeap.top() + minHeap.top()) /
                                     2.0);
                }
                
            }
        }
        return result;
    }
};