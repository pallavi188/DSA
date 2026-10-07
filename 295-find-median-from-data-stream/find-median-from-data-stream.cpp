class MedianFinder {
public:
    priority_queue<int>l_max_heap;
    priority_queue<int,vector<int>,greater<int>>r_min_heap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(l_max_heap.empty() || num < l_max_heap.top()){
            l_max_heap.push(num);
        }else{
            r_min_heap.push(num);
        }
        //maintain one extra element in the left max heap
        if(r_min_heap.size()>l_max_heap.size()){
            l_max_heap.push(r_min_heap.top());
            r_min_heap.pop();
        }else if(l_max_heap.size() - r_min_heap.size()>1){
            r_min_heap.push(l_max_heap.top());
            l_max_heap.pop();
        }
    }
    
    double findMedian() {
        if(l_max_heap.size() == r_min_heap.size())
            return (double)(l_max_heap.top()+r_min_heap.top())/2;
        else 
            return (double)(l_max_heap.top());    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */