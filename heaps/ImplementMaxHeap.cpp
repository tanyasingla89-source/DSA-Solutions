class Solution{
    public:
    vector<int>heap;
    int size;
        void initializeHeap(){
            heap.clear();
            size=-1;
        }

        void insert(int key){
            size=size+1;
            heap.push_back(key);
            int index=size;
            while(index>0)
            {
                int parent=(index-1)/2;
                if(heap[parent]<heap[index])
                {
                    swap(heap[parent],heap[index]);
                    index=parent;
                }
                else
                {
                    return;
                }
            }
        }

        void changeKey(int index, int new_val){
            void changeKey(int index, int new_val){
    heap[index] = new_val;
    
    // if new value is greater, heapify up
    while(index > 0){
        int parent = (index-1)/2;
        if(heap[parent] < heap[index]){
            swap(heap[parent], heap[index]);
            index = parent;
        }
        else return;
    }
    
    // if new value is smaller, heapify down
    int i = index;
    while(i <= size){
        int largest = i;
        int lind = 2*i+1;
        int rind = 2*i+2;
        if(lind <= size && heap[largest] <= heap[lind])
            largest = lind;
        if(rind <= size && heap[largest] <= heap[rind])
            largest = rind;
        if(largest != i){
            swap(heap[i], heap[largest]);
            i = largest;
        }
        else return;
    }
}
        }

        void extractMax(){
            swap(heap[size],heap[0]);
            size--;
            int i=0;
            while(i<=size)
            {
                int largest=i;
                int lind=2*i+1;
                int rind=2*i+2;
                if(lind<=size && heap[largest]<=heap[lind])
                {
                    largest=lind;
                }
                if(rind<=size && heap[largest]<=heap[rind])
                {
                    largest=rind;
                }
                if(largest!=i)
                {
                    swap(heap[i],heap[largest]);
            i=largest;
                }
                else 
                {
                    return;
                }
            }
        }

        bool isEmpty(){
            if(size>-1) return false;
            else return true;
        }

        int getMax(){
            return heap[0];
        }

        int heapSize(){
            return size;
        }
};
