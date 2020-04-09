bool asc(int a, int b) { //for minheap
    return a < b;
}

bool desc(int a, int b) {
    return a > b;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class Heap {
public:
    Heap(bool (*func)(int, int)) {
        cmp = func;
    }
    
    void insert(int num) {
        nums.push_back(num);
        //compare with parent; and decide if swap or done; depends if minheap or maxheap
        //explanations done based on minheap, asc
        int i = nums.size() - 1;
        int parent = (i + 1) / 2 - 1;
        while(i != 0 && cmp(nums.at(i), nums.at(parent))) { //cmp(child, parent); if child < parent, swap
            swap(nums.at(i), nums.at(parent));
            i = parent;
            parent = (i + 1) / 2 - 1;
        }
    }
    
    void remove_top() {
        nums.at(0) = nums.at(nums.size() - 1);
        nums.resize(nums.size() - 1);
        //move nums.at(0) down heap as needed; depends on if minheap or maxheap
        //comments based on having minheap
        int i = 0;
        while(1) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            if(rightChild < nums.size() && cmp(nums.at(rightChild), nums.at(leftChild))) {
                if(cmp(nums.at(rightChild), nums.at(i))) {
                    swap(nums.at(i), nums.at(rightChild));
                    i = rightChild;
                }
                else {
                    return;
                }
            }
            else if(leftChild < nums.size() && cmp(nums.at(leftChild), nums.at(i))) {
                swap(nums.at(i), nums.at(leftChild));
                i = leftChild;
            }
            else {
                return;
            }
        }
    }
    
    int get_top() {
        return nums.at(0);
    }
    
    int get_size() {
        return nums.size();
    }
private:
    vector<int> nums;
    bool (*cmp)(int, int);
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        minHeap = new Heap(asc);
        maxHeap = new Heap(desc);
    }
    
    void addNum(int num) {
        // minHeap->insert(num);
        if(minHeap->get_size() == maxHeap->get_size()) {
            if(maxHeap->get_size() == 0) {
                maxHeap->insert(num);
            }
            else {
                if(num > minHeap->get_top()) {
                    maxHeap->insert(minHeap->get_top());
                    minHeap->remove_top();
                    minHeap->insert(num);
                }
                else {
                    maxHeap->insert(num);
                }
            }
        }
        else { //heaps are different sizes; maxheap larger by 1 element
            if(num < maxHeap->get_top()) {
                minHeap->insert(maxHeap->get_top());
                maxHeap->remove_top();
                maxHeap->insert(num);
            }
            else {
                minHeap->insert(num);
            }
        }
    }
    
    double findMedian() {
        // if(minHeap->get_size() >= 6) {
        //     minHeap->remove_top();
        // }
        // return minHeap->get_top();
        if(minHeap->get_size() != maxHeap->get_size()) {
            return maxHeap->get_top();
        }
        return (maxHeap->get_top() + minHeap->get_top()) / 2.0;
    }
private:
    Heap* minHeap; //stores: upper half of stream; largest numbers
    Heap* maxHeap; //stores: lower half of stream; smallest numbers
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */