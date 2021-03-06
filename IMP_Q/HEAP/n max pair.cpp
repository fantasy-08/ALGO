vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<long long, vector<long long>, std::greater<int>> minHeap;
    sort(A.begin(), A.end(), std::greater<int>());
    sort(B.begin(), B.end(), std::greater<int>());
    long long summ;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j  < B.size(); j++) {
            summ = A[i] + B[j];
            if (i == 0) minHeap.push(summ);
            else if (minHeap.top() < summ){
                minHeap.pop();
                minHeap.push(summ);
            }
            else break;
        }
    }
    vector<int> output(minHeap.size(), 0);
    int i = minHeap.size()-1;
    while (!minHeap.empty()) {
        output[i--] = minHeap.top();
        minHeap.pop();
    }
    return output;
}
