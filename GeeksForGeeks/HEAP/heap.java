/*
 * Binary Heap : Java implementation
 * Insert(): Add element to last and bubble it up. O(logn)
 * DeleteKey(): DecreaseKey to INT_MIN and extractMin.
 * DecreaseKey: Replace element to target and bubble it up.
 * extractMin(): replace first element with last and heapify.
 * */



class GFG{
	 int maxsize;
	 int size;
	 int[] array;
	 int last;

	 int parent(int i ){return (i-1)/2;}
	 int left(int i){return  2*i+1;}
	 int right(int i){return 2*i+2;}


	GFG(int _maxsize){
		maxsize = _maxsize;
		last=0;
		array = new int[maxsize];
	 }

	void swap(int i, int j){
		System.out.println("i,j: "+ i + " "+j);
		int temp = array[i];
		array[i]=array[j];
		array[j]=temp;
	}

	void insert(int key){
		if (last == maxsize){
			System.out.println("Cant add shit. binaryHeap is full.");
			return;
		}
		array[last] = key;
		int i = last;
		last++;
		
		while (parent(i)>=0 && array[parent(i)] > array[i]){
			swap(array[parent(i)], array[i]);
			i  = parent(i);
		}
	}

	void decreaseKey(int i, int target){
		array[i] = target;
		while (parent(i) >=0 && array[parent(i)] > array[i]){
			swap(array[parent(i)], array[i]);
			i = parent(i);
		}
	}
	
	 int extractMin(){
		if  (last ==0){
			System.out.println("minHeap is empty");
			return Integer.MIN_VALUE;
		}
		int minheap = array[0];
		array[0] = array[last-1];
		last--;
		heapify(0);
		return minheap;
	}

 	void heapify(int i){
	
	        System.out.println("last is :" + last);	
		int nexthop=i;
		int smallest = array[i];
		while(true){
			if (left(i)<last && smallest >  array[left(i)]){
				nexthop = left(i);
				smallest = array[left(i)];
			}
			if (right(i) < last && smallest  > array[right(i)]){
				nexthop= right(i);
				smallest = array[right(i)];
			}
			if (nexthop == i){
				return;
			}
			System.out.println("nexthop,i,length  is: " + nexthop + " " + i + " " + array.length);
			swap(i, nexthop);
			i = nexthop;
		}
	}

        void deleteKey(int i){
		decreaseKey(i, Integer.MIN_VALUE);
		extractMin();
	}

	public static void main(String args[]){
		GFG heap = new GFG(20);
		heap.insert(10);
	 	heap.insert(20);
		heap.insert(30);

		System.out.println("array.0: " + heap.array[0]);
		for(int i=0;i<10;i++)
		System.out.println("min element is: " + heap.extractMin());

	}
}
