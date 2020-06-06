
/*
 * Java ArrayList, Vector, array, List:

    1. ArrayList vs Vector:

    1.1 Synchronization: Vector is thread synchronized. Structural
      modification in a vector is thread synchronized. At a time, only one
    thread can structurally modify the vector. In ArrayList, multiple
    threads can work simultaneously and may lead to un-predictable behavior
    unless structural modification is not synchonized. At a time, only one
    thread should have access to code that adds/remove element. Simpler
    modification should also be synchronized.

    1.2 Speed: ArrayList is faster due to absence of locks. But this should
      matter only  in multi-threaded code. Single thread should perform the
    same either way.

    1.3 Growth: ArrayList grows by 50%, Vector grows by 100%.

    1.4 Traversal: Vector can use Enumerations/Iterators for traversal.
     ArrayList can  use only Iterators for traversal.

    2 Which to use?

    2.1. Vector is thread-safe, ArrayList is not. If code is multi-threaded,
       using vector makes sense as it itself handles synchronization. For
     single threaded code, ArrayList is okay. Single threaded code can use
    vector as well, but doesnt make sense, as there will be overhead
    (significant or  not?) for locks.

    2.2. If  we know data growth rate, Vector is good choice as we can mention
       the growth rate in constructor.

    2.3. If you dont know which one to use, use ArrayList.

    3  array int[] a, is fixed sized array.

    4. ArrayList vs List:

      List is an interface implemented by ArrayList.

      4.1 List<obj> myList = new ArrayList<> ();
          myList can only call list interface methods implemented by  ArrayList class.

      4.2 ArrayList <objc> myList = new ArrayList<>();
          myList can call List interface methods as well as ArrayList class
          methods.

    5. Why would someone use List<obj> myList then?
    Ans:

    6. List interface is implemented by  ArrayList, LinkedList, Vector and
       Stack.

 *
 *
 */

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
